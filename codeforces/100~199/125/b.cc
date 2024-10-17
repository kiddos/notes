#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();

  auto read_tag = [&](int& i) -> pair<string, int> {
    int type = 1;
    assert(s[i] == '<');
    i++;
    if (s[i] == '/') {
      type = 0;
      i++;
    }
    string name;
    while (i < n && s[i] != '>') {
      name.push_back(s[i++]);
    }
    assert(s[i] == '>');
    i++;
    return {name, type};
  };
  int i = 0;
  vector<pair<string, int>> tags;
  while (i < n) {
    pair<string, int> t = read_tag(i);
    tags.push_back(t);
  }
  int indent = 0;
  for (auto& [name, type] : tags) {
    if (type == 0) {
      indent -= 2;
    }

    if (type == 1) {
      cout << string(indent, ' ') << "<" << name << ">\n";
    } else if (type == 0) {
      cout << string(indent, ' ') << "</" << name << ">\n";
    }

    if (type == 1) {
      indent += 2;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

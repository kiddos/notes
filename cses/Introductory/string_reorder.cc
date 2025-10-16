#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  map<char, int> count;
  for (char ch : s) {
    count[ch]++;
  }

  auto possible = [&]() -> bool {
    int max_count = 0;
    int length = 0;
    for (auto [ch, c] : count) {
      max_count = max(max_count, c);
      length += c;
    }
    return max_count <= (length+1) / 2;
  };

  if (!possible()) {
    cout << "-1" << endl;
    return;
  }

  string ans;
  char last = ' ';
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    char add = ' ';
    for (auto& [ch, c] : count) {
      if (c > 0 && ch != last) {
        c--;
        if (possible()) {
          add = ch;
          break;
        }
        c++;
      }
    }
    ans.push_back(add);
    last = add;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

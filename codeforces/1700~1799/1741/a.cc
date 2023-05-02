#include <bits/stdc++.h>

using namespace std;

void solve() {
  string a, b;
  cin >> a >> b;
  unordered_map<char, int> size = {{'S', -1}, {'M', 0}, {'L', 1}};
  int s1 = size[a.back()];
  int s2 = size[b.back()];
  if (s1 == s2) {
    if (a == b) {
      cout << "=" << endl;
    } else if (a.length() * s1 > b.length() * s2) {
      cout << ">" << endl;
    } else {
      cout << "<" << endl;
    }
  } else if (s1 > s2) {
    cout << ">" << endl;
  } else {
    cout << "<" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}

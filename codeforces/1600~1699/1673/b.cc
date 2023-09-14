#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();

  string chars = s;
  sort(chars.begin(), chars.end());
  chars.erase(unique(chars.begin(), chars.end()), chars.end());

  for (char ch : chars) {
    vector<int> count(26);
    for (int i = 0; i < n; ++i) {
      if (s[i] == ch) {
        fill(count.begin(), count.end(), 0);
      } else {
        int c = s[i] - 'a';
        if (++count[c] >= 2) {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }

  cout << "YES" << endl;
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  vector<int> ab;
  int n = s.length();
  for (int i = 1; i < n; ++i) {
    if (s[i-1] == 'A' && s[i] == 'B') {
      ab.push_back(i);
    }
  }

  for (int i = 1; i < n; ++i) {
    if (s[i-1] == 'B' && s[i] == 'A') {
      auto it = upper_bound(ab.begin(), ab.end(), i-2);
      if (it != ab.begin()) {
        cout << "YES" << endl;
        return;
      }
      it = lower_bound(ab.begin(), ab.end(), i+2);
      if (it != ab.end()) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

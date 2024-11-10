#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;
  string s;
  cin >> s;
  set<int> can_buy, cannot_buy;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      can_buy.insert(i);
    } else {
      cannot_buy.insert(i);
    }
  }

  i64 total = (n + 1) * n / 2;
  for (int i = n-1; i >= 0; --i) {
    if (s[i] == '1') {
      can_buy.erase(i);

      if (!cannot_buy.empty()) {
        cannot_buy.erase(prev(cannot_buy.end()));
        total -= (i+1);
      } else if (!can_buy.empty()) {
        can_buy.erase(can_buy.begin());
        total -= (i+1);
      }
    } else {
      cannot_buy.erase(i);
    }
  }

  cout << total << endl;
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

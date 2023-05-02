#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; ++i) cin >> a[i];
  map<int, int> count;

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      if (!count.empty()) {
        int max_bonus = count.rbegin()->first;
        ans += max_bonus;
        count[max_bonus]--;
        if (count[max_bonus] == 0) {
          count.erase(max_bonus);
        }
      }
    } else {
      count[a[i]]++;
    }
  }
  cout << ans << endl;
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

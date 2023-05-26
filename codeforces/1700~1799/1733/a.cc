#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);

  for (int i = 0; i < n; ++i) cin >> a[i];

  ll ans = 0;
  for (int i = 0; i < k; ++i) {
    vector<int> nums;
    for (int j = i; j < n; j += k) {
      nums.push_back(a[j]);
    }
    ans += *max_element(nums.begin(), nums.end());
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

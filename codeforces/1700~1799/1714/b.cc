#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int ans = 0;
  map<int, int> nums;
  for (int i = n-1; i >= 0; --i) {
    if (nums.count(a[i])) {
      break;
    } else {
      nums[a[i]]++;
      ans = max(ans, (int)nums.size());
    }
  }
  cout << n-ans << endl;
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

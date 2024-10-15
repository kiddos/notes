#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> ans(n);
  for (int i = 1; i < n; ++i) {
    int sum = a[i] + ans[i] + a[i-1] + ans[i-1];
    if (sum < k) {
      ans[i] += k - sum;
    }
  }
  int total = accumulate(ans.begin(), ans.end(), 0);
  cout << total << endl;
  for (int i = 0; i < n; ++i) {
    cout << ans[i] + a[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

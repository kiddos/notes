#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int k = 0, q = 0;
  cin >> k >> q;
  vector<int> a(k);
  for (int i = 0; i < k; ++i) cin >> a[i];
  sort(a.begin(), a.end());

  auto get_remove_count = [&](int n) -> int {
    int l = 0, r = k-1;
    int ans = 0;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (a[mid] <= n) {
        ans = mid + 1;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    return ans;
  };

  for (int i = 0; i < q; ++i) {
    int n = 0;
    cin >> n;

    while (true) {
      int r = get_remove_count(n);
      if (r == 0) {
        break;
      }
      n -= r;
    }
    cout << n << " ";
  }
  cout << endl;
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

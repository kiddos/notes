#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> c(n+1);
  for (int i = 0; i < n; ++i) {
    c[a[i]]++;
  }
  vector<int> p = c;
  for (int i = 1; i <= n; ++i) {
    p[i] += p[i-1];
  }

  auto find_median = [&](int x) -> int {
    int l = 0, r = x-1;
    int ans = r;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      int total = p[mid];
      for (int y = x; y <= n; y += x) {
        total += p[min(y + mid, n)] - p[y - 1];
      }

      if ((n % 2 == 0 && total >= (n + 2) / 2) || (n % 2 == 1 && total >= (n + 1) / 2)) {
        r = mid - 1;
        ans = mid;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  };

  vector<int> ans(n+1);
  for (int x = 1; x <= n; ++x) {
    ans[x] = find_median(x);
  }

  for (int i = 0; i < q; ++i) {
    int x = 0;
    cin >> x;
    cout << ans[x] << " ";
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

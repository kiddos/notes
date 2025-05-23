#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b = a;
  for (int i = 0; i < n; ++i) {
    b.push_back(a[i]);
  }

  int m = b.size();
  int L = ceil(log2(m)) + 1;
  vector<vector<int>> binary_lift(L, vector<int>(m));
  binary_lift[0] = b;
  for (int l = 1; l < L; ++l) {
    int p = 1<<(l-1);
    for (int i = 0; i+p < m; ++i) {
      binary_lift[l][i] = gcd(binary_lift[l-1][i], binary_lift[l-1][i+p]);
    }
  }

  auto range_gcd = [&](int l, int r) -> int {
    int len = r-l+1;
    int p = 0;
    while ((1<<(p+1)) <= len) {
      p++;
    }
    return gcd(binary_lift[p][l], binary_lift[p][r-(1<<p)+1]);
  };

  int all_gcd = a[0];
  for (int i = 0; i < n; ++i) {
    all_gcd = gcd(all_gcd, a[i]);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int l = 0, r = n-1;
    int len = r;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      int g = range_gcd(i, i + mid);
      if (g == all_gcd) {
        len = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    ans = max(ans, len);
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

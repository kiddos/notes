#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  i64 no_reverse = 0;
  for (int i = 0; i < n; ++i) {
    no_reverse += a[i] * b[i];
  }
  i64 ans = no_reverse;

  vector<i64> prefix(n);
  for (int i = 0; i < n; ++i) {
    prefix[i] = a[i] * b[i];
    if (i > 0) prefix[i] += prefix[i-1];
  }
  vector<i64> suffix(n);
  for (int i = n-1; i >= 0; --i) {
    suffix[i] = a[i] * b[i];
    if (i+1 < n) suffix[i] += suffix[i+1];
  }

  vector<vector<i64>> dp2(n, vector<i64>(n));
  for (int i = 0; i < n; ++i) {
    // center at i
    i64 sum = a[i] * b[i];
    int l = i-1, r = i+1;
    while (l >= 0 && r < n) {
      sum += a[l] * b[r] + a[r] * b[l];
      dp2[l][r] = sum;
      l--;
      r++;
    }

    if (i > 0) {
      // center at (i, i+1)
      l = i-1, r = i;
      sum = 0;
      while (l >= 0 && r < n) {
        sum += a[l] * b[r] + a[r] * b[l];
        dp2[l][r] = sum;
        l--;
        r++;
      }
    }
  }

  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ++r) {
      i64 p1 = l > 0 ? prefix[l-1] : 0;
      i64 p2 = dp2[l][r];
      i64 p3 = r+1 < n ? suffix[r+1] : 0;
      i64 total = p1 + p2 + p3;
      ans = max(ans, total);
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

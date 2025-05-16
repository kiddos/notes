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

  int L = ceil(log2(n))+1;
  vector<vector<int>> binary_lift(L+1, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    binary_lift[0][i] = a[i];
  }
  for (int l = 1; l <= L; ++l) {
    int p = 1<<l;
    for (int i = p-1; i < n; ++i) {
      binary_lift[l][i] = gcd(binary_lift[l-1][i], binary_lift[l-1][i - (1<<(l-1))]);
    }
  }

  auto range_gcd = [&](int l, int r) {
    int len = r-l+1;
    int level = 0;
    while ((1<<(level+1)) <= len) {
      level++;
    }
    int p = 1<<level;
    int g1 = binary_lift[level][l + p - 1];
    int g2 = binary_lift[level][r];
    return gcd(g1, g2);
  };

  vector<int> ans(n);
  int j = 0;
  for (int i = 0; i < n; ++i) {
    while (j < i && range_gcd(j, i) < (i-j+1)) {
      j++;
    }
    if (range_gcd(j, i) == (i-j+1)) {
      ans[i] = 1;
      j = i + 1;
    }
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << ans[i] << " ";
  // }
  // cout << endl;

  for (int i = 1; i < n; ++i) {
    ans[i] += ans[i-1];
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

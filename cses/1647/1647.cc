#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) cin >> nums[i];
  int l = ceil(log2(n))+1;
  vector<vector<int>> sparse_table(l, vector<int>(n));
  sparse_table[0] = nums;
  for (int i = 1; i < l; ++i) {
    int offset = pow(2, i-1);
    for (int j = 0; j <= n-offset; ++j) {
      sparse_table[i][j] = min(sparse_table[i-1][j], sparse_table[i-1][j+offset]);
    }
  }

  for (int i = 0; i < q; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    int size = v - u + 1;
    int l = log2(size);
    int ans = min(sparse_table[l][u-1], sparse_table[l][v-pow(2, l)]);
    cout << ans << endl;
  }
  return 0;
}

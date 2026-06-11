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
  i64 min_val = *min_element(a.begin(), a.end());
  vector<int> min_indices;
  for (int i = 0; i < n; ++i) {
    if (a[i] == min_val) {
      min_indices.push_back(i);
    }
  }
  i64 ans = min_val * n + (n-min_indices.back()-1) + min_indices[0];
  int size = min_indices.size();
  for (int i = 1; i < size; ++i) {
    ans = max(ans, min_val * n + min_indices[i] - min_indices[i-1] - 1);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  vector<int> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + h[i]);
  }
  int min_sum = numeric_limits<int>::max();
  int ans = 0;
  for (int j = 0; j <= n-k; ++j) {
    int sum = p[j+k] - p[j];
    if (sum < min_sum) {
      ans = j+1;
      min_sum = sum;
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

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
  int max_height = 0, min_height = numeric_limits<int>::max();
  int swap1 = 0, swap2 = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > max_height) {
      max_height = a[i];
      swap1 = i;
    }
  }
  int max_val = a[swap1];
  for (int i = swap1 - 1; i >= 0; --i) {
    a[i+1] = a[i];
  }
  a[0] = max_val;

  for (int i = n-1; i >= 0; --i) {
    if (a[i] < min_height) {
      min_height = a[i];
      swap2 = n-i-1;
    }
  }
  int ans = swap1 + swap2;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

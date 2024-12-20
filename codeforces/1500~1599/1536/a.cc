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
  int min_val = *min_element(a.begin(), a.end());
  if (min_val < 0) {
    cout << "NO" << endl;
    return;
  }

  int max_val = *max_element(a.begin(), a.end());
  cout << "YES" << endl;
  cout << max_val + 1 << endl;
  for (int i = 0; i <= max_val; ++i) {
    cout << i << " ";
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

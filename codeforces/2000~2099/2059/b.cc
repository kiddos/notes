#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (n == k) {
    for (int i = 1, t = 1; i < n; i += 2, ++t) {
      if (a[i] != t) {
        cout << t << endl;
        return;
      }
    }
    cout << k/2+1 << endl;
  } else {
    int max_one_index = n-k+1;
    for (int i = 1; i <= max_one_index; ++i) {
      if (a[i] != 1) {
        cout << "1" << endl;
        return;
      }
    }
    cout << "2" << endl;
  }
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

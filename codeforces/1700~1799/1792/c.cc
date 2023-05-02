#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) cin >> arr[i];

  vector<int> index(n+1);
  for (int i = 0; i < n; ++i) index[arr[i]] = i;

  int max_ops = n / 2 + (n % 2);
  int a = max_ops;
  int b = a + (n % 2 == 0 ? 1 : 0);
  int left = index[a], right = index[b];
  for (int i = max_ops; i > 0; --i, --a, ++b) {
    int i1 = index[a];
    int i2 = index[b];
    if (i1 > i2) {
      cout << i << endl;
      return;
    }
    if (i1 > left || i2 < right) {
      cout << i << endl;
      return;
    }

    left = i1;
    right = i2;
  }

  cout << "0" << endl;
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

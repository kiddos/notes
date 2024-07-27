#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  int size = n * m;

  vector<int> a(size);
  for (int i = 0; i < size; ++i) {
    cin >> a[i];
  }

  if (size == 1) {
    cout << "-1" << endl;
    return;
  }

  vector<int> b(size);
  for (int i = 0; i < size; ++i) {
    b[i] = a[(i+1) % size];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << b[i * m + j] << " ";
    }
    cout << endl;
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

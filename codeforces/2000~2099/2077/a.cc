#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int m = 2 * n;
  vector<i64> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  set<i64> s(b.begin(), b.end());
  int size = m+1;
  vector<i64> a(size);
  int k = m-1;
  a[0] = b[k--];
  for (int i = 2; i < size; i += 2) {
    a[i] = b[k--];
  }
  for (int i = 3; i < size; i += 2) {
    a[i] = b[k--];
  }
  a[1] = a[0];
  for (int i = 2; i < size; ++i) {
    if (i % 2 == 0) {
      a[1] += a[i];
    } else {
      a[1] -= a[i];
    }
  }

  for (int i = 0; i < size; ++i) {
    cout << a[i] << " ";
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

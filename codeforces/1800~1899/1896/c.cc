#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  vector<pair<int,int>> A;
  for (int i = 0; i < n; ++i) {
    A.emplace_back(a[i], i);
  }
  sort(A.rbegin(), A.rend());
  sort(b.rbegin(), b.rend());

  vector<int> new_b(n);
  int j = 0;
  for (int i = x; i < n; ++i) {
    new_b[A[i].second] = b[j++];
  }
  for (int i = 0; i < x; ++i) {
    new_b[A[i].second] = b[j++];
  }

  int X = 0;
  for (int i = 0; i < n; ++i) {
    X += a[i] > new_b[i];
  }

  if (X == x) {
    cout << "YES" << endl;
    for (int i = 0; i < n ; ++i) {
      cout << new_b[i] << " ";
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
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

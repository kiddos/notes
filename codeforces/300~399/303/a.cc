#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  if (n % 2 == 0) {
    cout << "-1" << endl;
    return;
  }

  vector<int> a(n);
  iota(a.begin(), a.end(), 0);
  vector<int> b(n);
  iota(b.begin(), b.end(), 1);
  b.back() = 0;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    c[i] = (a[i] + b[i]) % n;
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    cout << b[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    cout << c[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

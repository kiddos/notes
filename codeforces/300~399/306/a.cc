#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  int base = n / m;
  int left = n - base * m;
  vector<int> a(m, base);
  for (int i = m-1; i >= 0 && left > 0; --i) {
    a[i]++;
    left--;
  }
  for (int i = 0; i < m; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

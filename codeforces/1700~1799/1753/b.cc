#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> c(x+1);
  for (int i = 0; i < n; ++i) {
    c[a[i]]++;
  }
  for (int i = 1; i < x; ++i) {
    while (c[i] >= (i+1)) {
      c[i] -= (i+1);
      c[i+1]++;
    }
  }
  for (int i = 1; i < x; ++i) {
    if (c[i] > 0) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

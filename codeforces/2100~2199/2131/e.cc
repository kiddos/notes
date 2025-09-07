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
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  if (a.back() != b.back()) {
    cout << "NO" << endl;
    return;
  }
  vector<int> c = a;

  for (int i = n-2; i >= 0; --i) {
    if (a[i] == b[i]) {
      continue;
    }
    int a1 = a[i] ^ a[i+1];
    int a2 = a[i] ^ c[i+1];
    if (a1 != b[i] && a2 != b[i]) {
      cout << "NO" << endl;
      return;
    }
    a[i] = b[i];
  }

  cout << "YES" << endl;
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

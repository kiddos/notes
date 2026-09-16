#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> f(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> f[i];
  }

  for (int i = 1; i <= n; ++i) {
    int A = i;
    int B = f[A];
    int C = f[B];
    if (f[C] == A) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

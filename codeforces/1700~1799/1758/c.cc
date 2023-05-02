#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  int x = 0;
  cin >> n >> x;

  if (n % x != 0) {
    cout << "-1" << endl;
    return;
  }

  vector<int> a(n+1);
  iota(a.begin(), a.end(), 0);
  while (x < n) {
    for (int i = x * 2; i <= n; i += x) {
      if (n % i == 0) {
        a[x] = i;
        break;
      }
    }
  }

  for (int i = 1; i <= n; ++i) cout << a[i] << " ";
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

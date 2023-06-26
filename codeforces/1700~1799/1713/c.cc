#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  vector<bool> used(n);
  for (int i = n-1; i >= 0; --i) {
    int d = 1;
    while (d*d-i < n) {
      if (d*d-i >= 0 && !used[d*d-i]) {
        a[i] = d*d -i;
      }
      d++;
    }
    used[a[i]] = true;
  }

  for (int i = 0; i < n; ++i) cout << a[i] << " ";
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

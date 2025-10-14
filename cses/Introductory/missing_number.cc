#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<bool> found(n+1);
  for (int i = 0; i < n-1; ++i) {
    int x = 0;
    cin >> x;
    found[x] = true;
  }
  for (int x = 1; x <= n; ++x) {
    if (!found[x]) {
      cout << x << endl;
      return;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

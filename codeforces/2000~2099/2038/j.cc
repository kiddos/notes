#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  i64 current = 0;
  for (int i = 0; i < n; ++i) {
    char e = '\0';
    cin >> e;
    if (e == 'P') {
      int p = 0;
      cin >> p;

      current += p;
    } else if (e == 'B') {
      int b = 0;
      cin >> b;

      if (b > current) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      current = max(current - b, 0LL);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

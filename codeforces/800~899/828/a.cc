#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, a = 0, b = 0;
  cin >> n >> a >> b;
  int c = 0;
  vector<int> t(n);
  for (int i = 0; i < n;++i) {
    cin >> t[i];
  }

  int deny = 0;
  for (int i = 0; i < n; ++i) {
    if (t[i] == 1) {
      if (a > 0) {
        a--;
      } else if (b > 0) {
        b--;
        c++;
      } else if (c > 0) {
        c--;
      } else {
        deny++;
      }
    } else if (t[i] == 2) {
      if (b > 0) {
        b--;
      } else {
        deny += 2;
      }
    }
  }
  cout << deny << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

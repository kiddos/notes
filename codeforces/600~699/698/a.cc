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

  int ans = 0;
  int last = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      ans++;
      last = 0;
    } else if (a[i] == 1)  {
      if (last == 1) {
        ans++;
        last = 0;
      } else {
        last = a[i];
      }
    } else if (a[i] == 2) {
      if (last == 2) {
        ans++;
        last = 0;
      } else {
        last = a[i];
      }
    } else if (a[i] == 3) {
      if (last == 0 || last == 3) {
        last = a[i];
      } else if (last == 1) {
        last = 2;
      } else if (last == 2) {
        last = 1;
      }
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

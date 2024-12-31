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

  int non_zero = 0;
  int i = 0;
  while (i < n) {
    if (a[i] == 0) {
      i++;
    } else {
      int j = i;
      while (j+1 < n && a[j+1] != 0) {
        j++;
      }
      non_zero++;
      i = j+1;
    }
  }


  int ans = min(non_zero, 2);
  cout << ans << endl;
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

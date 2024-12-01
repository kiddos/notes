#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<int> ans(n);
  if (n % 2 == 0) {
    int k = 1;
    for (int i = 0; i < n; i += 2) {
      ans[i] = ans[i+1] = k++;
    }
  } else {
    if (n >= 27) {
      ans[0] = ans[9] = ans[25] = 1;
      ans[26] = ans[10] = 2;
      int k = 3;
      for (int i = 0; i < n; ++i) {
        if (ans[i] == 0) {
          ans[i] = ans[i+1] = k;
          k++;
        }
      }
    } else {
      cout << "-1" << endl;
      return;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
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

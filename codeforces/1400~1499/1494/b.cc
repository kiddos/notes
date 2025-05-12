#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, U = 0, R = 0, D = 0, L = 0;
  cin >> n >> U >> R >> D >> L;
  vector<int> a = {U, D};
  function<bool(int,int,int)> brute = [&](int i, int l, int r) -> bool {
    if (i == 2) {
      return l >= 0 && l <= n-2 && r >= 0 && r <= n-2;
    }
    bool ans = false;
    if (a[i] == n) {
      ans = brute(i+1, l-1, r-1);
    } else if (a[i] >= 2) {
      ans = ans || brute(i+1, l-1, r-1);
      ans = ans || brute(i+1, l-1, r);
      ans = ans || brute(i+1, l, r-1);
      if (a[i] <= n-2) {
        ans = ans || brute(i+1, l, r);
      }
    } else if (a[i] == 1) {
      ans = ans || brute(i+1, l-1, r);
      ans = ans || brute(i+1, l, r-1);
      if (a[i] <= n-2) {
        ans = ans || brute(i+1, l, r);
      }
    } else {
      ans = brute(i+1, l, r);
    }
    return ans;
  };

  bool ans = brute(0, L, R);
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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

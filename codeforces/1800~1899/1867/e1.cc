#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int i) {
  cout << "? " << i << endl;
  int result = 0;
  cin >> result;
  return result;
}

void answer(int ans) {
  cout << "! " << ans << endl;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  int m = n / k;
  int p = 1;
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    int result = query(p);
    ans ^= result;
    if (i < m-1) {
      p += k;
    } else {
      p++;
    }
  }
  while (p + k - 1 <= n) {
    int result = query(p);
    ans ^= result;
    p++;
  }
  answer(ans);
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

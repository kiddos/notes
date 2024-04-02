#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  if (n % 2 == 1) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  string ans;
  for (int i = 0; i < n / 2; ++i) {
    if (i % 2 == 0) {
      ans += "AA";
    } else{
      ans += "BB";
    }
  }
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

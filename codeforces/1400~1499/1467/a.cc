#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  if (n == 1) {
    cout << "9" << endl;
  } else if (n == 2) {
    cout << "98" << endl;
  } else {
    string ans = "989";
    int d = 0;
    while ((int)ans.length() < n) {
      ans.push_back(d + '0');
      d = (d+1) % 10;
    }
    cout << ans << endl;
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

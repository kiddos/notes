#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  int flag = 0;
  int l = 1, r = n;
  string ans;
  while (l <= r) {
    if (flag) {
      if (p[l] > p[r]) {
        ans.push_back('L');
        l++;
      } else {
        ans.push_back('R');
        r--;
      }
    } else {
      if (p[l] < p[r]) {
        ans.push_back('L');
        l++;
      } else {
        ans.push_back('R');
        r--;
      }
    }
    flag ^= 1;
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

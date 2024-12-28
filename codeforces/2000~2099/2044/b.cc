#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string a;
  cin >> a;
  int n = a.length();
  string ans;
  for (int i = n-1; i >= 0; --i) {
    if (a[i] == 'w') {
      ans.push_back('w');
    } else if (a[i] == 'p') {
      ans.push_back('q');
    } else if (a[i] == 'q') {
      ans.push_back('p');
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

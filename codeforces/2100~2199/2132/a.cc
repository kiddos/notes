#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string a;
  cin >> a;

  int m = 0;
  cin >> m;
  string b;
  cin >> b;
  string c;
  cin >> c;

  deque<char> d(a.begin(), a.end());
  for (int i = 0; i < m; ++i) {
    if (c[i] == 'D') {
      d.push_back(b[i]);
    } else if (c[i] == 'V') {
      d.push_front(b[i]);
    }
  }
  string ans(d.begin(), d.end());
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  if (k % 2 == 0) {
    sort(s.begin(), s.end());
  } else {
    string e, o;
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        e.push_back(s[i]);
      } else {
        o.push_back(s[i]);
      }
    }
    sort(e.begin(), e.end());
    sort(o.begin(), o.end());
    for (int i = 0, j = 0, k = 0; k < n; ++k) {
      if (k % 2 == 0) {
        s[k] = e[i++];
      } else {
        s[k] = o[j++];
      }
    }
  }
  cout << s << endl;
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

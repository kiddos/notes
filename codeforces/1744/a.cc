#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  string s;
  cin >> s;

  unordered_map<int, char> mapping;
  for (int i = 0; i < n; ++i) {
    if (!mapping.count(a[i])) {
      mapping[a[i]] = s[i];
    } else {
      if (mapping[a[i]] != s[i]) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
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

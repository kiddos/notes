#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> b = {a.back()};
  for (int i = n-2; i >= 0; --i) {
    if (a[i] > b.back()) {
      string s = to_string(a[i]);
      for (int i = s.length()-1; i >= 0; --i) {
        b.push_back(s[i] - '0');
      }
    } else {
      b.push_back(a[i]);
    }
  }
  reverse(b.begin(), b.end());

  for (int i = 1; i < (int)b.size(); ++i) {
    if (b[i] < b[i-1]) {
      cout << "NO" << endl;
      return;
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

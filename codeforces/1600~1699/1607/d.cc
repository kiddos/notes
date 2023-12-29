#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  string s;
  cin >> s;

  vector<int> blue, red;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') {
      red.push_back(a[i]);
    } else if (s[i] == 'B') {
      blue.push_back(a[i]);
    }
  }
  int i = 1;
  sort(blue.begin(), blue.end());
  sort(red.begin(), red.end());
  for (int b : blue) {
    if (b < i) {
      cout << "NO" << endl;
      return;
    }
    i++;
  }
  for (int r : red) {
    if (r > i) {
      cout << "NO" << endl;
      return;
    }
    i++;
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

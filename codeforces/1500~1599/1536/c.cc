#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  map<pair<int,int>, int> prefix;
  pair<int,int> current = {0, 0};
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'D') {
      current.first++;
    } else if (s[i] == 'K') {
      current.second++;
    }
    int g = gcd(current.first, current.second);
    pair<int,int> key = {current.first / g, current.second / g};
    prefix[key]++;
    ans[i] = prefix[key];
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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

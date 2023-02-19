#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& a, int c) {
  int n = a.size();
  vector<int> required_coins;
  for (int i = 0; i < n; ++i) {
    required_coins.push_back(i+1 + a[i]);
  }
  sort(required_coins.begin(), required_coins.end());

  int ans = 0;
  for (int i = 0; i < n && c > 0; ++i) {
    if  (c - required_coins[i] < 0) {
      break;
    }
    c -= required_coins[i];
    ans++;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, c = 0;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    solve(a, c);
  }
  return 0;
}

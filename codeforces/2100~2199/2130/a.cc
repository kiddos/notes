#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> S(n);
  for (int i = 0; i < n; ++i) {
    cin >> S[i];
  }
  int max_val = *max_element(S.begin(), S.end());
  vector<int> count(max_val+1);
  for (int i = 0; i < n; ++i) {
    count[S[i]]++;
  }
  int ans = 0;
  for (int x = 1; x <= max_val; ++x) {
    ans += x * count[x];
  }
  ans += count[0];
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

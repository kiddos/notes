#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& a) {
  unordered_map<int, int> count;
  for (int aa : a) count[abs(aa)]++;
  int ans = 0;
  for (auto& [value, c] : count) {
    ans += value == 0 ? 1 : min(c, 2);
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = solve(a);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}

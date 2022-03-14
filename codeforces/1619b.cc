#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
  unordered_set<int> s;
  for (int i = 1; i*i <= n; ++i) {
    s.insert(i*i);
  }
  for (int i = 1; i*i*i <= n; ++i) {
    s.insert(i*i*i);
  }
  return s.size();
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    int ans = solve(n);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}

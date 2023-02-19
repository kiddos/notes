#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
  return (1 << n) -1;
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

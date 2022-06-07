#include <bits/stdc++.h>

using namespace std;

int solve(string num) {
  if ((num.back()-'0') % 2 == 0) return 0;
  if ((num[0] - '0') % 2 == 0) return 1;
  for (int i = 1; i < num.length()-1; ++i) {
    if ((num[i] - '0') % 2 == 0) return 2;
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    string num;
    cin >> num;
    int ans = solve(num);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}

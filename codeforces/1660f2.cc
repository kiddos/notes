#include <bits/stdc++.h>

using namespace std;

int solve(string s) {
  int n = s.length();
  int balance = 0;
  vector<int> count(3);
  count[balance]++;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '-') {
      balance--;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    string s;
    cin >> n >> s;
    int ans = solve(s);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}

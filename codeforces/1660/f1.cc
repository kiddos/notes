#include <bits/stdc++.h>

using namespace std;

int solve(string s) {
  int n = s.length();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int plus = 0, minus = 0;
    int consecutive = 0;
    int ops = 0;
    for (int j = i; j < n; ++j) {
      if (s[j] == '+') {
        plus++;
        ops += consecutive / 2;
      } else if (s[j] == '-') {
        minus++;
        consecutive++;
      }

      if (minus == plus) {
        ans++;
      } else if (minus > plus && (minus - plus) % 3 == 0) {
        int require = (minus - plus) / 3;
        int has = ops + consecutive / 2;
        if (has >= require) {
          ans++;
        }
      }
    }
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
    string s;
    cin >> n >> s;
    int ans = solve(s);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}

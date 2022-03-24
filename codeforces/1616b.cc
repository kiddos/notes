#include <bits/stdc++.h>

using namespace std;

string solve(string s) {
  string ans;
  bool has_decreased = false;
  for (char ch : s) {
    if (ans.empty() || ans.back() > ch || (has_decreased && ans.back() >= ch)) {
      if (ans.back() > ch) {
        has_decreased = true;
      }
      ans.push_back(ch);
    } else {
      break;
    }
  }
  string mirror = ans;
  reverse(mirror.begin(), mirror.end());
  ans += mirror;
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
    string ans = solve(s);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}

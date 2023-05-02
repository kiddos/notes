#include <bits/stdc++.h>

using namespace std;

string solve(string s) {
  vector<int> count(26);
  for (char ch : s) count[ch-'a']++;
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    if (count[s[i]-'a'] > 1) {
      count[s[i]-'a']--;
    } else {
      return s.substr(i);
    }
  }
  return "";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    string s;
    cin >> s;
    string ans = solve(s);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}

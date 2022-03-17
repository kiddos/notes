#include <bits/stdc++.h>

using namespace std;

string solve(string s, string t) {
  vector<int> count(26);
  for (char ch : s) count[ch - 'a']++;
  string ans;

  if (t == "abc" && count[0] && count[1] && count[2]) {
    ans += string(count[0], 'a');
    ans += string(count[2], 'c');
    ans += string(count[1], 'b');
    for (int i = 3; i < 26; ++i) {
      ans += string(count[i], 'a' + i);
    }
  } else {
    for (int i = 0; i < 26; ++i) {
      ans += string(count[i], 'a' + i);
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
    string s, t;
    cin >> s >> t;
    string ans = solve(s, t);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}

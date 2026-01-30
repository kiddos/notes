#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int i = 0;
  string ans;
  while (i < n) {
    if (s[i] == '.') {
      ans.push_back('0');
      i++;
    } else if (s[i] == '-' && s[i+1] == '.') {
      ans.push_back('1');
      i += 2;
    } else if (s[i] == '-' && s[i+1] == '-') {
      ans.push_back('2');
      i += 2;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

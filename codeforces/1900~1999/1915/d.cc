#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  string type = "vcccv";

  string ans;
  int i = n-1;
  while (i >= 0) {
    int c = s[i]-'a';
    char t = type[c];
    if (t == 'c') {
      ans.push_back(s[i--]);
      ans.push_back(s[i--]);
      ans.push_back(s[i--]);
      ans.push_back('.');
    } else if (t == 'v') {
      ans.push_back(s[i--]);
      ans.push_back(s[i--]);
      ans.push_back('.');
    }
  }
  ans.pop_back();

  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}

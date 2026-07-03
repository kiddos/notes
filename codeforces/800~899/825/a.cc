#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int i = 0;
  string ans;
  while (i < n) {
    int j = i;
    while (j < n && s[j] != '0') {
      j++;
    }
    int len = j-i;
    ans.push_back(len + '0');
    i = j+1;
  }
  if (s.back() == '0') {
    ans += "0";
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

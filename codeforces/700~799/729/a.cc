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
    if (i + 2 < n && s[i] == 'o' && s[i+1] == 'g' && s[i+2] == 'o') {
      int j = i+1;
      while (j+1 < n && s[j] == 'g' && s[j+1] == 'o') {
        j += 2;
      }
      ans += string(3, '*');
      i = j;
    } else {
      ans.push_back(s[i++]);
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

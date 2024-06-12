#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  vector<array<int, 3>> p;
  int b = 0;
  for (int i = 0; i < n; ++i) {
    p.push_back({b, -(i+1), (int)s[i]});
    if (s[i] == '(') {
      b++;
    } else if (s[i] == ')') {
      b--;
    }
  }
  sort(p.begin(), p.end());
  string ans;
  for (int i = 0; i < n; ++i) {
    ans.push_back((char)p[i][2]);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

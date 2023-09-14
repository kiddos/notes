#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];


  i64 ans = 0;
  unordered_map<string, int> count;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      string s2 = s[i];
      for (char ch = 'a'; ch <= 'k'; ++ch) if (ch != s[i][j]) {
        s2[j] = ch;
        if (count.count(s2)) {
          ans += count[s2];
        }
      }
    }
    
    count[s[i]]++;
  }

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

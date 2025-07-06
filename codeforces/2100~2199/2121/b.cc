#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> suffix(26);
  for (int i = 0; i < n; ++i) {
    suffix[s[i] - 'a']++;
  }

  suffix[s[0] - 'a']--;
  vector<int> prefix(26);
  prefix[s[0] - 'a']++;
  for (int i = 1; i < n-1; ++i) {
    int c = s[i]-'a';
    suffix[c]--;
    if (prefix[c] || suffix[c]) {
      cout << "YES" << endl;
      return;
    }
    prefix[c]++;
  }
  cout << "NO" << endl;
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

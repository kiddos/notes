#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  getline(cin, s);
  vector<int> found(26);
  for (char ch : s) {
    if (ch >= 'a' && ch <= 'z') {
      found[ch-'a'] = 1;
    }
  }
  int ans = accumulate(found.begin(), found.end(), 0);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

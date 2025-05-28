#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  multiset<char> digits(s.begin(), s.end());
  int n = s.length();
  string ans;
  for (int i = 0; i < n; ++i) {
    char at_least = (n-i-1) + '0';
    auto it = digits.lower_bound(at_least);
    ans.push_back(*it);
    digits.erase(it);
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

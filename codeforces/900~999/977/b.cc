#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  unordered_map<string, int> count;
  for (int i = 1; i < n; ++i) {
    string t = s.substr(i-1, 2);
    count[t]++;
  }
  string ans;
  int most_count = 0;
  for (auto [t, c] : count) {
    if (c > most_count) {
      most_count = c;
      ans = t;
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

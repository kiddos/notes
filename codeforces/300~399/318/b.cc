#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> metal(n);
  for (int i = 0; i < n; ++i) {
    string sub = s.substr(i, 5);
    if (sub == "metal") {
      metal[i]++;
    }
  }
  for (int i = n-2; i >= 0; --i) {
    metal[i] += metal[i+1];
  }

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    string sub = s.substr(i, 5);
    if (sub == "heavy" && i+5 < n) {
      ans += metal[i+5];
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

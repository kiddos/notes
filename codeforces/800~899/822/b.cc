#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  int best = n + 1;
  vector<int> ans;
  for (int i = 0; i <= m-n; ++i) {
    vector<int> incorrect;
    for (int j = 0; j < n; ++j) {
      if (s[j] != t[i+j]) {
        incorrect.push_back(j + 1);
      }
    }
    if ((int)incorrect.size() < best) {
      ans = incorrect;
      best = incorrect.size();
    }
  }

  cout << ans.size() << endl;
  for (int idx : ans) {
    cout << idx << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

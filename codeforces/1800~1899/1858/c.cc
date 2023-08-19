#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  set<int> s;
  for (int i = 1; i <= n; ++i) {
    s.insert(i);
  }

  vector<int> ans;
  while (!s.empty()) {
    int start = *s.begin();
    s.erase(s.begin());
    ans.push_back(start);
    while (s.count(start * 2)) {
      s.erase(start * 2);
      ans.push_back(start * 2);
      start *= 2;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> w(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
  }
  string s;
  cin >> s;
  int size = n * 2;
  set<array<int,2>> not_occupy;
  set<array<int,2>> occupy;
  for (int i = 1; i <= n; ++i) {
    not_occupy.insert({w[i], i});
  }

  vector<int> ans(size);
  for (int i = 0; i < size; ++i) {
    if (s[i] == '0') {
      auto [wi, idx] = *not_occupy.begin();
      not_occupy.erase(not_occupy.begin());
      occupy.insert({wi, idx});
      ans[i] = idx;
    } else if (s[i] == '1') {
      auto [wi, idx] = *occupy.rbegin();
      occupy.erase(prev(occupy.end()));
      ans[i] = idx;
    }
  }

  for (int i = 0; i < size; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

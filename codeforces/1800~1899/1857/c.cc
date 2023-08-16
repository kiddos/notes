#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int m = (n - 1) * n / 2;
  vector<i64> b(m);
  for (int i = 0; i < m; ++i) cin >> b[i];

  map<i64,int> freq;
  for (i64 val : b) {
    freq[val]++;
  }

  vector<i64> ans;
  for (int x = n-1; x >= 1; --x) {
    auto it = freq.begin();
    ans.push_back(it->first);
    it->second -= x;
    if (it->second == 0) freq.erase(freq.begin());
  }
  ans.push_back(ans.back());

  for (i64 val : ans) cout << val << " ";
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

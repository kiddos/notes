#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> last_seen(n+1, -1);
  for (int i = 0; i < n; ++i) {
    last_seen[a[i]] = i;
  }

  vector<pair<int,int>> p;
  for (int i = 1; i <= n; ++i) {
    p.push_back({last_seen[i], i});
  }
  sort(p.begin(), p.end());
  vector<int> ans;
  for (int i = 0; i < k; ++i) {
    ans.push_back(p[i].second);
  }
  for (int ai : ans) {
    cout << ai << " ";
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

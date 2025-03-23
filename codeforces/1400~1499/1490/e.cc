#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<i64,int>> p;
  for (int i = 0; i < n; ++i) {
    p.emplace_back(a[i], i);
  }
  sort(p.begin(), p.end());
  vector<i64> prefix(n);
  for (int i = 0; i < n; ++i) {
    prefix[i] = p[i].first;
    if (i > 0) prefix[i] += prefix[i-1];
  }

  vector<int> ans;
  ans.push_back(p.back().second+1);
  for (int i = n-2; i >= 0; --i) {
    i64 pref = i > 0 ? prefix[i-1] : 0;
    if (p[i].first + pref < p[i+1].first) {
      break;
    } else {
      ans.push_back(p[i].second+1);
    }
  }
  sort(ans.begin(), ans.end());

  cout << ans.size() << endl;
  for (int p : ans) {
    cout << p << " ";
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

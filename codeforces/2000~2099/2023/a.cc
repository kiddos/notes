#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a1(n), a2(n);
  for (int i = 0; i < n; ++i) {
    cin >> a1[i] >> a2[i];
  }

  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.emplace_back(a1[i], a2[i]);
  }
  sort(p.begin(), p.end(), [&](auto& p1, auto& p2) {
    return p1.first + p1.second < p2.first + p2.second;
  });

  vector<int> ans;
  for (auto [ai1, ai2] : p) {
    ans.push_back(ai1);
    ans.push_back(ai2);
  }
  for (int x : ans) {
    cout << x << " ";
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

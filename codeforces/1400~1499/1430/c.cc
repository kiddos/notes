#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  if (n == 2) {
    cout << "2" << endl;
    cout << "1 2" << endl;
    return;
  }

  vector<vector<int>> p(2);
  for (int i = 1; i < n; ++i) {
    p[i%2].push_back(i);
  }
  int a = n;
  vector<pair<int,int>> ans;
  for (int i = 0; i < n-1; ++i) {
    int b = p[a%2].back();
    p[a%2].pop_back();
    ans.push_back({a, b});
    a = (a+b) / 2;
  }
  cout << "2" << endl;
  for (auto [ai, bi] : ans) {
    cout << ai << " " << bi << endl;
  }
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

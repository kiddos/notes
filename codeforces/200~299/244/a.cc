#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }

  set<int> s;
  for (int i = 1; i <= n*k; ++i) {
    s.insert(i);
  }
  vector<vector<int>> ans(k);
  for (int i = 0; i < k; ++i) {
    ans[i].push_back(a[i]);
    s.erase(a[i]);
  }
  for (int i = 0; i < k; ++i) {
    while ((int)ans[i].size() < n) {
      int x = *s.begin();
      s.erase(s.begin());
      ans[i].push_back(x);
    }
  }

  for (vector<int>& g : ans) {
    for (int x : g) {
      cout << x << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

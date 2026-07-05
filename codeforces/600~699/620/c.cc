#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int idx = 1;
  vector<pair<int,int>> ans;
  while (idx <= n) {
    bool found = false;
    map<int,int> count;
    int j = idx;
    while (j <= n) {
      int x = a[j];
      count[x]++;
      j++;
      if (count[x] >= 2) {
        found = true;
        break;
      }
    }
    if (found) {
      ans.push_back({idx, j-1});
    }
    idx = j;
  }

  if (ans.empty()) {
    cout << "-1" << endl;
    return;
  }

  ans.back().second = n;
  cout << ans.size() << endl;
  for (auto [l, r] : ans) {
    cout << l << " " << r << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

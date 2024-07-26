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

  vector<int> components;
  for (int i = 1; i <= n; ++i) {
    components.push_back(i);
  }

  vector<pair<int,int>> ans;
  for (int x = n-1; x >= 1; --x) {
    vector<int> found(x, -1);
    for (int c : components) {
      int mod = a[c] % x;
      if (found[mod] > 0) {
        ans.push_back({c, found[mod]});
        auto it = find(components.begin(), components.end(), found[mod]);
        components.erase(it);
        break;
      } else {
        found[mod] = c;
      }
    }
  }

  reverse(ans.begin(), ans.end());
  cout << "YES" << endl;
  for (auto& [u, v] : ans) {
    cout << u << " " << v << endl;
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

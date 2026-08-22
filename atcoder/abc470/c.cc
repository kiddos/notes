#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  map<int, int> values;
  int current = 0;
  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    int t = 0;
    cin >> t;
    if (t == 1) {
      int x = 0;
      cin >> x;

      if (values.count(x)) {
        current ^= values[x];
      }
      values[x]++;
      current ^= values[x];
    } else if (t == 2) {
      vector<int> to_remove;
      for (auto it = values.begin(); it != values.end(); ++it) {
        current ^= it->second;
        if (--it->second == 0) {
          to_remove.push_back(it->first);
        }
        current ^= it->second;
      }
      for (int val : to_remove) {
        values.erase(val);
      }
    }
    ans.push_back(current);
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

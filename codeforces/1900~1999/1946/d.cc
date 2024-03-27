#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;

  x++;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  int ans = -1;
  for (int b = 30; b >= 0; --b) {
    vector<int> indices;
    for (int i = 0; i < (int)a.size(); ++i) if (a[i] & (1<<b)) {
      indices.push_back(i);
    }

    // cout << "indices: " << indices.size() << endl;
    vector<int> new_a;
    bool merge = false;
    for (int i = 0, j = 0; i < (int)a.size(); ++i) {
      if (merge) {
        new_a.back() ^= a[i];
      } else {
        new_a.push_back(a[i]);
      }

      if (j < (int)indices.size() && i == indices[j]) {
        merge = !merge;
        j++;
      }
    }
    if (!(x & (1<<b))) {
      // need to remove this bit
      if (indices.size() % 2 == 1) {
        // always have left over
        cout << ans << endl;
        return;
      }

      a = std::move(new_a);
    } else {
      if (indices.size() % 2 == 0) {
        ans = max(ans, (int)new_a.size());
      }
    }
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
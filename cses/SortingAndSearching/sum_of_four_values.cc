#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 x = 0;
  cin >> n >> x;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  map<i64, vector<pair<int,int>>> indices;
  for (int l = 0; l < n; ++l) {
    for (int r = l+1; r < n; ++r) {
      i64 sum = a[l] + a[r];
      indices[sum].push_back({l, r});
    }
  }

  for (auto [s1, idx1] : indices) {
    if (!indices.count(x - s1)) {
      continue;
    }

    vector<pair<int,int>>& idx2 = indices[x - s1];
    for (auto [i1, i2] : idx1) {
      for (auto [i3, i4] : idx2) {
        set<int> s = {i1, i2, i3, i4};
        if (s.size() == 4) {
          for (int idx : s) {
            cout << idx+1 << " ";
          }
          cout << endl;
          return;
        }
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

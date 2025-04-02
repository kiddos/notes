#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  set<array<int,3>> unoccupied;
  set<array<int,3>> occupied;
  int empty_line = 0;

  auto insert_unoccupied = [&]() {
    for (int x = 0; x <= empty_line; ++x) {
      int y = empty_line - x;
      unoccupied.insert({3 * x + 3 * y + 2, 3 * x + 1, 3 * y + 1});
    }
    empty_line++;
  };

  vector<pair<int,int>> ans;
  for (int i = 0; i < n; ++i) {
    if (unoccupied.empty()) {
      insert_unoccupied();
    }

    if (t[i] == 0) {
      auto [l, r, c] = *unoccupied.begin();
      unoccupied.erase(unoccupied.begin());
      ans.push_back({r, c});
      occupied.insert({r+c+1, r+1, c});
      occupied.insert({r+c+1, r, c+1});
      // add extra 2 because we cannot go through table
      occupied.insert({r+c+4, r+1, c+1});
    } else {
      if (!occupied.empty()) {
        auto [l1, r1, c1] = *occupied.begin();
        auto [l2, r2, c2] = *unoccupied.begin();
        if (l1 < l2 || ((l1 == l2) && r1 < r2)) {
          occupied.erase(occupied.begin());
          ans.push_back({r1, c1});
        } else {
          unoccupied.erase(unoccupied.begin());
          ans.push_back({r2, c2});
          occupied.insert({r2+c2+1, r2+1, c2});
          occupied.insert({r2+c2+1, r2, c2+1});
          occupied.insert({r2+c2+4, r2+1, c2+1});
        }
      } else {
        auto [l, r, c] = *unoccupied.begin();
        unoccupied.erase(unoccupied.begin());
        ans.push_back({r, c});
        occupied.insert({r+c+1, r+1, c});
        occupied.insert({r+c+1, r, c+1});
        occupied.insert({r+c+4, r+1, c+1});
      }
    }
  }

  for (auto [r, c] : ans) {
    cout << r << " " << c << endl;
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

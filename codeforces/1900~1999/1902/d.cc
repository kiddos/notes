#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  string s;
  cin >> s;

  map<int, map<int, vector<int>>> indices;
  int x = 0, y = 0;
  indices[x][y].push_back(0);
  vector<pair<int,int>> pos;
  pos.emplace_back(x, y);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'U') {
      y++;
    } else if (s[i] == 'D') {
      y--;
    } else if (s[i] == 'L') {
      x--;
    } else if (s[i] == 'R') {
      x++;
    }

    indices[x][y].push_back(i+1);
    pos.emplace_back(x, y);
  }

  auto query_left = [&](int x, int y, int l) -> bool {
    if (!indices.count(x)) return false;
    if (!indices[x].count(y)) return false;
    vector<int>& idx = indices[x][y];
    return upper_bound(idx.begin(), idx.end(), l-1) != idx.begin();
  };

  auto query_right = [&](int x, int y, int r) -> bool {
    if (!indices.count(x)) return false;
    if (!indices[x].count(y)) return false;
    vector<int>& idx = indices[x][y];
    return lower_bound(idx.begin(), idx.end(), r+1) != idx.end();
  };

  // pos(l-1) + pos(r) - pos(i) = (x, y)
  // => pos(i) = pos(l-1) + pos(r) - (x, y)
  // => find an index i such that i >= l-1 and i <= r
  // in the map
  // x = pos[l-1][0] + pos[r][0] - xi
  // y = pos[l-1][1] + pos[r][1] - yi
  auto query_middle = [&](int xi, int yi, int l, int r) -> bool {
    int x = pos[l-1].first + pos[r].first - xi;
    int y = pos[l-1].second + pos[r].second - yi;
    if (!indices.count(x)) return false;
    if (!indices[x].count(y)) return false;
    vector<int>& idx = indices[x][y];
    auto it = lower_bound(idx.begin(), idx.end(), l-1);
    if (it == idx.end()) return false;
    return *it <= r;
  };

  auto query = [&](int x, int y, int l, int r) -> bool {
    return query_left(x, y, l) || query_right(x, y, r) || query_middle(x, y, l, r);
  };

  for (int i = 0; i < q; ++i) {
    int xi = 0, yi = 0, l = 0, r = 0;
    cin >> xi >> yi >> l >> r;
    bool result = query(xi, yi, l, r);
    if (result) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

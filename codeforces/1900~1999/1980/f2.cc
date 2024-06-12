#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<array<i64, 3>> p(k);
  for (int i = 0; i < k; ++i) {
    cin >> p[i][0] >> p[i][1];
    p[i][2] = i;
  }

  sort(p.begin(), p.end(), [&](auto& p1, auto& p2) {
    if (p1[0] == p2[0]) {
      return p1[1] < p2[1];
    }
    return p1[0] > p2[0];
  });

  p.push_back({0, 0, k});

  vector<i64> area(k+1);
  vector<i64> last_rows(k+1, n);
  vector<i64> last_cols(k+1, m+1);
  vector<bool> is_corner(k+1);
  for (int i = 0; i <= k; ++i) {
    auto [r, c, idx] = p[i];
    if (i > 0) {
      last_rows[i] = last_rows[i-1];
      last_cols[i] = last_cols[i-1];
    }
    if (last_cols[i] > c) {
      i64 h = last_rows[i] - r;
      i64 w = last_cols[i] - 1;
      area[i] = w * h;
      last_rows[i] = r;
      last_cols[i] = c;
      is_corner[i] = true;
      // cout << "r=" << r << ", c=" << c << ", w=" << w << ", h=" << h << endl;
    }
  }

  for (int i = 1; i <= k; ++i) {
    area[i] += area[i-1];
  }
  i64 alice = area[k];
  cout << alice << endl;

  vector<i64> ans(k+1);
  for (int i = 0; i < k; ++i) {
    if (is_corner[i]) {
      i64 last_c = i > 0 ? last_cols[i-1] : m+1;
      i64 last_r = i > 0 ? last_rows[i-1] : n;
      i64 change = i > 0 ? area[i-1] : 0;
      // cout << "start=" << change << endl;

      for (int j = i+1; j <= k; ++j) {
        auto [r, c, idx] = p[j];
        if (last_c > c) {
          i64 h = last_r - r;
          i64 w = last_c - 1;
          // cout << "r=" << r << ", c=" << c << ", w=" << w << ", h=" << h << endl;
          change += h * w;
          last_c = c;
          last_r = r;
        }
        if (is_corner[j]) {
          ans[p[i][2]] = change - area[j];
          break;
        }
      }
      // cout << "change=" << ans[p[i][2]] << " idx= " << p[i][2] << ", area " <<
      //   area[j] << endl;
    }
  }

  for (int i = 0; i < k; ++i) {
    cout << ans[i] << " ";
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

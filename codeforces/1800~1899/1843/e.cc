#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  vector<pair<int, int>> segments;
  for (int i = 0; i < m; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    segments.emplace_back(l, r);
  }
  
  int q = 0;
  cin >> q;
  vector<int> queries(q);
  for (int i = 0; i < q; ++i) cin >> queries[i];

  auto is_beautiful = [&](int num_q) {
    vector<int> line(n+1);
    for (int i = 0; i <= num_q; ++i) {
      line[queries[i]] = 1;
    }

    vector<int> p = {0};
    for (int i = 0; i < line.size(); ++i) {
      p.push_back(p.back() + line[i]);
    }

    for (auto& [l, r] : segments) {
      int ones = p[r+1] - p[l];
      int segment_size = r-l+1;
      int zeros = segment_size - ones;
      if (ones > zeros) {
        return true;
      }
    }
    return false;
  };

  int l = 0, r = q-1;
  int ans = -1;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (is_beautiful(mid)) {
      ans = mid+1;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }

  cout << ans << endl;
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

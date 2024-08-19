#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<pair<int,int>> colors(n+1);
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    if (s == "BG") {
      colors[i] = {0, 1};
    } else if (s == "BR") {
      colors[i] = {0, 2};
    } else if (s == "BY") {
      colors[i] = {0, 3};
    } else if (s == "GR") {
      colors[i] = {1, 2};
    } else if (s == "GY") {
      colors[i] = {1, 3};
    } else if (s == "RY") {
      colors[i] = {2, 3};
    }
  }

  vector<vector<int>> right(16), left(16);
  for (int mask = 1; mask < 16; ++mask) {
    if (bitset<4>(mask).count() != 2) {
      continue;
    }

    vector<int> r(n+1, -1);
    stack<int> s;
    for (int i = 1; i <= n; ++i) {
      int current_mask = (1<<colors[i].first) | (1 << colors[i].second);
      if (current_mask == mask) {
        while (!s.empty()) {
          r[s.top()] = i;
          s.pop();
        }
        r[i] = i;
      } else {
        s.push(i);
      }
    }
    right[mask] = r;

    vector<int> l(n+1, -1);
    s = stack<int>();
    for (int i = n; i >= 1; --i) {
      int current_mask = (1<<colors[i].first) | (1 << colors[i].second);
      if (current_mask == mask) {
        while (!s.empty()) {
          l[s.top()] = i;
          s.pop();
        }
        l[i] = i;
      } else {
        s.push(i);
      }
    }
    left[mask] = l;
  }

  auto share_color = [&](int x, int y) -> bool {
    return colors[x].first == colors[y].first ||
      colors[x].first == colors[y].second ||
      colors[x].second == colors[y].first ||
      colors[x].second == colors[y].second;
  };

  for (int i = 0; i < q; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    int a = min(x, y);
    int b = max(x, y);

    if (share_color(a, b)) {
      int dist = b - a;
      cout << dist << endl;
    } else {
      vector<int> masks = {
        (1<<colors[a].first) | (1 << colors[b].first),
        (1<<colors[a].first) | (1 << colors[b].second),
        (1<<colors[a].second) | (1 << colors[b].first),
        (1<<colors[a].second) | (1 << colors[b].second),
      };
      int ans = numeric_limits<int>::max();
      for (int mask : masks) {
        int l = left[mask][x], r = right[mask][x];
        if (l > 0) {
          ans = min(ans, abs(a - l) + abs(b - l));
        }
        if (r > 0) {
          ans = min(ans, abs(a - r) + abs(b - r));
        }
      }

      if (ans == numeric_limits<int>::max()) {
        cout << "-1" << endl;
      } else {
        cout << ans << endl;
      }
    }
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

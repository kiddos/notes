#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  string s;
  cin >> s;
  s = " " + s;

  vector<int> queries(q);
  for (int i = 0; i < q; ++i) {
    cin >> queries[i];
  }

  vector<pair<int,int>> moves;
  for (int i = 1; i <= n; ++i) {
    if (p[i] != i) {
      int x = min(p[i], i), y = max(p[i], i);
      moves.emplace_back(x, y);
    }
  }

  auto is_stop = [&](int idx) -> bool {
    return idx+1 <= n && s[idx] == 'L' && s[idx+1] == 'R';
  };

  vector<i64> line(n+2);
  for (auto& [l, r] : moves) {
    line[l]++;
    line[r]--;
  }
  for (int i = 1; i <= n; ++i) {
    line[i] += line[i-1];
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << line[i] << " ";
  // }
  // cout << endl;

  vector<bool> state(n+1);
  i64 total_blocked = 0;
  for (int i = 1; i <= n; ++i) {
    state[i] = is_stop(i);
    if (state[i]) {
      total_blocked += line[i];
    }
  }

  auto flip = [&](int idx) {
    s[idx] = s[idx] == 'R' ? 'L' : 'R';
  };

  auto update = [&](int idx) {
    if (idx < 0 || idx > n) return;
    bool new_state = is_stop(idx);
    if (new_state != state[idx]) {
      state[idx] = new_state;
      if (state[idx]) {
        total_blocked += line[idx];
      } else {
        total_blocked -= line[idx];
      }
    }
  };

  for (int i : queries) {
    flip(i);
    update(i);
    update(i-1);

    if (total_blocked == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
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

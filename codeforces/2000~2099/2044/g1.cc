#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> r(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> r[i];
  }

  vector<int> last(n+1);
  vector<int> state(n+1);
  vector<bool> is_cycle(n+1);
  function<void(int)> mark_cycle = [&](int node) {
    if (state[node]) {
      if (state[node] == 1) {
        // found cycle
        int x = node;
        do {
          is_cycle[x] = true;
          x = last[x];
        } while (x != node);
      }
      return;
    }

    state[node] = 1;
    last[r[node]] = node;
    mark_cycle(r[node]);
    state[node] = 2;
  };

  for (int node = 1; node <= n; ++node) {
    if (!state[node]) {
      mark_cycle(node);
    }
  }

  // for (int node = 1; node <= n; ++node) {
  //   cout << is_cycle[node] << " ";
  // }
  // cout << endl;

  vector<int> dist_to_cycle(n+1);
  function<void(int)> compute_dist_to_cycle = [&](int node) {
    if (is_cycle[node]) {
      return;
    }
    if (dist_to_cycle[node]) {
      return;
    }

    compute_dist_to_cycle(r[node]);
    dist_to_cycle[node] = dist_to_cycle[r[node]] + 1;
  };

  for (int node = 1; node <= n; ++node) {
    compute_dist_to_cycle(node);
  }

  // for (int node = 1; node <= n; ++node) {
  //   cout << dist_to_cycle[node] << " ";
  // }
  // cout << endl;

  int max_dist = *max_element(dist_to_cycle.begin(), dist_to_cycle.end());
  int ans = max_dist + 2;
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

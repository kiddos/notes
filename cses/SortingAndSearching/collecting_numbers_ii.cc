#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> x(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }

  vector<int> idx(n+1);
  for (int i = 1; i <= n; ++i) {
    idx[x[i]] = i;
  }
  int round = 1;

  auto round_inc = [&](int pi) -> int {
    int last_idx = idx[pi-1];
    int current_idx = idx[pi];
    if (last_idx > current_idx) {
      return 1;
    }
    return 0;
  };

  for (int pi = 2; pi <= n; ++pi) {
    round += round_inc(pi);
  }

  vector<int> ans;
  vector<int> s;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;

    int a_idx = idx[x[a]];
    int b_idx = idx[x[b]];

    s.clear();
    for (int xi = max(1, x[a]-1); xi <= min(x[a]+1, n); ++xi) {
      s.push_back(xi);
    }
    for (int xi = max(1, x[b]-1); xi <= min(x[b]+1, n); ++xi) {
      s.push_back(xi);
    }
    sort(s.begin(), s.end());
    s.resize(unique(s.begin(), s.end()) - s.begin());

    for (int xi : s) {
      round -= round_inc(xi);
    }

    idx[x[a]] = b_idx;
    idx[x[b]] = a_idx;
    swap(x[a], x[b]);

    for (int xi : s) {
      round += round_inc(xi);
    }

    ans.push_back(round);
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << x[i] << " ";
  // }
  // cout << endl;
  
  for (int r : ans) {
    cout << r << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

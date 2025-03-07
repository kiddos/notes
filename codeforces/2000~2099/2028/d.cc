#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> pref(3, vector<int>(n+1));
  for (int i = 0; i < 3; ++i) {
    for (int a = 1; a <= n; ++a) {
      cin >> pref[i][a];
    }
  }

  vector<int> min_reach = {n, n, n};
  vector<array<int,2>> next(n+1, {-1, -1});
  for (int a = n-1; a >= 1; --a) {
    for (int p = 0; p < 3; ++p) {
      if (pref[p][min_reach[p]] < pref[p][a]) {
        next[a] = {min_reach[p], p};
      }
    }
    if (next[a][1] >= 0) {
      for (int p = 0; p < 3; ++p) {
        // for players who doesn't want to trade
        // because alice can now reach a by other player
        // they can start from a now
        if (pref[p][min_reach[p]] > pref[p][a]) {
          min_reach[p] = min(min_reach[p], a);
        }
      }
    }
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << next[i][0] << " " << next[i][1] << endl;
  // }

  string players = "qkj";
  int card = 1;
  vector<pair<int,int>> ans;
  while (card < n) {
    if (next[card][1] < 0) {
      cout << "NO" << endl;
      return;
    }
    int next_card = next[card][0];
    int p = next[card][1];
    ans.push_back({p, next_card});
    card = next_card;
    // cout << "player=" << p << ",card=" << card << endl;
  }

  cout << "YES" << endl;
  cout << ans.size() << endl;
  for (auto [p, card] : ans) {
    cout << players[p] << " " << card << endl;
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

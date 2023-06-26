#include <bits/stdc++.h>

using namespace std;

void solve() {
  deque<pair<int,int>> a;
  int n = 0, Q = 0;
  cin >> n >> Q;
  int max_player = 0;
  int max_a = 0;
  for (int i = 0; i < n; ++i) {
    int aa = 0;
    cin >> aa;
    a.push_back({aa, i+1});

    if (aa > max_a) {
      max_player = i+1;
      max_a = aa;
    }
  }

  vector<map<int,int>> wins(n+1);
  for (int t = 1; t <= 2 * n; ++t) {
    auto p1 = a.front();
    a.pop_front();
    auto p2 = a.front();
    a.pop_front();

    int p = 0;
    if (p1.first > p2.first) {
      p = p1.second;
      a.push_front(p1);
      a.push_back(p2);
    } else {
      p = p2.second;
      a.push_back(p1);
      a.push_front(p2);
    }

    map<int,int>& w = wins[p];
    wins[p][t] = w.empty() ? 1 : (w.rbegin()->second+1);
  }

  // cout << "wins: " << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << "player: " << i << endl;
  //   for (auto& [turn, win] : wins[i]) {
  //     cout << turn << " win " << win << endl;
  //   }
  // }

  vector<int> ans;
  for (int q = 0; q < Q; ++q) {
    int i = 0, k = 0;
    cin >> i >> k;
    if (k > 2 * n && i == max_player) {
      map<int,int>& w = wins[i];
      ans.push_back(w.rbegin()->second + (k - 2 * n));
    } else {
      map<int,int>& w = wins[i];
      auto it = w.upper_bound(k);
      if (it == w.begin()) {
        ans.push_back(0);
      } else {
        ans.push_back(prev(it)->second);
      }
    }
  }

  for (int s : ans) {
    cout << s << endl;
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

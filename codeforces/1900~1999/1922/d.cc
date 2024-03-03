#include <bits/stdc++.h>
 
using namespace std;
 
using i64 = long long;
 
void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n+2);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<i64> d(n+2);
  for (int i = 1; i <= n; ++i) cin >> d[i];

  set<int> alive;
  for (int i = 0; i <= n+1; ++i) {
    alive.insert(i);
  }

  set<int> q;
  for (int i = 1; i <= n; ++i) {
    q.insert(i);
  }

  vector<int> ans(n);
  for (int round = 0; round < n && !q.empty(); ++round) {
    set<int> q2;
    vector<int> to_remove;
    for (int i : q) {
      if (!alive.count(i)) {
        continue;
      }

      auto it = alive.find(i);
      int last_monster = *prev(it);
      int next_monster = *next(it);
      i64 attack = a[last_monster] + a[next_monster];
      if (attack > d[i]) {
        to_remove.push_back(i);
        if (last_monster > 0) q2.insert(last_monster);
        if (next_monster <= n) q2.insert(next_monster);
      }
    }
    for (int i : to_remove) {
      alive.erase(i);
    }
    ans[round] = to_remove.size();

    q = std::move(q2);
  }
 
  for (int i = 0; i < n; ++i) {
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

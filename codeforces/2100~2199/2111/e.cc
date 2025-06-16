#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<pair<char, char>> queries;
  for (int i = 0; i < q; ++i) {
    char x = '\0', y = '\0';
    cin >> x >> y;
    queries.emplace_back(x, y);
  }

  vector<set<int>> ops(9);
  for (int i = 0; i < q; ++i) {
    auto [x, y] = queries[i];
    int xc = x - 'a';
    int yc = y - 'a';
    int id = xc * 3 + yc;
    ops[id].insert(i);
  }

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      continue;
    } else if (s[i] == 'b') {
      // try to find b -> a
      if (!ops[3].empty()) {
        s[i] = 'a';
        ops[3].erase(ops[3].begin());
      } else {
        // try to find b -> c, c -> a
        if (!ops[5].empty()) {
          int t = *ops[5].begin();
          auto it = ops[6].lower_bound(t);
          if (it != ops[6].end()) {
            s[i] = 'a';
            ops[6].erase(it);
            ops[5].erase(t);
          }
        }
      }
    } else if (s[i] == 'c') {
      // try to find c -> a
      if (!ops[6].empty()) {
        s[i] = 'a';
        ops[6].erase(ops[6].begin());
      } else {
        // try to find c -> b, b -> a
        if (!ops[7].empty()) {
          int t = *ops[7].begin();
          auto it = ops[3].lower_bound(t);
          if (it != ops[3].end()) {
            s[i] = 'a';
            ops[7].erase(t);
            ops[3].erase(it);
          } else {
            // just do c -> b
            s[i] = 'b';
            ops[7].erase(t);
          }
        }
      }
    }
  }

  cout << s << endl;
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

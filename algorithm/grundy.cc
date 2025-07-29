#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int MAX_N = 21;
  vector<int> memo(MAX_N+1, -1);
  // 0 is the losing state
  // none-zero is winning state
  // in this game the first player to reach MAX_N loses
  // each turn a player can move from x to x+1, x+2, or x+3 
  // determine which player wins
  auto grundy = [&](const auto& self, int x) -> int {
    if (x == MAX_N) {
      return 0;
    }
    if (memo[x] >= 0) {
      return memo[x];
    }
    set<int> s;
    for (int i = 0; i <= MAX_N; ++i) {
      s.insert(i);
    }
    for (int y = x+1; y <= min(x+3, MAX_N); ++y) {
      s.erase(self(self, y));
    }
    return memo[x] = *s.begin();
  };

  for (int i = 1; i <= MAX_N; ++i) {
    cout << grundy(grundy, i) << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

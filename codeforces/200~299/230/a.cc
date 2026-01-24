#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 s = 0;
  int n = 0;
  cin >> s >> n;
  vector<pair<int,int>> dragon;
  for (int i = 0; i < n; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    dragon.push_back({x, y});
  }
  sort(dragon.begin(), dragon.end());
  for (auto [x, y] : dragon) {
    if (s <= x) {
      cout << "NO" << endl;
      return;
    }
    s += y;
  }
  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

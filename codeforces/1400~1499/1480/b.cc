#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int A = 0, B = 0, n = 0;
  cin >> A >> B >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  vector<pair<int,int>> monsters;
  for (int i = 0; i < n; ++i) {
    monsters.emplace_back(a[i], b[i]);
  }

  sort(monsters.begin(), monsters.end());

  for (int i = 0; i < n; ++i) {
    i64 hero_attacks = (monsters[i].second + A - 1) / A;
    i64 monster_attacks = (B + monsters[i].first - 1) / monsters[i].first;
    if (monster_attacks < hero_attacks) {
      cout << "NO" << endl;
      return;
    }
    B -= hero_attacks * monsters[i].first;
    B = max(B, 0);
  }
  cout << "YES" << endl;
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

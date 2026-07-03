#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int h1 = 0, a1 = 0, c1 = 0;
  cin >> h1 >> a1 >> c1;
  int h2 = 0, a2 = 0;
  cin >> h2 >> a2;

  array<int,3> ans = {0, 0, 0};
  int l = 1, r = 1000000;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    int received_damage = (mid-1) * a2;
    int extra_health = max(received_damage - h1 + 1, 0);
    int heal = (extra_health + c1 -1) / c1;
    int attack = max(mid - heal, 0);
    int monster_damage = attack * a1;
    if (monster_damage >= h2) {
      ans = {mid, heal, attack};
      r = mid-1;
    } else {
      l = mid+1;
    }
  }
  cout << ans[0] << endl;
  for (int i = 0; i < ans[1]; ++i) {
    cout << "HEAL" << endl;
  }
  for (int i = 0; i < ans[2]; ++i) {
    cout << "STRIKE" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

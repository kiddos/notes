#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.push_back({b[i], a[i]});
  }
  sort(p.rbegin(), p.rend());
  int can_play = 1;
  int points = 0;
  for (int i = 0; i < min(can_play, n); ++i) {
    can_play += p[i].first;
    points += p[i].second;
  }
  cout << points << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

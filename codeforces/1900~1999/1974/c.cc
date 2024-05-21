#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  i64 ans = 0;
  map<array<int, 2>, int> totals[3];
  map<array<int, 2>, map<int,int>> counts[3];
  for (int i = 2; i < n; ++i) {
    array<int,2> key1 = {a[i-1], a[i]};
    array<int,2> key2 = {a[i-2], a[i]};
    array<int,2> key3 = {a[i-2], a[i-1]};

    if (totals[0].count(key1)) {
      ans += totals[0][key1] - counts[0][key1][a[i-2]];
    }
    if (totals[1].count(key2)) {
      ans += totals[1][key2] - counts[1][key2][a[i-1]];
    }
    if (totals[2].count(key3)) {
      ans += totals[2][key3] - counts[2][key3][a[i]];
    }

    totals[0][key1]++;
    totals[1][key2]++;
    totals[2][key3]++;
    counts[0][key1][a[i-2]]++;
    counts[1][key2][a[i-1]]++;
    counts[2][key3][a[i]]++;
  }

  cout << ans << endl;
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

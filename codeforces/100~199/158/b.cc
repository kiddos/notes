#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> counts(5);
  for (int i = 0; i < n; ++i) {
    int a = 0;
    cin >> a;
    counts[a]++;
  }
  int ans = counts[4];
  int g1 = min(counts[1], counts[3]);
  ans += g1;
  counts[1] -= g1;
  counts[3] -= g1;
  ans += counts[2] / 2;
  counts[2] %= 2;
  ans += counts[3];

  if (counts[2]) {
    ans++;
    counts[1] -= min(counts[1], 2);
    ans += (counts[1] + 3) / 4;
  } else {
    ans += (counts[1] + 3) / 4;
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

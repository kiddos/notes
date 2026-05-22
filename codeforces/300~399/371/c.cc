#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  vector<i64> n(3);
  for (int i = 0; i < 3; ++i) {
    cin >> n[i];
  }
  vector<i64> p(3);
  for (int i = 0; i < 3; ++i) {
    cin >> p[i];
  }
  i64 R = 0;
  cin >> R;

  vector<i64> require(3);
  for (char ch : s) {
    if (ch == 'B') {
      require[0]++;
    } else if (ch == 'S') {
      require[1]++;
    } else if (ch == 'C') {
      require[2]++;
    }
  }

  i64 l = 0, r = R + accumulate(n.begin(), n.end(), 0LL);
  i64 ans = 0;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    vector<i64> cost(3);
    for (int i = 0; i < 3; ++i) {
      cost[i] = max(require[i] * mid - n[i], 0LL) * p[i];
    }
    i64 total_cost = accumulate(cost.begin(), cost.end(), 0LL);
    if (total_cost <= R) {
      ans = mid;
      l = mid+1;
    } else {
      r = mid-1;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

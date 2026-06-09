#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  vector<int> P(3), T(2);
  cin >> n;
  for (int i = 0; i < 3; ++i) {
    cin >> P[i];
  }
  for (int i = 0; i < 2; ++i) {
    cin >> T[i];
  }
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }

  int current = l[0];
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (current + T[0] + T[1] <= l[i]) {
      ans += (l[i] - (current + T[0] + T[1])) * P[2];
      ans += T[1] * P[1];
      ans += T[0] * P[0];
    } else if (current + T[0] <= l[i]) {
      ans += (l[i] - (current + T[0])) * P[1];
      ans += T[0] * P[0];
    } else {
      ans += (l[i] - current) * P[0];
    }
    ans += (r[i] - l[i]) * P[0];
    current = r[i];
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

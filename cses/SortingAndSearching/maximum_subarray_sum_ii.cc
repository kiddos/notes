#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, a = 0, b = 0;
  cin >> n >> a >> b;
  vector<i64> x(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  vector<i64> p = x;
  for (int i = 1; i <= n; ++i) {
    p[i] += p[i-1];
  }

  i64 ans = numeric_limits<i64>::min();
  multiset<i64> s;
  for (int i = 1; i <= n; ++i) {
    if (i >= a) {
      s.insert(p[i-a]);
    }
    if (i > b) {
       s.erase(s.find(p[i-b-1]));
    }

    if (i >= a) {
      i64 smallest = *s.begin();
      i64 subsum = p[i] - smallest;
      ans = max(ans, subsum);
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, c = 0;
  cin >> a >> c;

  auto to_ternary = [&](int x) -> vector<int> {
    vector<int> t;
    while (x > 0) {
      t.push_back(x % 3);
      x /= 3;
    }
    return vector<int>(t.rbegin(), t.rend());
  };

  vector<int> x = to_ternary(a);
  vector<int> z = to_ternary(c);
  int len = max(x.size(), z.size());
  reverse(x.begin(), x.end());
  reverse(z.begin(), z.end());
  vector<int> y;
  for (int i = 0; i < len; ++i) {
    int t1 = i < (int)x.size() ? x[i] : 0;
    int t3 = i < (int)z.size() ? z[i] : 0;
    int t2 = (t3 - t1 + 3) % 3;
    y.push_back(t2);
  }
  reverse(y.begin(), y.end());
  int ans = 0;
  for (int i = 0; i < (int)y.size(); ++i) {
    ans = ans * 3 + y[i];
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

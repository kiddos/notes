#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<i64> get_divisors(i64 x) {
  vector<i64> divs;
  for (i64 d = 1; d * d <= x; ++d) {
    if (x % d == 0) {
      divs.push_back(d);
      divs.push_back(x / d);
    }
  }
  sort(divs.begin(), divs.end());
  divs.resize(unique(divs.begin(), divs.end()) - divs.begin());
  return divs;
}

void solve() {
  i64 a = 0, b = 0, c = 0, d = 0;
  cin >> a >> b >> c >> d;
  i64 p = a * b;
  vector<i64> div_a = get_divisors(a);
  vector<i64> div_b = get_divisors(b);
  for (i64 d1 : div_a) {
    for (i64 d2 : div_b) {
      i64 g = d1 * d2;
      i64 x = (a / g + 1) * g;
      if (x > c) continue;
      i64 y = (b / (p / g) + 1) * (p / g);
      if (y > d) continue;
      cout << x << " " << y << endl;
      return;
    }
  }
  cout << "-1 -1" << endl;
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

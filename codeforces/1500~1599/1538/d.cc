#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int count_factors(int x) {
  int c = 0;
  for (int d = 2; d * d <= x; ++d) {
    while (x % d == 0) {
      x /= d;
      c++;
    }
  }
  if (x > 1) {
    c++;
  }
  return c;
}

void solve() {
  int a = 0, b = 0, k = 0;
  cin >> a >> b >> k;

  int g = gcd(a, b);
  int a_to_g = count_factors(a / g);
  int b_to_g = count_factors(b / g);
  int g_to_1 = count_factors(g);
  int at_least_to_g = (a == g ? 0 : 1) + (b == g ? 0 : 1);
  int at_most_to_g = a_to_g + b_to_g;
  int at_least_to_1 = (a == 1 ? 0 : 1) + (b == 1 ? 0 : 1);
  int at_most_to_1 = a_to_g + b_to_g + g_to_1 * 2;
  if (at_least_to_g <= k && at_most_to_g >= k) {
    cout << "YES" << endl;
  } else if (at_least_to_1 <= k && at_most_to_1 >= k) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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

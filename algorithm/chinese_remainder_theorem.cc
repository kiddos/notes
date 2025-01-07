#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct Congruence {
  i64 a, m;
};

i64 extended_euclidean(i64 a, i64 b, i64& x, i64& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  i64 x1 = 0, y1 = 0;
  i64 g = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}

i64 mod_div(i64 a, i64 b, i64 m) {
  i64 x = 0, y = 0;
  i64 g = extended_euclidean(b, m, x, y);
  if (g != 1) {
    return -1;
  }
  i64 inv_b = (x % m + m) % m;
  return (a * inv_b) % m;
}

i64 chinese_remainder_theorem(vector<Congruence>& congruence) {
  i64 M = 1;
  for (auto [a, m] : congruence) {
    M *= m;
  }
  i64 ans = 0;
  for (auto [a, m] : congruence) {
    i64 Mi = M / m;
    i64 div = mod_div(1, Mi, m);
    i64 add = (a * Mi) % M;
    add = (add * div) % M;
    ans = (ans + add) % M;
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<Congruence> congruence = {
    Congruence{2, 3},
    Congruence{3, 5},
    Congruence{2, 7},
  };

  i64 ans = chinese_remainder_theorem(congruence);
  cout << ans << endl;
  assert(ans % 3 == 2);
  assert(ans % 5 == 3);
  assert(ans % 7 == 2);
  assert(ans == 23);
  return 0;
}

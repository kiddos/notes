#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_factors(int x) {
  vector<int> factors;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      factors.push_back(i);
      if (i * i != x) {
        factors.push_back(x / i);
      }
    }
  }
  return factors;
}

void solve() {
  vector<int> a(3);
  for (int i = 0; i < 3; ++i) {
    cin >> a[i];
  }
  vector<int> factors = get_factors(a[0]);
  for (i64 f : factors) {
    if (a[1] % f == 0) {
      i64 side2 = a[0] / f;
      i64 side3 = a[1] / f;
      if (side2 * side3 == a[2]) {
        i64 ans = (f + side2 + side3) * 4;
        cout << ans << endl;
        return;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

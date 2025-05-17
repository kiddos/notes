#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 query(i64 a, i64 b) {
  cout << "? " << a << " " << b << endl;
  int result = 0;
  cin >> result;
  return result;
}

void answer(i64 x) {
  cout << "! " << x << endl;
}

void solve() {
  i64 r = 0;
  i64 p = 1;
  for (int k = 1; k <= 30; ++k, p *= 2) {
    i64 g = query(p - r, p - r + p * 2);
    if (g == p * 2) {
      r |= p;
    }
  }
  answer(r);
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

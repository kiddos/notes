#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n = 0, m = 0;
  cin >> n >> m;
  ll n0 = n;

  int twos = 0, fives = 0;
  while (n % 2 == 0 && n > 0) {
    n /= 2;
    twos++;
  }
  while (n % 5 == 0 && n > 0) {
    n /= 5;
    fives++;
  }
  ll k = 1;
  while (twos > 0 && fives > 0) {
    twos--;
    fives--;
  }
  while (twos > 0 && k * 5 <= m) {
    k *= 5;
    twos--;
  }
  while (fives > 0 && k * 2 <= m) {
    k *= 2;
    fives--;
  }
  while (k * 10 <= m) {
    k *= 10;
  }

  if (k == 1) {
    cout << n0 * m << endl;
  } else {
    k *= m / k;
    cout << n0 * k << endl;
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

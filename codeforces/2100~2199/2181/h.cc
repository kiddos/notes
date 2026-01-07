#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> prime_factors(int x) {
  vector<int> p;
  for (int d = 2; d*d <= x; ++d) {
    while (x % d == 0) {
      p.push_back(d);
      x /= d;
    }
  }
  if (x > 1) {
    p.push_back(x);
  }
  return p;
}

void solve() {
  i64 w = 0, h = 0, d = 0, n = 0;
  cin >> w >> h >> d >> n;

  vector<int> primes = prime_factors(n);
  int wc = 1, hc = 1, dc = 1;
  for (int p : primes) {
    if (w % p == 0) {
      w /= p;
      wc *= p;
    } else if (h % p == 0) {
      h /= p;
      hc *= p;
    } else if (d % p == 0) {
      d /= p;
      dc *= p;
    } else {
      cout << "-1" << endl;
      return;
    }
  }
  wc--;
  hc--;
  dc--;

  cout << wc << " " << hc << " " << dc << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

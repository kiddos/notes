#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

map<int,int> get_factors(int n) {
  map<int,int> factors;
  for (int d = 2; d * d <= n; ++d) {
    while (n % d == 0) {
      factors[d]++;
      n /= d;
    }
  }
  if (n > 1) {
    factors[n]++;
  }
  return factors;
}

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;


  map<int,int> P = get_factors(n);
  map<int,int> P0 = P;


  while (q-- > 0) {
    int type = 0;
    cin >> type;
    if (type == 1) {
      int x = 0;
      cin >> x;

      map<int,int> x_factors = get_factors(x);
      for (auto& [p, c] : x_factors) {
        P[p] += c;
      }

      map<int,int> d;
      for (auto& [p, c] : P) {
        map<int,int> f = get_factors(c+1);
        for (auto& [p2, c] : f) {
          d[p2] += c;
        }
      }

      bool ans = true;
      for (auto& [p, c] : d) {
        if (!P.count(p) || P[p] < c) {
          ans = false;
          break;
        } 
      }

      if (ans) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else if (type == 2)  {
      P = P0;
    }
  }

  cout << endl;
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

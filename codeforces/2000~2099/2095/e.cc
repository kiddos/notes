#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 power(i64 x, i64 n, i64 mod) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= mod;
    }
    x = (x * x) % mod;
    n >>= 1;
  }
  return ans;
}

i64 mod_div(i64 a, i64 b, i64 m) {
  i64 inv_b = power(b, m-2, m);
  return (a * inv_b) % m;
}

void solve() {
  int n = 0, p = 0, k = 0;
  cin >> n >> p >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> c(n);
  for (int i = 0; i < n; ++i) {
    c[i] = (a[i] * a[i]) % p;
    c[i] *= a[i];
    c[i] %= p;
  }

  i64 ans = 0;
  if (k == 0) {
    int rest = n;
    for (int i = 0; i < n; ++i) {
      if (a[i] == 0) {
        rest--;
        ans += rest;
      }
    }
    cout << ans << endl;
    return;
  }

  map<int,int> count;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      continue;
    } else {
      int t = mod_div(k, c[i], p);
      if (count.count(t)) {
        ans += count[t];;
      }
    }
    count[c[i]]++;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

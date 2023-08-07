#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<ll> b(n+1);
  for (int i = 1; i <= n; ++i) cin >> b[i];

  function<ll(int,int)> compute_ops = [&](ll a, ll b) -> ll {
    if (a == 0) {
      return 0;
    }
    if (b == 0) {
      return 1;
    }
    if (a <= b) {
      return compute_ops(b, b-a) + 1;
    }

    ll b2 = b*2;
    ll k = a / b2;
    ll sub = k * b2;
    if (k) {
      return compute_ops(a - sub, b) + 3 * k;
    }
    return compute_ops(b, a-b) + 1;
  };

  unordered_set<int> parities;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 0 && b[i] == 0) continue;

    int ops = compute_ops(a[i], b[i]);
    int p = ops % 3;
    // cout << "a=" << a[i] << ", b=" << b[i] << ", ops: " << ops << endl;
    parities.insert(p);
  }

  if (parities.size() <= 1) {
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

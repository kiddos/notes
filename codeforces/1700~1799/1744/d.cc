#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  ll power2 = 0;
  for (int i = 0; i < n; ++i) {
    ll a = 0;
    cin >> a;
    while (a % 2 == 0) {
      a >>= 1;
      power2++;
    }
  }

  vector<ll> can_add;
  for (ll i = 2; i <= n; ++i) {
    ll add = 0;
    ll x = i;
    while (x % 2 == 0) {
      x >>= 1;
      add++;
    }
    if (add > 0) {
      can_add.push_back(add);
    }
  }

  ll total_can_add = accumulate(can_add.begin(), can_add.end(), 0LL);
  sort(can_add.begin(), can_add.end());

  if (power2 >= n) {
    cout << "0" << endl;
  } else if (power2 + total_can_add < n) {
    cout << "-1" << endl;
  } else {
    int ans = 0;
    while (power2 < n) {
      power2 += can_add.back();
      can_add.pop_back();
      ans++;
    }
    cout << ans << endl;
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

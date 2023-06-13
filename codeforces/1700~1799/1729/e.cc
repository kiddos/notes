#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll query(ll a, ll b) {
  cout << "? " << a << " " << b << endl;
  ll ans = 0;
  cin >> ans;
  return ans;
}

ll try_ask() {
  unordered_map<ll, int> results;
  for (int i = 2; i <= 25; ++i) {
    ll x = query(1, i);
    ll y = query(i, 1);
    if (x == -1) {
      return i-1;
    }

    if (x != y) {
      results[x+y]++;
    }
  }

  int most = 0;
  ll ans = 0;
  for (auto& [n, count] : results) {
    if (count > most) {
      most = count;
      ans = n;
    }
  }
  return ans;
}

void solve() {
  ll ans = try_ask();
  cout << "! " << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

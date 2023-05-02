#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n = 0, p = 0;
  cin >> n >> p;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  ll last = a.back();
  ll new_digit = 1;
  for (int i = n-2; i >= 0; --i) {
    if (a[i] != p-1) {
      new_digit = a[i] + 1;
      break;
    }
  }

  set<int> digits(a.begin(), a.end());

  auto check_with_new_digit = [&](ll start, ll end) -> bool {
    for (ll x = start; x <= end; ++x) {
      if (x != new_digit && !digits.count(x)) {
        return false;
      }
    }
    return true;
  };

  auto check = [&](ll start, ll end) -> bool {
    for (ll x = start; x <= end; ++x) {
      if (!digits.count(x)) {
        return false;
      }
    }
    return true;
  };

  ll l = 0, r = p-1;
  ll ans = r;
  while (l <= r) {
    ll m = l + (r-l) / 2;
    if ((last + m >= p && check_with_new_digit(last + m - (p -1), last - 1)) ||
        (last + m < p && check(0, last-1) && check(last+m+1, p-1))) {
      ans = m;
      r = m-1;
    } else {
      l = m+1;
    }
  }

  cout << ans << endl;
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

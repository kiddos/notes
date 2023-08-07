#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  ll n = 0, c = 0;
  cin >> n >> c;
  vector<ll> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  ll l = 1, r = sqrt(c)+1;
  while (l <= r) {
    ll mid = l + (r-l) / 2;
    ll total = 0;
    for (int i = 0; i < n; ++i) {
      total += (s[i] + mid) * (s[i] + mid);
      if (total > c) {
        break;
      }
    }

    if (total == c) {
      cout << mid / 2 << endl;
      return;
    } else if (total > c) {
      r = mid-1;
    } else {
      l = mid+1;
    }
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

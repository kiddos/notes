#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  int q = 0;
  cin >> q;
  pair<ll, ll> height = {1, numeric_limits<ll>::max()};

  auto compute_days = [&](ll a, ll b, ull h) -> ll {
    ull diff = a - b;
    ll l = 1, r = numeric_limits<ll>::max() / diff;
    ll ans = -1;
    while (l <= r) {
      ull m = l + (r-l) / 2;
      ull can_reach = (m - 1) * diff + a;
      if (can_reach >= h) {
        ans = m;
        r = m-1;
      } else {
        l = m+1;
      }
    }
    return ans;
  };

  for (int i = 0; i < q; ++i) {
    int e = 0;
    cin >> e;
    if (e == 1) {
      ll a = 0, b = 0, n = 0;
      cin >> a >> b >> n;
      ll diff = a - b;
      ll longest = (n - 1) * diff + a;
      ll shortest = n == 1 ? 1 : longest - diff + 1;

      if (longest < height.first || shortest > height.second) {
        cout << "0 ";
      } else {
        height.first = max(height.first, shortest);
        height.second = min(height.second, longest);
        cout << "1 ";
      }
    } else if (e == 2) {
      ll a = 0, b = 0;
      cin >> a >> b;

      ll min_days = compute_days(a, b, height.first);
      ll max_days = compute_days(a, b, height.second);
      // cout << endl << "days: ";
      // cout << min_days << ", " << max_days << "; " << height.first << "; " << height.second << endl;
      if (min_days != max_days) {
        cout << "-1 ";
      } else {
        cout << min_days << " ";
      }
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

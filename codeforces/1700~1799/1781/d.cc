#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll MAX_S = 1e9;

unordered_set<ll> squares;

void precompute() {
  for (ll d = 1; d*d <= MAX_S; ++d) {
    squares.insert(d*d);
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());

  int ans = 1;
  for (int i = 0; i < n; ++i) {
    unordered_map<ll, int> xs;
    for (int j = i+1; j < n; ++j) {
      ll diff = a[j] - a[i];

      for (int d = 1; d*d <= diff; ++d) {
        if (diff % d == 0) {
          ll t = (diff / d + d);
          if (t % 2 == 0) {
            t /= 2;
            ll x = t * t - a[j];
            if (x >= 0) {
              xs[x]++;
            }
          }
        }
      }
    }

    for (auto& [x, count] : xs) {
      ans = max(ans, count+1);
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}

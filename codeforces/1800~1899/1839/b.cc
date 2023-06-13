#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<ll,ll>> ab;
  for (int i = 0; i < n; ++i) {
    ll a = 0, b = 0;
    cin >> a >> b;
    ab.emplace_back(a, b);
  }

  sort(ab.begin(), ab.end(), [&](auto& p1, auto& p2) {
    if (p1.first == p2.first) {
      return p1.second > p2.second;
    }
    return p1.first < p2.first;
  });

  int max_on = 0;
  int on = 0;
  int i = 0;
  int j = 0;
  ll ans = 0;
  vector<bool> used(n);
  while (i < n) {
    while (i < n && ab[i].first <= max_on) {
      i++;
    }

    if (i < n) {
      ans += ab[i].second;
      max_on = max(max_on, ++on);
      used[i] = true;
      i++;
    }

    while (j < n && ab[j].first <= max_on) {
      if (used[j]) {
        on--;
      }
      j++;
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

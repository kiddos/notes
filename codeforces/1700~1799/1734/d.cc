#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  k--;

  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<pair<ll,ll>> L, R;
  ll sum = 0, required = 0;
  for (int i = k-1; i >= 0; --i) {
    sum += a[i];
    required = min(required, sum);
    if (sum >= 0) {
      L.push_back({sum, required});
      sum = required = 0;
    }
  }
  L.push_back({sum, required});
  sum = required = 0;

  for (int i = k+1; i < n; ++i) {
    sum += a[i];
    required = min(required, sum);
    if (sum >= 0) {
      R.push_back({sum, required});
      sum = required = 0;
    }
  }
  R.push_back({sum, required});

  // for (auto& [sum, required] : L) {
  //   cout << "sum=" << sum << ", required: " << required << endl;
  // }
  // for (auto& [sum, required] : R) {
  //   cout << "sum=" << sum << ", required: " << required << endl;
  // }

  int p = 0, q = 0;
  ll current = a[k];
  while (p < L.size() && q < R.size()) {
    if (current + L[p].second >= 0) {
      current += L[p].first;
      p++;
    } else if (current + R[q].second >= 0) {
      current += R[q].first;
      q++;
    } else {
      break;
    }
  }
  if (p >= L.size() || q >= R.size()) {
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

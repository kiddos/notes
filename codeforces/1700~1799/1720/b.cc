#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MAX_VAL = numeric_limits<int>::max();

void solve() {
  int n = 0;
  cin >> n;

  vector<ll> a(n+2);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<ll> lmax(n+2), lmin(n+2, MAX_VAL);
  for (int i = 1; i <= n; ++i) {
    lmax[i] = max(lmax[i-1], a[i]);
    lmin[i] = min(lmin[i-1], a[i]);
  }

  vector<ll> rmax(n+2), rmin(n+2, MAX_VAL);
  for (int i = n; i >= 1; --i) {
    rmax[i] = max(rmax[i+1], a[i]);
    rmin[i] = min(rmin[i+1], a[i]);
  }


  auto get_beauty = [&](int pivot) -> ll {
    ll current_min = a[pivot];
    ll ans = 0;
    for (int i = pivot; i >= 1; --i) {
      current_min = min(current_min, a[i]);
      ll min_val = min(lmin[i-1], rmin[pivot+1]);
      ll max_val = max(lmax[i-1], rmax[pivot+1]);
      ll beauty = a[pivot] - current_min + max_val - min_val;
      ans = max(ans, beauty);
    }

    current_min = a[pivot];
    for (int i = pivot; i <= n; ++i) {
      current_min = min(current_min, a[i]);
      ll min_val = min(lmin[pivot-1], rmin[i+1]);
      ll max_val = max(lmax[pivot-1], rmax[i+1]);
      ll beauty = a[pivot] - current_min + max_val - min_val;
      ans = max(ans, beauty);
    }
    return ans;
  };

  vector<int> index(n+2);
  iota(index.begin(), index.end(), 0);
  sort(index.begin(), index.end(), [&](int i1, int i2) {
    return a[i1] < a[i2];
  });

  ll ans = max(get_beauty(index[n+1]), get_beauty(index[n]));
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

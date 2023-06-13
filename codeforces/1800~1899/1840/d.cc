#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  if (a.size() <= 3) {
    cout << "0" << endl;
    return;
  }

  vector<ll> diff;
  for (int i = 1; i < a.size(); ++i) {
    diff.push_back(a[i] - a[i-1]);
  }

  auto can_achieve = [&](ll max_segment) {
    ll seg = 0;
    int cut = 0;
    for (int i = 0; i < diff.size(); ++i) {
      if (seg + diff[i] > max_segment) {
        seg = 0;
        cut++;
      } else {
        seg += diff[i];
      }
      if (cut > 2) return false;
    }
    return true;
  };

  ll l = 0, r = accumulate(diff.begin(), diff.end(), 0LL);
  ll ans = r;
  while (l <= r) {
    ll mid = l + (r-l) / 2;
    if (can_achieve(mid)) {
      ans = (mid+1)/2;
      r = mid-1;
    } else {
      l = mid+1;
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

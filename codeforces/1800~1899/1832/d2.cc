#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());

  vector<ll> p(n+1, numeric_limits<ll>::max());
  for (int i = 0; i < n; ++i) {
    p[i+1] = min(p[i], a[i]-i);
  }

  ll sum = accumulate(a.begin(), a.end(), 0LL);

  vector<ll> ans;
  for (int i = 0; i < q; ++i) {
    ll k = 0;
    cin >> k;

    if (k < n) {
      ans.push_back(min(p[k] + k, a[k]));
    } else if (k % 2 == n % 2) {
      ll s = sum - n * (n-1) / 2 - p[n] * n;
      ll temp = max(0LL, (k - n) / 2 - s);
      ans.push_back(p[n] + k - (temp + n - 1) / n);
    } else {
      ll second_min = min(p[n-1], a[n-1] - k);
      ll s = sum - n * (n-1) / 2 + (n-1) - k - second_min * n;
      ll temp = max(0LL, (k - (n - 1)) / 2 - s);
      ans.push_back(second_min + k - (temp + n - 1) / n);
    }
  }

  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_factors(int x) {
  vector<int> f;
  for (int d = 2; d * d <= x; ++d) {
    if (x % d == 0) {
      f.push_back(d);
      f.push_back(x / d);
    }
  }
  sort(f.rbegin(), f.rend());
  return f;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int sum = accumulate(a.begin(), a.end(), 0);
  int ans = sum;
  sort(a.begin(), a.end());
  for (int i = 1; i < n; ++i) {
    vector<int> factors = get_factors(a[i]);
    for (int f : factors) {
      int gained = a[0] * f - a[0];
      int removed = a[i] - a[i] / f;
      int new_sum = sum + gained - removed;
      ans = min(ans, new_sum);
    }
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

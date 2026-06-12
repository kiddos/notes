#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<i64> suffix_min = a;
  for (int i = n-2; i >= 0; --i) {
    suffix_min[i] = min(suffix_min[i], suffix_min[i+1]);
  }
  i64 total = accumulate(a.begin(), a.end(), 0LL);
  i64 ans = total - accumulate(suffix_min.begin(), suffix_min.end(), 0LL);
  map<i64,int> suffix_count;
  for (int i = 0; i < n; ++i) {
    suffix_count[suffix_min[i]]++;
  }
  int max_size = 0;
  for (auto [si, c] : suffix_count) {
    max_size = max(max_size, c);
  }
  ans += max_size - 1;
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

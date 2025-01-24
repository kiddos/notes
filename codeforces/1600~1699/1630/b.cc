#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> sorted = a;
  sort(sorted.begin(), sorted.end());
  int expected_size = (n + k + 1) / 2;
  constexpr int inf = numeric_limits<int>::max();
  array<int,3> ans = {inf, inf, inf};
  for (int i = 0; i <= n-expected_size; ++i) {
    int x = sorted[i], y = sorted[i+expected_size-1];
    int diff = y-x;
    ans = min(ans, {diff, x, y});
  }

  cout << ans[1] << " " << ans[2] << endl;
  vector<pair<int,int>> segments;
  for (int i = 0, b = 0, last = 0; i < n; ++i) {
    if (a[i] >= ans[1] && a[i] <= ans[2]) {
      b++;
    } else {
      b--;
    }
    if (b > 0) {
      b = 0;
      segments.push_back({last, i});
      last = i+1;
    }
  }
  while ((int)segments.size() > k) {
    segments.pop_back();
  }
  if (!segments.empty()) {
    segments.back().second = n-1;
  }
  assert((int)segments.size() == k);
  for (auto& [i1, i2] : segments) {
    cout << i1+1 << " " << i2+1 << endl;
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

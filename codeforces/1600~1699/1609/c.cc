#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 1e6;

vector<bool> is_p(MAX_N + 1, true);

void precompute() {
  is_p[0] = is_p[1] = false;

  for (int i = 2; i <= MAX_N; ++i) {
    if (is_p[i]) {
      for (int j = i+i; j <= MAX_N; j += i) {
        is_p[j] = false;
      }
    }
  }
}

void solve() {
  int n = 0, e = 0;
  cin >> n >> e;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> left_ones(n);
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1 && i+e < n) {
      left_ones[i+e] = left_ones[i] + 1;
    }
  }
  vector<int> right_ones(n);
  for (int i = n-1; i >= 0; --i) {
    if (a[i] == 1 && i-e >= 0) {
      right_ones[i-e] = right_ones[i] + 1;
    }
  }

  i64 ans = 0;
  for (int i = 0; i < e; ++i) {
    for (int j = i; j < n; j += e) {
      if (is_p[a[j]]) {
        i64 l = left_ones[j], r = right_ones[j];
        ans += l * (r + 1) + r;
      }
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

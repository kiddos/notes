#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];

  vector<int> t(n);
  for (int i = 0; i < n; ++i) cin >> t[i];

  constexpr int INF = numeric_limits<int>::max();
  auto can_meet = [&](int T) {
    int r = INF;
    int l = 0;
    for (int i = 0; i < n; ++i) {
      int left = x[i] - (T - t[i]);
      int right = x[i] + (T - t[i]);
      l = max(l, left);
      r = min(r, right);
    }
    return l <= r;
  };

  int l = 0, r = numeric_limits<int>::max();
  int T = r;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (can_meet(mid)) {
      T = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }

  int left = 0;
  int right = INF;
  for (int i = 0; i < n; ++i) {
    left = max(left, x[i] - (T - t[i]));
    right = min(right, x[i] + (T - t[i]));
  }

  long long  ans = ((long long) left + right);
  if (ans % 2 == 1) {
    cout << ans / 2 << ".5" << endl;
  } else {
    cout << ans / 2 << endl;
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

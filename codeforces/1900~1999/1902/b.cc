#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, P = 0, L = 0, T = 0;
  cin >> n >> P >> L >> T;

  i64 total_task = (n + 6) / 7;
  auto points = [&](i64 work) -> i64 {
    i64 task = min(work * 2, total_task);
    i64 task_points = task * T;
    i64 lession_points = work * L;
    return task_points + lession_points;
  };

  i64 l = 1, r = n;
  i64 work = r;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 p = points(mid);
    if (p >= P) {
      work = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }
  i64 ans = n - work;
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

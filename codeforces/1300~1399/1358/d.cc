#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 x = 0;
  cin >> n >> x;
  vector<i64> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }

  vector<i64> p = {0};
  for (int i = 0; i < n*2; ++i) {
    p.push_back(p.back() + d[i%n]);
  }

  vector<i64> prefix_hugs = {0};
  for (int i = 0; i < n*2; ++i) {
    i64 hugs = (d[i%n] + 1) * d[i%n] / 2;
    prefix_hugs.push_back(prefix_hugs.back() + hugs);
  }

  i64 ans = 0;
  for (int i = n; i < n*2; ++i) {
    int l = 0, r = i;
    int idx = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      i64 total_days = p[i+1] - p[mid];
      if (total_days <= x) {
        idx = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    if (idx < 0) {
      i64 last_day = d[i%n];
      i64 first_day = last_day - x + 1;
      i64 total_hugs = (first_day + last_day) * x / 2;
      ans = max(ans, total_hugs);
    } else {
      i64 full_month = p[i+1] - p[idx];
      i64 left = x - full_month;
      i64 last_day = d[(idx-1+n)%n];
      i64 first_day = last_day - left + 1;
      i64 total_hugs = (first_day + last_day) * left / 2;
      total_hugs += prefix_hugs[i+1] - prefix_hugs[idx];
      ans = max(ans, total_hugs);
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

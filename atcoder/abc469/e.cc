#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> o_count = {0};
  for (int i = 0; i < n; ++i) {
    o_count.push_back(o_count.back() + (s[i] == 'o'));
  }

  auto possible = [&](double prob) -> bool {
    vector<double> p = {0};
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'o') {
        p.push_back(1.0 - prob);
      } else {
        p.push_back(-prob);
      }
    }

    vector<double> ps = p;
    for (int i = 1; i <= n; ++i) {
      ps[i] += ps[i-1];
    }

    vector<double> min_ps = ps;
    for (int i = 1; i <= n; ++i) {
      min_ps[i] = min(min_ps[i], min_ps[i-1]);
    }

    for (int i = 1; i <= n; ++i) {
      int l = 1, r = i;
      int j = -1;
      while (l <= r) {
        int mid = l + (r-l) / 2;
        int count = o_count[i] - o_count[mid-1];
        if (count >= k) {
          j = mid;
          l = mid+1;
        } else {
          r = mid-1;
        }
      }

      if (j >= 1) {
        if (min_ps[j-1] <= ps[i]) {
          return true;
        }
      }
    }
    return false;
  };

  double l = 0, r = 1.0;
  double ans = 0;
  int iter = 100;
  while (abs(r-l) >= 1e-12 && iter-- > 0) {
    double mid = (l + r) / 2.0;
    if (possible(mid)) {
      ans = mid;
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << fixed << setprecision(9) << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

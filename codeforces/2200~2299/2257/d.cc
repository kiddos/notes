#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 s = 0;
  int q = 0;
  cin >> s >> q;
  vector<i64> x(q), y(q);
  for (int i = 0; i < q; ++i) {
    cin >> x[i] >> y[i];
  }

  vector<i64> factors;
  for (i64 d = 1; d * d <= s; ++d) {
    if (s % d == 0) {
      factors.push_back(d);
      factors.push_back(s / d);
    }
  }
  sort(factors.begin(), factors.end());
  factors.resize(unique(factors.begin(), factors.end()) - factors.begin());

  int size = factors.size();
  vector<i64> heights(size);
  for (int i = 0; i < size; ++i) {
    heights[i] = s / factors[i];
  }

  vector<i64> points(size);
  i64 last = 0;
  for (int i = 0; i < size; ++i) {
    i64 w = factors[i] - last;
    i64 h = heights[i];
    points[i] = w * h;
    last = factors[i];
  }

  // cout << "factors:";
  // for (int i = 0; i < size; ++i) {
  //   cout << factors[i] << " ";
  // }
  // cout << endl;
  //
  // cout << "heights:";
  // for (int i = 0; i < size; ++i) {
  //   cout << heights[i] << " ";
  // }
  // cout << endl;
  //
  // cout << "points: ";
  // for (int i = 0; i < size; ++i) {
  //   cout << points[i] << " ";
  // }
  // cout << endl;

  vector<i64> p = points;
  for (int i = 1; i < size; ++i) {
    p[i] += p[i-1];
  }

  vector<i64> ans;
  for (int i = 0; i < q; ++i) {
    auto it = upper_bound(factors.begin(), factors.end(), x[i]);
    int i1 = it - factors.begin() - 1;
    int i2 = -1;
    int l = 0, r = i1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (heights[mid] > y[i]) {
        l = mid+1;
        i2 = mid;
      } else {
        r = mid-1;
      }
    }

    // cout << "i1=" << i1 << ",i2=" << i2 << endl;

    i64 sum1 = 0;
    if (i1+1 < size) {
      i64 w = min(factors[i1+1], x[i]) - factors[i1];
      i64 h = min(heights[i1+1], y[i]);
      sum1 = w * h;
    }

    i64 sum2 = 0;
    if (i1 >= 0) {
      sum2 = p[i1] - (i2 >= 0 ? p[i2] : 0);
    }

    i64 sum3 = 0;
    if (i2 >= 0) {
      i64 w = factors[i2];
      i64 h = y[i];
      sum3 = w * h;
    }
    // cout << "sum1=" << sum1 << ", sum2=" << sum2 << ", sum3=" << sum3 << endl;
    i64 total = sum1 + sum2 + sum3;

    ans.push_back(total);
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
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

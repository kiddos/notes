#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 y = 0;
  cin >> n >> y;

  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  // sort(c.begin(), c.end());
  // int max_val = c.back();
  // int min_val = c[0];
  int max_val = *max_element(c.begin(), c.end());
  int min_val = *min_element(c.begin(), c.end());

  int max_x = max((max_val + min_val - 1) / min_val, 2);
  vector<int> counts(max_val+1);
  for (int i = 0; i < n; ++i) {
    counts[c[i]]++;
  }

  vector<int> p = counts;
  for (int i = 1; i <= max_val; ++i) {
    p[i] += p[i-1];
  }

  vector<i64> new_prices(max_x+1);
  for (int x = 2; x <= max_x; ++x) {
    for (int price = 1; price <= max_val; ++price) {
      int l = x * (price - 1);
      int r = min(x * price, max_val);
      if (l > max_val) {
        break;
      }

      i64 range_count = (p[r] - p[l]);
      new_prices[x] += range_count * price;
    }
  }

  // for (int x = 1; x <= max_x; ++x) {
  //   cout << "x=" << x << ", price=" << new_prices[x] << endl;
  // }
  // cout << endl;

  vector<int> saves(max_x+1);
  for (i64 val = 1; val <= max_val; ++val) {
    if (counts[val] == 0) {
      continue;
    }

    i64 to_x = max((max_val + val - 1) / val, 2LL);
    for (i64 x = 2; x <= to_x; ++x) {
      i64 l = val * x - x + 1;
      i64 r = val * x;
      if (l > max_val) {
        break;
      }

      // auto it1 = lower_bound(c.begin(), c.end(), l);
      // auto it2 = upper_bound(c.begin(), c.end(), r);
      // i64 save_tag = it2 - it1;
      i64 save_tag = p[min(r, (i64)max_val)] - p[l-1];
      save_tag = max(save_tag, 0LL);
      saves[x] += min(save_tag, (i64)counts[val]);
    }
  }

  // for (int x = 1; x <= max_x; ++x) {
  //   cout << saves[x] << " ";
  // }
  // cout << endl;

  i64 ans = numeric_limits<i64>::min();
  for (int x = 2; x <= max_x; ++x) {
    // cout << "x=" << x << ",saves=" << saves[x] << ":" << (n - saves[x]) * y<< endl;
    // cout << (n - saves[x]) * y << endl;
    i64 total = new_prices[x] - (n - saves[x]) * y;
    ans = max(ans, total);
  }
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0, x = 0;
  cin >> n >> k >> x;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  priority_queue<pair<double,i64>, vector<pair<double,i64>>, less<>> pq;
  for (int i = 0; i < n; ++i) {
    pq.push({a[i], 1});
  }
  while (k > 0) {
    auto [val, count] = pq.top();
    pq.pop();
    if (k > count) {
      pq.push({val / 2.0, count * 2});
      k -= count;
    } else {
      i64 c1 = k;
      i64 c2 = count-k;
      pq.push({val, c2});
      pq.push({val / 2.0, c1 * 2});
      k = 0;
    }
  }

  map<double,i64> value_count;
  while (!pq.empty()) {
    auto [val, count] = pq.top();
    pq.pop();
    value_count[val] += count;
  }

  vector<pair<double,i64>> p(value_count.begin(), value_count.end());
  int size = p.size();
  for (int i = size-2; i >= 0; --i) {
    p[i].second += p[i+1].second;
  }

  // for (auto [len, c] : p) {
  //   cout << "len=" << len << ", count=" << c << endl;
  // }

  auto find_xth = [&]() {
    int l = 0, r = size-1;
    double ans = p.back().first;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      i64 total_count = p[mid].second;
      if (total_count >= x) {
        ans = p[mid].first;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    return ans;
  };

  double ans = find_xth();
  cout << fixed << setprecision(12) << ans << endl;
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

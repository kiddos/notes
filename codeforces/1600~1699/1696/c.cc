#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int k = 0;
  cin >> k;
  vector<i64> b(k);
  for (int i = 0; i < k; ++i) cin >> b[i];

  i64 sum1 = accumulate(a.begin(), a.end(), 0LL);
  i64 sum2 = accumulate(b.begin(), b.end(), 0LL);
  if (sum1 != sum2) {
    cout << "NO" << endl;
    return;
  }

  auto decompose = [&](vector<i64>& arr) {
    vector<pair<i64,i64>> nums;
    for (int i = 0; i < arr.size(); ++i) {
      i64 x = arr[i];
      i64 count = 1;
      while (x % m == 0) {
        x /= m;
        count *= m;
      }

      if (!nums.empty() && nums.back().first == x) {
        nums.back().second += count;
      } else {
        nums.push_back({x, count});
      }
    }
    return nums;
  };

  vector<pair<i64,i64>> c = decompose(a);
  vector<pair<i64,i64>> d = decompose(b);

  if (c == d) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<i64> prefix_b = b;
  for (int i = 1; i < n; ++i) {
    prefix_b[i] += prefix_b[i-1];
  }
  map<i64,int> count_a;
  for (int i = 0; i < n; ++i) {
    count_a[a[i]]++;
  }

  auto find_total_completed = [&](int c) -> int {
    int l = 0, r = n-1;
    int ans = 0;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (prefix_b[mid] <= c) {
        l = mid+1;
        ans = mid+1;
      } else {
        r = mid-1;
      }
    }
    return ans;
  };

  int count = n;
  i64 ans = 0;
  for (auto [ai, c] : count_a) {
    i64 level = find_total_completed(count);
    i64 score = ai * level;
    ans = max(ans, score);

    count -= c;
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

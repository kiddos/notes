#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int max_val = *max_element(a.begin(), a.end());
  vector<int> count(max_val+1);
  pair<int,int> max_count = {0, 0};
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
    max_count = max(max_count, {count[a[i]], a[i]});
  }
  int total_sum = accumulate(a.begin(), a.end(), 0);
  int rest = n - max_count.first;
  int ans = 0;
  if (max_count.first >= rest) {
    int take = min(rest+2, max_count.first);
    ans = take * max_count.second + (total_sum - max_count.first * max_count.second);
  } else {
    ans = total_sum;
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

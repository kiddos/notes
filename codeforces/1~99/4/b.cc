#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int d = 0, sum_time = 0;
  cin >> d >> sum_time;
  vector<int> min_time(d), max_time(d);
  for (int i = 0; i < d; ++i) {
    cin >> min_time[i] >> max_time[i];
  }

  int total = accumulate(min_time.begin(), min_time.end(), 0);
  if (total > sum_time) {
    cout << "NO" << endl;
    return;
  }

  int left = sum_time - total;
  vector<int> ans = min_time;
  for (int i = 0; i < d; ++i) {
    int extra = min(left, max_time[i] - min_time[i]);
    ans[i] += extra;
    left -= extra;
  }

  if (left > 0) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  for (int i = 0; i < d; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

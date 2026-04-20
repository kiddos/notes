#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, m = 0;
  cin >> n >> m;

  i64 large_group = n - (m-1);
  i64 k_max = (large_group - 1) * large_group / 2;

  i64 min_size_group = n / m;
  i64 extra_group_count = n - n / m * m;
  i64 min_size_group_count = m - extra_group_count;
  i64 k_min = (min_size_group - 1) * min_size_group / 2 * min_size_group_count +
    (min_size_group + 1) * min_size_group / 2 * extra_group_count;
  cout << k_min << " " << k_max << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

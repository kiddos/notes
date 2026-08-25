#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool in_range(int x, int l, int r) {
  return x >= l && x <= r;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> l(n), r(n), u(n), v(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i] >> u[i] >> v[i];
  }

  auto possible = [&](int rank) -> bool {
    int added = 0;
    // cout << "rank=" << rank << endl;
    for (int i = 0; i < n; ++i) {
      int left_rank = added + 1;
      int right_rank = rank - added;
      // cout << left_rank << " " << right_rank << endl;
      if (!in_range(left_rank, l[i], r[i]) && !in_range(right_rank, u[i], v[i])) {
        added++;
      }
      if (added == rank) {
        return true;
      }
    }
    return false;
  };

  for (int rank = n; rank >= 1; --rank) {
    if (possible(rank)) {
      cout << rank << endl;
      return;
    }
  }
  cout << "0" << endl;
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

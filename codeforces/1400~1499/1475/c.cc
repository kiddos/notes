#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int A = 0, B = 0, k = 0;
  cin >> A >> B >> k;
  vector<int> a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }
  vector<int> b(k);
  for (int i = 0; i < k; ++i) {
    cin >> b[i];
  }

  map<int, vector<int>> group;
  for (int i = 0; i < k; ++i) {
    group[a[i]].push_back(b[i]);
  }

  vector<int> totals(B+1);
  i64 current_total = 0;
  i64 ans = 0;
  for (auto [ai, bs] : group) {
    for (int bi : bs) {
      i64 total = current_total - totals[bi];
      ans += total;
    }

    for (int bi : bs) {
      totals[bi]++;
    }
    current_total += bs.size();
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

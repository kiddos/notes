#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int j = 0; j < m; ++j) {
    cin >> b[j];
  }

  vector<int> masks;
  int mask_size = 1 <<m;
  for (int mask = 0; mask < mask_size; ++mask) {
    int x = ~0;
    for (int j = 0; j < m; ++j) {
      if (mask & (1<<j)) {
        x = x & b[j];
      }
    }
    masks.push_back(x);
  }

  vector<int> changes;
  for (int i = 0; i < n; ++i) {
    vector<int> ops(m+1);
    for (int j = 1; j < mask_size; ++j) {
      int x = a[i] & masks[j];
      int bit_count = bitset<10>(j).count();
      ops[bit_count] = max(ops[bit_count], a[i] - x);
    }
    for (int i = 1; i <= m; ++i) {
      int change = ops[i] - ops[i-1];
      changes.push_back(change);
    }
  }

  i64 ans = accumulate(a.begin(), a.end(), 0LL);
  sort(changes.begin(), changes.end());
  for (int t = 0; t < k && !changes.empty(); ++t) {
    int change = changes.back();
    changes.pop_back();
    ans -= change;
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 C2(i64 n) {
  return n * (n-1) / 2;
}

void solve() {
  i64 n = 0, b = 0, x = 0;
  cin >> n >> b >> x;
  vector<i64> c(n);
  for (int i = 0; i < n; ++i) cin >> c[i];

  i64 max_squad = *max_element(c.begin(), c.end());
  i64 ans = 0;
  map<int, vector<i64>> counts;
  for (int race = 0; race < n; ++race) {
    vector<i64> count;
    for (int k = 2; k <= c[race]; ++k) {
      i64 y = c[race] / k;
      i64 y_prime = (c[race] + k - 1) / k;
      i64 size2 = c[race] % k;
      i64 size1 = k - size2;
      i64 total = C2(size1) * y * y +
        C2(size2) * y_prime * y_prime +
        size2 * size1 * y * y_prime;
      count.push_back(total);
    }
    count.push_back(C2(c[race]));

    reverse(count.begin(), count.end());
    counts[race] = std::move(count);
  }

  i64 total_count = 0;
  map<int,i64> last;
  for (int k = 2; k <= max_squad; ++k) {
    vector<int> empty;
    for (auto& [race, c] : counts) {
      total_count += c.back();
      total_count -= last[race];
      last[race] = c.back();
      c.pop_back();
      if (c.empty()) {
        empty.push_back(race);
      }
    }
    for (int r : empty) counts.erase(r);

    i64 strength = total_count * b - (k-1) * x;
    ans = max(ans, strength);
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  mt19937_64 gen((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
  vector<i64> table(n);
  set<i64> found;
  for (int i = 0; i < n; ++i) {
    i64 x = gen();
    while (found.count(x)) {
      x = gen();
    }
    table[i] = x;
    found.insert(x);
  }

  vector<pair<i64, int>> hashes;
  for (int j = 0; j < m; ++j) {
    i64 h = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i][j] == '1') {
        h ^= table[i];
      }
    }
    for (int i = 0; i < n; ++i) {
      // this means perform the op on all other row on this col with 1
      // except this row i
      hashes.emplace_back(h ^ table[i], i * m + j);
    }
  }

  int max_count = 0;
  map<i64, int> hash_count;
  for (auto& [h, idx] : hashes) {
    max_count = max(max_count, ++hash_count[h]);
  }

  string ans(n, '0');
  for (auto& [h, idx] : hashes) {
    if (hash_count[h] == max_count) {
      int r = idx / m;
      int c = idx % m;
      if (s[r][c] == '0') {
        ans[r] = '1';
        for (int i = 0; i < n; ++i) {
          if (s[i][c] == '1') {
              ans[i] = '1';
          }
        }
      } else if (s[r][c] == '1') {
        for (int i = 0; i < n; ++i) {
          if (s[i][c] == '1' && i != r) {
            ans[i] = '1';
          }
        }
      }
      break;
    }
  }
  cout << max_count << endl;
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

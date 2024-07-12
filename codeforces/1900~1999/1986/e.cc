#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  map<int, vector<int>> groups;
  for (int i = 0; i < n; ++i) {
    groups[a[i] % k].push_back(a[i]);
  }

  int odd_size = 0;
  for (auto& [m, list] : groups) {
    sort(list.begin(), list.end());
    odd_size += list.size() % 2;
  }

  if (odd_size > 1) {
    cout << "-1" << endl;
    return;
  }

  i64 ans = 0;
  for (auto& [m, list] : groups) {
    if (list.size() % 2 == 1) {
      int size = list.size();
      vector<i64> suffix(size + 1);
      for (int i = size-2; i >= 0; i -= 2) {
        suffix[i] = suffix[i+2] + (list[i+1] - list[i]) / k;
      }
      i64 prefix = 0;
      i64 best = numeric_limits<i64>::max();
      for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
          i64 sum = prefix + suffix[i+1];
          best = min(best, sum);
        } else {
          i64 sum = prefix;
          if (i+1 < size) {
            sum += (list[i+1] - list[i-1]) / k;
          }
          if (i+2 <= size) {
            sum += suffix[i+2];
          }
          best = min(best, sum);

          prefix += (list[i] - list[i-1]) / k;
        }
      }
      ans += best;
    } else {
      for (int i = 1; i < (int)list.size(); i += 2) {
        ans += (list[i] - list[i-1]) / k;
      }
    }
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

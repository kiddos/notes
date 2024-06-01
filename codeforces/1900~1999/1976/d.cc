#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> levels(n);
  int l = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      l++;
    } else if (s[i] == ')') {
      l--;
    }
    levels[i] = l;
  }

  map<int,int> level_count;
  i64 ans = 0;
  for (int l = 0; l < n; ++l) {
    int b = levels[l];
    ans += level_count[b];
    level_count[b]++;
    while (!level_count.empty()) {
      int x = level_count.begin()->first;
      if (x >= levels[l] - x) {
        break;
      }
      level_count.erase(level_count.begin());
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

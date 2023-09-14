#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  map<int,int> x;
  for (int i = 0; i < n; ++i) {
    int a = 0;
    cin >> a;
    x[a]++;
  }

  int last = -1;
  int current = 0;
  pair<int,int> ans = {-1, -2};
  for (auto& [a, count] : x) {
    if (count >= k) {
      if (a == last+1) {
        current++;
      } else {
        current = 1;
      }

      int len = ans.second - ans.first + 1;
      if (current > len) {
        ans = {a-current+1, a};
      }

      last = a;
    }
  }

  if (ans.first == -1) {
    cout << "-1" << endl;
  } else {
    cout << ans.first << " " << ans.second << endl;
  }
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

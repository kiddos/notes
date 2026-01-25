#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<i64> x(4);
  for (int i = 0; i < 4; ++i) {
    cin >> x[i];
  }
  i64 total = accumulate(x.begin(), x.end(), 0LL);
  for (int i = 0; i < 4; ++i) {
    i64 rest = total - x[i];
    if (rest == x[i] * 2) {
      vector<i64> ans;
      for (int j = 0; j < 4; ++j) {
        if (j != i) {
          ans.push_back(x[i] - x[j]);
        }
      }
      for (i64 result : ans) {
        cout << result << " ";
      }
      cout << endl;
      return;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

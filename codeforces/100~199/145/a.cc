#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string a, b;
  cin >> a >> b;
  int n = a.length();
  vector<int> count(2);
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      if (a[i] == '4') {
        count[0]++;
      } else if (a[i] == '7') {
        count[1]++;
      }
    }
  }

  int swap2 = min(count[0], count[1]);
  count[0] -= swap2;
  count[1] -= swap2;
  int ans = swap2 + max(count[0], count[1]);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

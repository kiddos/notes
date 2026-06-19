#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


// 0 -> 0, 8
// 1 -> 1, 0, 3, 4, 7, 8, 9
// 2 -> 2, 8
// 3 -> 3, 8, 9
// 4 -> 4, 8, 9
// 5 -> 5, 6, 8, 9
// 6 -> 6, 8
// 7 -> 7, 0, 3, 8, 9
// 8 -> 8
// 9 -> 9, 8

void solve() {
  string s;
  cin >> s;
  int ans = 1;
  vector<int> different = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
  for (char ch : s) {
    int d = ch - '0';
    ans *= different[d];
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

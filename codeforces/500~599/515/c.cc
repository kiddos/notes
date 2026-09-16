#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 2 -> 2
// 3 -> 3
// 4 -> 3, 2, 2
// 5 -> 5
// 6 -> 6 -> 3, 5
// 7 -> 7
// 8 -> 7, 2, 2, 2
// 9 -> 9 * 8 * 7 * 6 * 5  * 4 * 3 -> 3, 3, 2, 7

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  string ans;
  for (char ch : s) {
    if (ch == '2') {
      ans.push_back('2');
    } else if (ch == '3') {
      ans.push_back('3');
    } else if (ch == '4') {
      ans += "322";
    } else if (ch == '5') {
      ans.push_back('5');
    } else if (ch == '6') {
      ans += "53";
    } else if (ch == '7') {
      ans.push_back('7');
    } else if (ch == '8') {
      ans += "7222";
    } else if (ch == '9') {
      ans += "7332";
    }
  }
  sort(ans.rbegin(), ans.rend());
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

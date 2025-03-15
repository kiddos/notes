#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int time_to_zero(i64 x, const string& command) {
  int n = command.length();
  for (int i = 0; i < n; ++i) {
    if (command[i] == 'L') {
      x--;
    } else if (command[i] == 'R') {
      x++;
    }
    if (x == 0) {
      return i+1;
    }
  }
  return -1;
}

void solve() {
  int n = 0;
  i64 x = 0, k = 0;
  cin >> n >> x >> k;
  string s;
  cin >> s;

  int first_to_zero = time_to_zero(x, s);
  if (first_to_zero < 0 || k < first_to_zero) {
    cout << "0" << endl;
    return;
  }

  k -= first_to_zero;
  i64 ans = 1;
  int first_to_reset = time_to_zero(0, s);
  if (first_to_reset > 0) {
    ans += k / first_to_reset;
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

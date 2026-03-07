#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool check(int n) {
  if (n % 9 == 0) {
    for (int i = 0; i <= 100; ++i) {
      int sum = n + i;
      string s = to_string(sum);
      for (char ch : s) {
        sum -= ch - '0';
      }
      if (sum == n) {
        return true;
      }
    }
    return false;
  } else {
    return false;
  }
}

void solve() {
  int n = 0;
  cin >> n;

  if (check(n)) {
    cout << "10" << endl;
  } else {
    cout << "0" << endl;
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

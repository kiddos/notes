#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_prime(int x) {
  int s = sqrt(x);
  for (int d = 2; d <= s; ++d) {
    if (x % d == 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      int value = (s[i] - '0') * 10 + s[j] - '0';
      if (is_prime(value)) {
        cout << value << endl;
        return;
      }
    }
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

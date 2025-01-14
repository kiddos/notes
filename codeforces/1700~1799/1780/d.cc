#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int subtract(int x) {
  cout << "- " << x << endl;
  int cnt = 0;
  cin >> cnt;
  return cnt;
}

void answer(int x) {
  cout << "! " << x << endl;
}

void solve() {
  int n = 0;
  cin >> n;

  int ans = 0;
  while (n > 0) {
    int x = 1 << (n-1);
    int n2 = subtract(x);
    if (n2 == n-1) {
      // (n-1) bit is 1
      ans |= (1 << (n-1));
      n = n2;
    } else {
      int extra_bit = n2 - n;
      // n + extra_bit is 1
      ans |= (1 << (n+extra_bit));
      int x2 = (1 << (n+extra_bit)) - (1<<(n-1));
      n = subtract(x2);
    }
  }

  answer(ans);
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

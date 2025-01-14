#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_power_2(int n, int& step) {
  while (n % 2 == 0) {
    n /= 2;
    step++;
  }
  return n == 1;
}

void solve() {
  int n = 0;
  cin >> n;
  int step = 0;
  if (n == 1) {
    cout << "Bob" << endl;
  } else if (is_power_2(n, step)) {
    if (step % 2 == 0) {
      cout << "Alice" << endl;
    } else {
      cout << "Bob" << endl;
    }
  } else {
    if (n % 2 == 1) {
      cout << "Bob" << endl;
    } else {
      cout << "Alice" << endl;
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

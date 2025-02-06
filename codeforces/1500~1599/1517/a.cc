#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<i64> numbers;

void precompute() {
  i64 x = 2050;
  while (x <= 1e18) {
    numbers.push_back(x);
    x *= 10;
  }
}

void solve() {
  i64 n = 0;
  cin >> n;
  int size = numbers.size();
  int ans = 0;
  for (int i = size-1; i >= 0; --i) {
    while (n >= numbers[i]) {
      n -= numbers[i];
      ans++;
    }
  }

  if (n == 0) {
    cout << ans << endl;
  } else {
    cout << "-1" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}

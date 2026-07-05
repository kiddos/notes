#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


// x = (-b + sqrt(b * b - 4 * a * c))

int digit_sum(i64 x) {
  int ans = 0;
  while (x > 0) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}

void solve() {
  i64 n = 0;
  cin >> n;
  for (int b = 1; b <= 90; ++b) {
    i64 square = b * b + 4 * n;
    i64 sq = sqrt(square);
    if (sq * sq == square) {
      i64 sum = -b + sq;
      if (sum >= 0 && sum % 2 == 0) {
        i64 x = sum / 2;
        int d = digit_sum(x);
        if (d == b) {
          cout << sum / 2 << endl;
          return;
        }
      }
    }
  }
  cout << "-1" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

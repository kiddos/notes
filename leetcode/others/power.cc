#include <bits/stdc++.h>

using namespace std;

class Solution1 {
 public:
  double myPow(double a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b == -1) return 1.0 / a;
    double x = myPow(a, b/2);
    return x * x * myPow(a, b % 2);
  }
};

class Solution2 {
 public:
  double myPow(double a, int b) {
    double result = 1;
    long c = b;
    while (abs(c) > 0) {
      if (c % 2 == 1) result *= a;
      if (c % 2 == -1) result /= a;
      a *= a;
      c /= 2;
    }
    return result;
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    double a = 0;
    int b = 0;
    cin >> a >> b;
    double ans = Solution1().myPow(a, b);
    cout << "mine: " << ans << endl;
    ans = Solution2().myPow(a, b);
    cout << "mine: " << ans << endl;
    cout << "real: " << pow(a, b) << endl;
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    string s = to_string(n);
    int k = s.length();
    int a = 0, b = 0;
    int da = 0, db = 0;
    for (int i = 0; i < k; ++i) {
      int d = s[i] - '0';
      a *= 10;
      b *= 10;
      if (d % 2 == 0) {
        a += d / 2;
        b += d / 2;
        da += d / 2;
        db += d / 2;
      } else {
        if (da > db) {
          a += d / 2;
          b += d / 2 + 1;
          da += d / 2;
          db += d / 2 + 1;
        } else {
          a += d / 2 + 1;
          b += d / 2;
          da += d / 2 + 1;
          db += d / 2;
        }
      }
    }
    cout << a << " " << b << endl;
  }
  return 0;
}

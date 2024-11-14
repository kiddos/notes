#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  int add = 0, sub = 0;
  for (int i = 0; i < n; ++i) {
    add += s[i] == '+';
    sub += s[i] == '-';
  }

  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    i64 a = 0, b = 0;
    cin >> a >> b;
    i64 g = gcd(a, b);
    a /= g;
    b /= g;

    if (a == b) {
      if (add == sub) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      // ax + c = add
      // bx + c = sub
      // x = (add - sub) / (a - b)
      i64 d1 = a - b, d2 = add - sub;
      if (d2 % d1 == 0) {
        i64 x = (add - sub) / (a - b);
        if (x > 0) {
          i64 c = add - a * x;
          if (c >= 0) {
            cout << "YES" << endl;
          } else {
            cout << "NO" << endl;
          }
        } else {
          // bx + c = add
          // ax + c = sub
          x = (add - sub) / (b - a);
          i64 c = add - b * x;
          if (c >= 0) {
            cout << "YES" << endl;
          } else {
            cout << "NO" << endl;
          }
        }
      } else {
        cout << "NO" << endl;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

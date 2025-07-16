#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int q = 0, d = 0;
  cin >> q >> d;

  vector<int> multiples(10);
  for (int m = 1; m <= 10; ++m) {
    int k = d * m;
    if (!multiples[k%10]) {
      multiples[k%10] = k;
    }
  }

  vector<int> a(q);
  for (int i = 0; i < q; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < q; ++i) {
    int last_digit = a[i] % 10;
    if (!multiples[last_digit]) {
      if (a[i] >= d * 10 + last_digit) {
        int extra = a[i] - d * 10 + last_digit;
        if (extra % d == 0) {
          cout << "YES" << endl;
        } else {
          if (a[i] >= d * 10) {
            cout << "YES" << endl;
          } else {
            cout << "NO" << endl;
          }
        }
      } else {
        cout << "NO" << endl;
      }
    } else {
      int left = a[i] - multiples[last_digit];
      if (left >= 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
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

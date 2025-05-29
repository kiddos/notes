#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0, k = 0;
  cin >> a >> b >> k;

  string x, y;
  if (a < k) {
    if (b <= 2) {
      cout << "No" << endl;
      return;
    }
    int max_ones = a + b-2;
    if (k > max_ones || a == 0) {
      cout << "No" << endl;
      return;
    }
    // 11111000
    // 10111001

    y.push_back('1');
    for (int i = 0; i < a; ++i) {
      x.push_back('0');
      y.push_back('0');
    }
    x.push_back('1');
    y.back() = '1';

    int left = k-a;
    for (int i = 0; i < left-1; ++i) {
      x.push_back('1');
      y.push_back('1');
    }
    x.push_back('1');
    y.push_back('0');
    for (int i = 0; i < b-1-left; ++i) {
      x.push_back('1');
      y.push_back('1');
    }
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
  } else {
    if (b == 1) {
      if (k == 0) {
        int len = a + b;
        x = string(len, '0');
        y = string(len, '0');
        x[0] = '1';
        y[0] = '1';
      } else {
        cout << "No" << endl;
        return;
      }
    } else {
      y.push_back('1');
      for (int i = 0; i < k; ++i) {
        x.push_back('0');
        y.push_back('0');
      }
      x.push_back('1');
      int zeros_left = a-k;
      for (int i = 0; i < zeros_left; ++i) {
        x.push_back('0');
        y.push_back('0');
      }
      int ones_left = b-1;
      for (int i = 0; i < ones_left; ++i) {
        x.push_back('1');
        y.push_back('1');
      }
      reverse(x.begin(), x.end());
      reverse(y.begin(), y.end());
    }
  }

  cout << "Yes" << endl;
  cout << x << endl;
  cout << y << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

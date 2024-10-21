#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string x;
  cin >> x;

  string a, b;

  bool not_same = false;
  for (int i = 0; i < n; ++i) {
    if (not_same) {
      if (x[i] == '0') {
        a.push_back('0');
        b.push_back('0');
      } else if (x[i] == '2') {
        a.push_back('0');
        b.push_back('2');
      } else if (x[i] == '1') {
        a.push_back('0');
        b.push_back('1');
      }
    } else {
      if (x[i] == '0') {
        a.push_back('0');
        b.push_back('0');
      } else if (x[i] == '2') {
        a.push_back('1');
        b.push_back('1');
      } else if (x[i] == '1') {
        not_same = true;
        a.push_back('1');
        b.push_back('0');
      }
    }
  }
  cout << a << endl;
  cout << b << endl;
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

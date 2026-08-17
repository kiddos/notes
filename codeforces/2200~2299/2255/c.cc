#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve_first() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  int rx = 0, cx = 0;
  cin >> rx >> cx;
  vector<int> x = {rx-1, cx-1};

  // try to make the center of black be x
  // delta = w * x - sum of (r, c) for all black cell
  // if this delta is 0, we swap a cell with itself
  // else find a black cell p with p + delta being white

  vector<int> sum(2);
  int w = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == '#') {
        sum[0] += i;
        sum[1] += j;
        w++;
      }
    }
  }

  vector<int> delta(2);
  for (int d = 0; d < 2; ++d) {
    delta[d] = (w * x[d]) % n;
    delta[d] -= sum[d] % n;
    delta[d] %= n;
    delta[d] += n;
    delta[d] %= n;
  }

  if (delta[0] == 0 && delta[1] == 0) {
    cout << "1 1 1 1" << endl;
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (s[i][j] == '#') {
          int i2 = (i + delta[0]) % n;
          int j2 = (j + delta[1]) % n;
          if (s[i2][j2] == '.') {
            cout << i+1 << " " << j+1 << " " << i2+1 << " " << j2+1 << endl;
            return;
          }
        }
      }
    }

    assert(false);
  }
}

void first() {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve_first();
  }
}

int extended_euclid(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  int x1 = 0, y1 = 0;
  int g = extended_euclid(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}

int mod_div(int a, int b, int m) {
  int x = 0, y = 0;
  int g = extended_euclid(b, m, x, y);
  if (g != 1) {
    return -1;
  } else {
    int inv_b = (x % m + m) % m;
    return (a * inv_b) % m;
  }
}

void solve_second() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  vector<int> sum(2);
  int w = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == '#') {
        sum[0] += i;
        sum[1] += j;
        w++;
      }
    }
  }

  vector<int> center = {mod_div(sum[0] % n, w, n), mod_div(sum[1] % n, w, n)};
  cout << center[0]+1 << " " << center[1]+1 << endl;
}

void second() {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve_second();
  }
}

void solve() {
  string s;
  cin >> s;
  if (s == "first") {
    first();
  } else if (s == "second") {
    second();
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

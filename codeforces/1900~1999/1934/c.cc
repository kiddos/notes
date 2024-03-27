#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// (x-1) + (y-1) = d1
// => (x+y) = d1 + 2
// (n-x) + (y-1) = d2
// => (y-x) = d2 - n + 1 
// => 2*y = d1 + 2 + d2 - n + 1
// => y = (d1 + d2 - n + 3) / 2
// => x = d1 + 2 - y

// (x-1) + (m-y) = d3
// => (x-y) = d3 - m + 1
// => 2*x = d1 + 2 + d3 - m + 1
// => x = (d1 + d3 - m + 3) / 2
// => y = d1 + 2 - x

int query(int x, int y) {
  cout << "? " << x << " " << y << endl;
  int d = 0;
  cin >> d;
  return d;
}

void answer(int x, int y) {
  cout << "! " << x << " " << y << endl;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  int d1 = query(1, 1);
  int d2 = query(n, 1);
  int d3 = query(1, m);

  int y1 = (d1 + d2 - n + 3) / 2;
  int x1 = d1 + 2 - y1;
  int x2 = (d1 + d3 - m + 3) / 2;
  int y2 = d1 + 2 - x2;

  if (x1 <= 0 || x1 > n || y1 <= 0 || y1 > m) {
    answer(x2, y2);
  } else {
    int d4 = query(x1, y1);
    if (d4 == 0) {
      answer(x1, y1);
    } else {
      answer(x2, y2);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
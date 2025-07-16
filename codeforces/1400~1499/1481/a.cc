#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int px = 0, py = 0;
  cin >> px >> py;
  string s;
  cin >> s;

  int u = 0, d = 0, r = 0, l = 0;
  if (px > 0) {
    r = px;
  } else if (px < 0) {
    l = -px;
  }
  if (py > 0) {
    u = py;
  } else if (py < 0) {
    d = -py;
  }

  int U = std::count_if(s.begin(), s.end(), [](char c ) { return c == 'U'; });
  int D = std::count_if(s.begin(), s.end(), [](char c ) { return c == 'D'; });
  int R = std::count_if(s.begin(), s.end(), [](char c ) { return c == 'R'; });
  int L = std::count_if(s.begin(), s.end(), [](char c ) { return c == 'L'; });
  if (U >= u && D >= d && R >= r && L >= l) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr i64 MAX_X = 1e12;

vector<i64> cubes;
set<i64> s;

void precompute() {
  for (i64 i = 1; i*i*i <= MAX_X; ++i) {
    cubes.push_back(i * i * i);
  }
  s = set<i64>(cubes.begin(), cubes.end());
}

void solve() {
  i64 x = 0;
  cin >> x;
  for (i64 a : cubes) {
    i64 b = x - a;
    if (b <= 0) {
      break;
    }
    if (s.count(b)) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}

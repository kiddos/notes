#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, a = 0, b = 0, c = 0, d = 0;
  cin >> n >> a >> b >> c >> d;
  pair<int,int> r1 = {(a-b) * n, (a+b) * n};
  pair<int,int> r2 = {(c-d), (c+d)};
  pair<int,int> r3 = {max(r1.first, r2.first), min(r1.second, r2.second)};
  if (r3.first <= r3.second) {
    cout << "Yes" << endl;
  } else{
    cout << "No" << endl;
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

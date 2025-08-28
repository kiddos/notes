#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int cross(array<i64,2>& a, array<i64,2>& b) {
  return a[0] * b[1] - a[1] * b[0];
}

bool is_parallel(array<i64,2>& a, array<i64,2>& b) {
  return cross(a, b) == 0;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> x(n), y(n), u(n), v(n);
  for (int i = 0; i < n; ++i) {
    cin  >> x[i] >> y[i] >> u[i] >> v[i];
  }

  vector<array<i64,2>> vecs;
  for (int i = 0; i < n; ++i) {
    array<i64, 2> a = {x[i] - u[i], y[i] - v[i]};
    i64 g = gcd(abs(a[0]), abs(a[1]));
    a[0] /= g;
    a[1] /= g;
    vecs.push_back(a);
  }

  i64 ans = 0;
  // for (int i = 0; i < n; ++i) {
  //   for (int j = i+1; j < n; ++j) {
  //     if (is_parallel(vecs[i], vecs[j]) && vecs[i] != vecs[j]) {
  //       ans++;
  //     }
  //   }
  // }
  map<array<i64,2>, i64> count;
  for (int i = 0; i < n; ++i) {
    array<i64,2> t = {-vecs[i][0], -vecs[i][1]};
    if (count.count(t)) {
      ans += count[t];
    }
    count[vecs[i]]++;
  }
  cout << ans << endl;
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

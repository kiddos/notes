#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  i64 a = 0, b = 0, c = 0, d = 0, e = 0;
  cin >> a >> b >> c >> d >> e;
  vector<i64> points = {a, b, c, d, e};
  i64 current = 0;
  vector<i64> total(5);
  for (int i = 0; i < n; ++i) {
    current += p[i];
    for (int j = 4; j >= 0; --j) {
      total[j] += current / points[j];
      current %= points[j];
    }
  }

  for (int i = 0; i < 5; ++i) {
    cout << total[i] << " ";
  }
  cout << endl;
  cout << current << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

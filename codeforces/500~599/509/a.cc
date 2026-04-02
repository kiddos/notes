#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n, 1);
  for (int i = 1; i < n; ++i) {
    vector<i64> a2(n, 1);
    for (int j = 1; j < n; ++j) {
      a2[j] = a2[j-1] + a[j];
    }
    a = std::move(a2);
  }
  cout << a.back() << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

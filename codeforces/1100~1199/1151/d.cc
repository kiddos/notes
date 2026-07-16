#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<i64,i64>> p;
  for (int i = 0; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    p.push_back({a, b});
  }

  sort(p.begin(), p.end(), [&](auto& p1, auto& p2) {
    i64 first = p1.second + p2.first;
    i64 second = p2.second + p1.first;
    return first < second;
  });
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    auto [a, b] = p[i];
    ans += a * i + b * (n-i-1);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

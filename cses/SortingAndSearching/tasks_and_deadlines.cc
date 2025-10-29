#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> tasks;
  for (int i = 0; i < n; ++i) {
    int a = 0, d = 0;
    cin >> a >> d;
    tasks.emplace_back(a, d);
  }
  sort(tasks.begin(), tasks.end(), [&](auto& t1, auto& t2) {
    return t1.first < t2.first;
  });

  i64 t = 0;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    auto [a, d] = tasks[i];
    t += a;
    ans += d - t;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

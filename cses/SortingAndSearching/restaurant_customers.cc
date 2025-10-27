#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }

  map<int,int> line;
  for (int i = 0; i < n; ++i) {
    line[a[i]]++;
    line[b[i]+1]--;
  }

  int total_count = 0;
  int ans = 0;
  for (auto [ti, c] : line) {
    total_count += c;
    ans = max(ans, total_count);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

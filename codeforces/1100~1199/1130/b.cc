#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int m = 2 * n;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> position(n+1);
  position[0] = {0, 0};
  for (int i = 0; i < m; ++i) {
    position[a[i]].push_back(i);
  }

  i64 ans = 0;
  for (int i = 1; i <= n; ++i) {
    int move1 = abs(position[i][0] - position[i-1][0]) + abs(position[i][1] - position[i-1][1]); 
    int move2 = abs(position[i][1] - position[i-1][0]) + abs(position[i][0] - position[i-1][1]); 
    ans += min(move1, move2);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, a = 0, b = 0;
  cin >> n >> a >> b;

  vector<pair<int,int>> ans(n);
  int i = 0;
  int x = a, y = b;
  if (x == 0 && y > 0) {
    while (i < n && y > 0) {
      ans[i++].second = 1;
      y--;
    }
  } else if (y == 0 && x > 0) {
    while (i < n && x > 0) {
      ans[i++].first = 1;
      x--;
    }
  } else if (x > 0 && y > 0){
    while (i < n-1 && x > 0) {
      ans[i++].first = 1;
      x--;
    }
    while (i < n && y > 0) {
      ans[i++].second = 1;
      y--;
    }
  }

  ans[0].first += x;
  ans.back().second += y;

  int draw = 0;
  for (int i = 0; i < n; ++i) {
    draw += ans[i].first == ans[i].second;
  }

  cout << draw << endl;
  for (auto [x, y] : ans) {
    cout << x << ":" << y << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

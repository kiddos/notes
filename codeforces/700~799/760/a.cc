#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int m = 0, d = 0;
  cin >> m >> d;
  vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int first_week = 7 - d + 1;
  int left = days[m-1] - first_week;
  int cols = (left + 6) / 7 + 1;
  cout << cols << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

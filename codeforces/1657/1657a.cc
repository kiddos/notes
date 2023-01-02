#include <bits/stdc++.h>

using namespace std;

int solve(int x, int y) {
  if (x == 0 && y == 0) return 0;
  int square = x * x + y * y;
  unordered_set<int> squares;
  for (int i = 1; i <= 100; ++i) squares.insert(i*i);
  if (squares.count(square)) return 1;
  return 2;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int x = 0, y= 0;
    cin >> x >> y;
    int ans = solve(x, y);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}

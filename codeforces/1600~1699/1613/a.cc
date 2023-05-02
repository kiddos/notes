#include <bits/stdc++.h>

using namespace std;

string solve(int x1, int p1, int x2, int p2) {
  while (x1 % 10 == 0) {
    x1 /= 10;
    p1++;
  }
  while (x2 % 10 == 0) {
    x2 /= 10;
    p2++;
  }
  int d1 = p1 + to_string(x1).length();
  int d2 = p2 + to_string(x2).length();
  if (d1 > d2) return ">";
  else if (d1 < d2) return "<";

  while (p1 < p2) {
    x2 *= 10;
    p2--;
  }
  while (p1 > p2) {
    x1 *= 10;
    p1--;
  }

  if (x1 == x2) return "=";
  else if (x1 > x2) return ">";
  else return "<";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int x1 = 0, p1 = 0, x2 = 0, p2 = 0;
    cin >> x1 >> p1 >> x2 >> p2;
    string ans = solve(x1, p1, x2, p2);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}

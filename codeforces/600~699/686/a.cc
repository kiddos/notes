#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 x = 0;
  cin >> n >> x;
  i64 distress = 0;
  for (int i = 0; i < n; ++i) {
    char ch = '\0';
    int d = 0;
    cin >> ch >> d;
    if (ch == '+') {
      x += d;
    } else {
      if (x >= d) {
        x -= d;
      } else {
        distress++;
      }
    }
  }
  cout << x << " " << distress << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

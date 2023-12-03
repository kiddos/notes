#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

double dist(int x1, int y1, int x2, int y2) {
  int dx = x1 - x2;
  int dy = y1 - y2;
  return sqrt(dx * dx + dy * dy);
}

void solve() {
  int Px = 0, Py = 0;
  int Ax = 0, Ay = 0;
  int Bx = 0, By = 0;
  cin >> Px >> Py >> Ax >> Ay >> Bx >> By;

  double AP = dist(Ax, Ay, Px, Py);
  double BP = dist(Bx, By, Px, Py);
  double AO = dist(Ax, Ay, 0, 0);
  double BO = dist(Bx, By, 0, 0);
  double AB = dist(Ax, Ay, Bx, By) / 2.0;

  // cout << AP << " " << BP << endl;
  // cout << AO << " " << BO << endl;
  // cout << AB << endl;
  if (AP <= BP && AO <= BO) {
    double ans = max(AO, AP);
    cout << setprecision(9) << ans << endl;
  } else if (BP <= AP && BO <= AO) {
    double ans = max(BO, BP);
    cout << setprecision(9) << ans << endl;
  } else {
    double ans = max({min(AO, BO), min(AP, BP), AB});
    cout << setprecision(9) << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}

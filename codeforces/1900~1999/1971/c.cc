#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define PI 3.14159265358979323846

vector<pair<double,double>> coord;

void precompute() {
  for (int i = 0; i < 12; ++i) {
    double t = i * 30 / 180.0 * PI;
    double x = sin(t), y = cos(t);
    coord.emplace_back(x, y);
  }
  coord.push_back(coord[0]);
}

pair<double, double> vec(const pair<double, double>& p1, const pair<double, double>& p2) {
  return {p1.first - p2.first, p1.second - p2.second};
}

double cross(const pair<double, double>& p1, const pair<double, double>& p2) {
  return p1.first * p2.second - p1.second * p2.first;
}

void solve() {
  int a = 0, b = 0, c = 0, d = 0;
  cin >> a >> b >> c >> d;

  auto A = coord[a], B = coord[b], C = coord[c], D = coord[d];
  auto AC = vec(A, C), BC = vec(B, C);
  auto AD = vec(A, D), BD = vec(B, D);
  if (cross(AC, BC) * cross(AD, BD) < 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}

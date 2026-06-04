#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
constexpr double PI = 3.14159265358979323846;

void solve() {
  i64 d = 0, h = 0, v = 0, e = 0;
  cin >> d >> h >> v >> e;
  double r = (double)d / 2.0;
  double increase_speed = r * r * PI * e;
  if (increase_speed >= v) {
    cout << "NO" << endl;
    return;
  }
  double decrease_speed = (double)v - increase_speed;
  double current_volume = r * r * PI * h;
  double time = current_volume / decrease_speed;
  cout << "YES" << endl;
  cout << fixed << setprecision(10) << time << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

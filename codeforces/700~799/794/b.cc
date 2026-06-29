#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, h = 0;
  cin >> n >> h;

  double total_area = (double)h / 2.0;
  double expected = total_area / n;
  vector<double> last = {0};
  for (int i = 1; i < n; ++i) {
    double l = last.back();
    double r = h;
    while (r-l >= 1e-10) {
      double mid = (l+r) / 2.0;
      double height = mid - last.back();
      double current_base = mid / h;
      double area = height * (current_base + last.back() / h) / 2.0;
      if (area <= expected) {
        l = mid;
      } else {
        r = mid;
      }
    }
    last.push_back(l);
  }

  for (int i = 1; i < (int)last.size(); ++i) {
    cout << fixed << setprecision(10) << last[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

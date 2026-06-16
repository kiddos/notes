#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_factors(int x) {
  vector<int> f;
  for (int d = 1; d*d <= x; ++d) {
    if (x % d == 0) {
      f.push_back(d);
      f.push_back(x / d);
    }
  }
  sort(f.begin(), f.end());
  f.resize(unique(f.begin(), f.end()) - f.begin());
  return f;
}

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;
  if (b > a) {
    cout << "0" << endl;
  } else if (b == a) {
    cout << "infinity" << endl;
  } else {
    int c = a - b;
    vector<int> factors = get_factors(c);
    int ans = 0;
    for (int f : factors) {
      if (f > b) {
        ans++;
      }
    }
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

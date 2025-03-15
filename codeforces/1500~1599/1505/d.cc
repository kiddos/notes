#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  vector<int> digits;
  while (n > 0) {
    digits.push_back(n % m);
    n /= m;
  }
  set<int> d(digits.begin(), digits.end());
  if (d.size() == digits.size()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

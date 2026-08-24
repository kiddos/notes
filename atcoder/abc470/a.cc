#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    if (i % 3 == 0) {
      cout << "Fizz" << endl;
    } else {
      cout << i << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

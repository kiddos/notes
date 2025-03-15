#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  while (n >= 10) {
    int n2 = 0;
    while (n > 0) {
      n2 += n % 10;
      n /= 10;
    }
    n = n2;
  }
  cout << n << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

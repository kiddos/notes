#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string r, b;
  cin >> r >> b;
  int balance = 0;
  for (int i = 0; i < n; ++i) {
    if (r[i] > b[i]) {
      balance++;
    } else if (b[i] > r[i]) {
      balance--;
    }
  }
  if (balance > 0) {
    cout << "RED" << endl;
  } else if (balance < 0) {
    cout << "BLUE" << endl;
  } else {
    cout << "EQUAL" << endl;
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

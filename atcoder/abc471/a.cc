#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int A = 0, B = 0;
  cin >> A >> B;
  if (A+B == 9 || A-B == 9 || A*B == 9 || (A % B == 0 && A / B == 9)) {
    cout << "Nine" << endl;
  } else {
    cout << "Nein" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

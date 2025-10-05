#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int neg = 0, zero = 0, pos = 0;
  for (int i = 0; i < n; ++i){
    int a = 0;
    cin >> a;
    if (a == -1) {
      neg++;
    } else if (a == 0) {
      zero++;
    } else if (a == 1) {
      pos++;
    }
  }

  if (zero == 0) {
    if (neg % 2 == 0) {
      cout << "0" << endl;
    } else {
      cout << "2" << endl;
    }
  } else {
    if (neg % 2 == 0) {
      cout << zero << endl;
    } else {
      cout << zero + 2 << endl;
    }
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

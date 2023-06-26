#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n = 0;
  cin >> n;
  if (n == 1) {
    cout << "2" << endl;
    return;
  } else if (n == 2) {
    cout << "1" << endl;
  } else if (n == 3) {
    cout << "1" << endl;
  } else {
    int k = n / 3;
    if (n % 3 == 0) {
      cout << k << endl;
    } else {
      cout << k+1 << endl;
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

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  ll even = 0, odd = 0;
  for (int i = 0; i < n; ++i) {
    int a = 0;
    cin >> a;
    if (a % 2 == 0) {
      even += a;
    } else {
      odd += a;
    }
  }

  if (even > odd) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n = 0, k = 0;
  cin >> n >> k;

  if (n % 2 == 0 || n % k == 0) {
    cout << "YES" << endl;
    return;
  }
  if (n > k && (n - k) % 2 == 0) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
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

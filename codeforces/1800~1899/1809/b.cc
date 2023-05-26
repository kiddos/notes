#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n = 0;
  cin >> n;
  ll s = sqrt(n);
  if (s * s < n) s++;

  cout << s - 1 << endl;
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

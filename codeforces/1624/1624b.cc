#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool solve(ll a, ll b, ll c) {
  ll target_a = 2 * b - c;
  if (target_a > 0 && target_a % a == 0) return true;

  if ((c-a) % 2 == 0) {
    ll target_b = (c - a) / 2 + a;
    if (target_b > 0 && target_b % b == 0) return true;
  }

  ll target_c = b + b - a;
  if (target_c > 0 && target_c % c == 0) return true;
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    bool ans = solve(a, b, c);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
  }
  cout << flush;
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n = 0;
  cin >> n;

  ll l = 1, r = n;
  ll turn = 1;
  while (l <= r) {
    ll m = l + (r-l) / 2;
    ll total = (m+1) * m / 2;
    if (total <= n) {
      turn = m;
      l = m+1;
    } else {
      r = m-1;
    }
  }

  int which = 1;
  ll alice_white = 0, alice_black = 0;
  ll bob_white = 0, bob_black = 0;
  ll total = 0;
  for (int i = 1; i <= turn; ++i) {
    int black = i / 2;
    int white = i / 2;
    total += i;
    n -= i;
    if (i % 2 == 1) {
      if (total % 2 == 1) {
        white++;
      } else {
        black++;
      }
    }

    if (which < 2) {
      alice_white += white;
      alice_black += black;
    } else {
      bob_white += white;
      bob_black += black;
    }
    which = (which+1) % 4;
  }

  if (n > 0) {
    int white = n / 2;
    int black = n / 2;
    total += n;
    if (n % 2 == 1) {
      if (total % 2 == 1) {
        white++;
      } else {
        black++;
      }
    }

    if (which < 2) {
      alice_white += white;
      alice_black += black;
    } else {
      bob_white += white;
      bob_black += black;
    }
  }
  cout << alice_white << " " << alice_black << " " << bob_white << " " << bob_black << endl;
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

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int q = 0;
  cin >> q;

  ll a_len = 0;
  ll b_len = 0;
  char smallest_a = 'a';
  char smallest_b = 'a';
  char biggest_a = 'a';
  char biggest_b = 'a';
  for (int i = 0; i < q; ++i) {
    ll d = 0, k = 0;
    string x;
    cin >> d >> k >> x;

    if (d == 1) {
      a_len += k * x.length();
      for (char ch : x) {
        smallest_a = min(smallest_a, ch);
        biggest_a = max(biggest_a, ch);
      }
    } else if (d == 2) {
      b_len += k * x.length();
      for (char ch : x) {
        smallest_b = min(smallest_b, ch);
        biggest_b = max(biggest_b, ch);
      }
    }

    if (a_len == 0 || smallest_a < biggest_b || (smallest_a == biggest_b && biggest_a == smallest_a && a_len < b_len)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
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

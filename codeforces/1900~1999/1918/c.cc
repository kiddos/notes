#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// if a = 1<<i, b = 1<<i
// if a = 0<<i, b = 0<<i
// it doesn't matter what x ith bit is
// if a = 1<<i, b = 0<<i
// we want x ith bit = 0
// if a = 0<<i, b = 1<<i
// we want x ith bit = 1

void solve() {
  i64 a = 0, b = 0, r = 0;
  cin >> a >> b >> r;

  constexpr int MAX_BITS = 63;
  vector<int> bits(MAX_BITS);
  for (int i = MAX_BITS-1; i >= 0; --i) {
    int ai = (a & (1LL<<i)) ? 1 : 0;
    int bi = (b & (1LL<<i)) ? 1 : 0;
    bits[i] = ai-bi;
  }

  int j = -1;
  i64 x = 0;
  for (int i = MAX_BITS-1; i >= 0; --i) {
    if (bits[i]) {
      if (j >= 0) {
        if (bits[j] < 0) {
          // make ith bit positive
          if (bits[i] < 0 && (x | (1LL<<i)) <= r) {
            bits[i] = -bits[i];
            x |= (1LL<<i);
          }
        } else {
          // make ith bit negative
          if (bits[i] > 0 && (x | (1LL<<i)) <= r) {
            bits[i] = -bits[i];
            x |= (1LL<<i);
          }
        }
      } else {
        j = i;
      }
    }
  }

  i64 ans = 0;
  for (int i = 0; i < 63; ++i) {
    ans += ((i64)bits[i] << i);
  }
  cout << abs(ans) << endl;
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

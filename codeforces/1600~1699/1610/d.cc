#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// count odd numbers first
// because if there is a odd number in the sequence it's good
//
// if there is only even numbers
// eg 2, 2, 4
// this is also good
// but why?
// if we look at the sum formula
// sum = (ai + aj) * bi / 2
//     = k * bi / 2
// so if bj is 2 * bi, or 4 * bi
// just need to randomly pick 2 bi to cancel 4 or 2 bi because of the k constant in front

constexpr int MAX_N = 200000;
constexpr int MOD = 1e9 + 7;
vector<i64> p2(MAX_N+1, 1);

void precompute() {
  for (int i = 1; i <= MAX_N; ++i) {
    p2[i] = p2[i-1] * 2;
    p2[i] %= MOD;
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> two_divisible(31);

  int even = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      even++;

      int p = 1;
      while (a[i] % (1LL << (p+1)) == 0) {
        p++;
      }
      two_divisible[p]++;
    }
  }

  i64 ans = (p2[n] - p2[even] + MOD) % MOD;
  int added = 0;
  for (int i = 1; i <= 30; ++i) {
    if (two_divisible[i] == 0) continue;

    added += two_divisible[i];
    i64 pick = p2[two_divisible[i]-1]-1;
    i64 larger = p2[even - added];
    ans += pick * larger;
    ans %= MOD;
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  solve();
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<i64> p3;
void precompute() {
  i64 p = 1;
  for (int i = 0; i <= 22; ++i) {
    p3.push_back(p);
    p *= 3;
  }
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  vector<int> coef;
  for (int x = 20; x >= 0; --x) {
    coef.push_back(n / p3[x]);
    n %= p3[x];
  }
  reverse(coef.begin(), coef.end());

  int total_deal = accumulate(coef.begin(), coef.end(), 0);
  if (total_deal > k) {
    cout << "-1" << endl;
    return;
  }

  i64 ans = 0;
  int extra_deal = k - total_deal;
  for (int x = coef.size()-1; x >= 0; --x) {
    if (x > 0) {
      int can_move = min(extra_deal / 2, coef[x]);
      extra_deal -= can_move * 2;
      coef[x] -= can_move;
      coef[x-1] += 3 * can_move;
    }
    i64 cost = p3[x+1] + (x > 0 ? x * p3[x-1] : 0);
    ans += coef[x] * cost;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}

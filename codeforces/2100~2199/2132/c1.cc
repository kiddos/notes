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
  int n = 0;
  cin >> n;
  
  i64 ans = 0;
  for (int x = 20; x >= 0; --x) {
    int count = n / p3[x];
    i64 cost = p3[x+1] + (x > 0 ? x * p3[x-1] : 0);
    ans += cost * count;
    n %= p3[x];
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

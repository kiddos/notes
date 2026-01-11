#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;
  k--;
  i64 odd_count = (n+1) / 2;
  if (k < odd_count) {
    cout << k*2 + 1 << endl;
  } else {
    k -= odd_count;
    cout << (k+1) * 2 << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

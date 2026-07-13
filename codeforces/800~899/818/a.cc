#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;
  i64 half = n / 2;
  i64 diplomas = half / (k+1);
  i64 certificate = diplomas * k;
  i64 not_winner = n - diplomas - certificate;
  cout << diplomas << " " << certificate << " " << not_winner << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

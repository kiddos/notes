#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll N = 0, M = 0;
  cin >> N >> M;
  if (N == 1 && M == 1) {
    cout << "0" << endl;
  } else if (M == 1) {
    cout << N-1 << endl;
  } else {
    cout << (M-1) * N << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

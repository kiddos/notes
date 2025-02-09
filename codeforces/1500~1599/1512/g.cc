#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_C = 10000000;
vector<i64> c(MAX_C+1, 1);
vector<int> cidx(MAX_C+1, -1);
void precompute() {
  for (int i = 2; i <= MAX_C; ++i) {
    for (int j = i; j <= MAX_C; j += i) {
      c[j] += i;
    }
  }
  for (int i = 1; i <= MAX_C; ++i) {
    if (c[i] <= MAX_C && cidx[c[i]] < 0) {
      cidx[c[i]] = i;
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;
  cout << cidx[n] << endl;
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

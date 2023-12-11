#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

vector<int> counts(30);

void precompute() {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int k = 0; k < 10; ++k) {
        counts[i+j+k]++;
      }
    }
  }
}

void solve() {
  string n;
  cin >> n;
  i64 ans = 1;
  for (char ch : n) {
    int c = ch - '0';
    ans *= counts[c];
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

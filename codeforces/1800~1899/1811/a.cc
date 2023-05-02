#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  char d = '\0';
  cin >> n >> d;
  string num;
  cin >> num;
  for (int i = 0; i < n; ++i) {
    if (d > num[i]) {
      cout << num.substr(0, i) + string(1, d) + num.substr(i) << endl;
      return;
    }
  }
  cout << num + string(1, d) << endl;
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<pair<int,int>> result;

void solve() {
  int n = 0;
  cin >> n;

  if (n == 2) {
    cout << "1 1" << endl;
    cout << "1 2" << endl;
  } else if (n == 3) {
    cout << "1 1" << endl;
    cout << "1 2" << endl;
    cout << "3 2" << endl;
  } else {
    cout << "1 1" << endl;
    cout << "1 2" << endl;
    for (int i = 3; i <= n; ++i) {
      cout << i << " " << i << endl;
    }
  }
  cout << endl;
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

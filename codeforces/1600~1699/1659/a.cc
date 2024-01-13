#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, r = 0, b = 0;
  cin >> n >> r >> b;
  int d = b+1;
  int row = r / d;
  int left = r - row * d;
  string ans;
  for (int i = 0; i < d; ++i) {
    int size = row;
    if (left > 0) {
      size++;
      left--;
    }
    ans += string(size, 'R');
    if (i != d-1) {
      ans.push_back('B');
    }
  }
  cout << ans << endl;
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

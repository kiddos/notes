#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(7);
  for (int i = 0; i < 7; ++i) {
    cin >> a[i];
  }
  int idx = 0;
  while (n > 0) {
    n -= a[idx%7];
    if (n <= 0) {
      cout << (idx%7)+1 << endl;
      return;
    }
    idx++;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

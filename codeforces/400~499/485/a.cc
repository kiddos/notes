#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, m = 0;
  cin >> a >> m;
  int x = a % m;
  vector<bool> found(m);
  while (!found[x]) {
    found[x] = true;
    int left = x % m;
    x += left;
    x %= m;
  }

  if (found[0]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

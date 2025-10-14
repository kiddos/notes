#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  if (n == 2 || n == 3) {
    cout << "NO SOLUTION" << endl;
    return;
  }

  vector<int> p(n);
  int k = n-1;
  for (int i = 2; i <= n; i += 2) {
    p[k--] = i;
  }
  for (int i = 1; i <= n; i += 2) {
    p[k--] = i;
  }
  for (int x : p) {
    cout << x << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

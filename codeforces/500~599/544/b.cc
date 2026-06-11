#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  int c = 0;
  vector<string> s(n, string(n, 'S'));
  for (int i = 0; i < n; ++i) {
    for (int j = i%2; j < n && c < k; j += 2) {
      s[i][j] = 'L';
      c++;
    }
  }

  if (c < k) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    cout << s[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

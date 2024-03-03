#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(3);
  for (int i = 0; i < 2; ++i) {
    a[i] = 1;
  }
  a.back() = n-2;
  for (int i = 2; i >= 0 && a[i] > 26; --i) {
    int extra = a[i] - 26;
    a[i] = 26;
    a[i-1] += extra;
  }
  for (int i = 0; i < 3; ++i) {
    char c = 'a' + a[i] - 1;
    cout << c;
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

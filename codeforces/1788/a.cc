#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& a) {
  int n = a.size();
  int two = 0;
  for (int i = 0; i < n; ++i) {
    two += a[i] == 2;
  }
  if (two % 2 == 1) {
    cout << "-1" << endl;
    return;
  }

  for (int i = 0, t = 0; i < n; ++i) {
    t += a[i] == 2;
    if (t == two / 2) {
      cout << i+1 << endl;
      break;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    solve(a);
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>& b) {
  int v1 = b[6] - b[5];
  int v3 = b[4] - v1;
  int v2 = b[6] - v1 - v3;
  return {v1, v2, v3};
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    vector<int> b(7);
    for (int i = 0; i < 7; ++i) cin >> b[i];
    vector<int> ans = solve(b);
    for (int a : ans) cout << a << ' ';
    cout << '\n';
  }
  cout << flush;
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, s = 0, r = 0;
    cin >> n >> s >> r;
    int max_val = s - r;
    int dice = n-1;
    int val = r / dice;

    vector<int> ans(n);
    ans[0] = max_val;
    for (int i = 1; i < n; ++i) {
      ans[i] = val;
      r -= val;
    }
    for (int i = 1; i < n && r; ++i) {
      ans[i]++;
      r--;
    }

    for (int a : ans) cout << a << " ";
    cout << endl;
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> ans(n*n+1);
    int r = n*n, l = 1;
    for (int i = 0; i < n*n; i+=2) {
      ans[i] = r--;
      ans[i+1] = l++;
    }
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 1) {
        for (int j = n-1; j >= 0; --j) {
          cout << ans[i*n+j] << " ";
        }
      } else {
        for (int j = 0; j < n; ++j) {
          cout << ans[i*n+j] << " ";
        }
      }
      cout << endl;
    }
  }
  return 0;
}

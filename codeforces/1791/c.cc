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
    string binary;
    cin >> binary;

    int l = 0, r = n-1;
    while (l < r) {
      if (binary[l] != binary[r]) {
        l++;
        r--;
      } else {
        break;
      }
    }
    cout << r-l+1 << endl;
  }
  return 0;
}

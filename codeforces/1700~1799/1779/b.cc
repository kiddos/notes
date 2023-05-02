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
    if (n == 3) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      if (n % 2 == 1) {
        int k = n / 2;
        cout << k - 1 << " ";
        for (int i = 1; i < n; i += 2) {
          cout << -(k) << " " << k-1 << " ";
        }
      } else {
        for (int i = 0; i < n; i += 2) {
          cout << "1 -1 ";
        }
      }
      cout << endl;
    }
  }
  return 0;
}

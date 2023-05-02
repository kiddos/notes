#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // 1, 2, 4, 7, 11, 16, 22, 29, 37, 46, 56
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int k = 0, n = 0;
    cin >> k >> n;
    int current = 1, diff = 1;
    k--;
    cout << 1 << " ";
    while (k-- > 0) {
      int next = current + diff;
      if (n - next >= k) {
        diff++;
        current = next;
      } else {
        current++;
      }
      cout << current << " ";
    }
    cout << endl;
  }
  return 0;
}

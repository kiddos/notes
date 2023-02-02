#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> count(1000000);
  for (int i = 1; i < 1000000; ++i) {
    int k = i;
    int non_zero = 0;
    while (k) {
      int d = k % 10;
      non_zero += d != 0;
      k /= 10;
    }
    count[i] += count[i-1];
    if (non_zero == 1) {
      count[i]++;
    }
  }

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    cout << count[n] << endl;
  }
  return 0;
}

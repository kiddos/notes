#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> a;
    int r = n, l = 1;
    while (a.size() < n) {
      for (int i = 1; i < k && a.size() < n; ++i) {
        a.push_back(r--);
      }
      if (a.size() < n) a.push_back(l++);
    }

    for (int aa : a) cout << aa << " ";
    cout << endl;
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int x = 0, y = 0;
    cin >> x >> y;

    vector<int> a;
    for (int i = y; i <= x; ++i) {
      a.push_back(i);
    }
    for (int i = x-1; i >= y+1; --i) {
      a.push_back(i);
    }
    cout << a.size() << endl;
    for (int num : a) cout << num << " ";
    cout << endl;
  }
  return 0;
}

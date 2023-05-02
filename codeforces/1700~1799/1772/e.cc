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
    int only_first = 0, only_second = 0, both = 0;
    for (int i = 0; i < n; ++i) {
      int a = 0;
      cin >> a;
      int f = i+1, s = n-i;
      if (a != f && a != s) {
        both++;
      } else if (a != f) {
        only_first++;
      } else if (a != s) {
        only_second++;
      }
    }

    if (only_second >= only_first + both) cout << "First" << endl;
    else if (only_first >= only_second + 1 + both) cout << "Second" << endl;
    else cout << "Tie" << endl;
  }
  return 0;
}

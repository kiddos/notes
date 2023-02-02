#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    char a = '0', b = '0', op = ' ';
    cin >> a >> op >> b;
    cout << (a-'0' + b-'0') << endl;
  }
  return 0;
}

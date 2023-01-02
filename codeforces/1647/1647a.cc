#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  constexpr int MAX_VAL = 1000;
  vector<string> ans(MAX_VAL+1);
  ans[1] = "1";
  ans[2] = "2";
  for (int i = 1; i <= MAX_VAL; ++i) {
    if (ans[i].back() == '1') {
      if (i+3 <= MAX_VAL) ans[i+3] = ans[i] + "21";
    } else if (ans[i].back() == '2') {
      if (i+1 <= MAX_VAL) ans[i+1] = ans[i] + "1";
      if (i+3 <= MAX_VAL) ans[i+3] = ans[i] + "12";
    }
  }

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    cout << ans[n] << '\n';
  }
  cout.flush();
  return 0;
}

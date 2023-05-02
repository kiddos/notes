#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b) {
  int ans = b-a;
  for (int aa = a; aa < b; ++aa) {
    int bb = 0;
    for (int i = 31; i >= 0; --i) {
      int a_bit = aa & (1 << i), b_bit = b & (1 << i);
      if (a_bit || b_bit) {
        bb |= (1 << i);
        if (a_bit && !b_bit) break;
      }
    }
    ans = min(ans, (aa|bb) - bb + 1 + (aa - a) + (bb - b));
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int a = 0, b = 0;
    cin >> a >> b;
    int ans = solve(a, b);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long LONG;

bool can_win(LONG hc, LONG dc, LONG hm, LONG dm) {
  return (hc + dm - 1) / dm >= (hm + dc - 1) / dc;
}

bool solve(LONG hc, LONG dc, LONG hm, LONG dm, LONG k, LONG w, LONG a) {
  if (dc > hm) return true;
  for (int i = 0; i <= k; ++i) {
    if (can_win(hc + i * a, dc + (k-i) * w, hm, dm)) return true;
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    LONG hc = 0, dc = 0, hm = 0, dm = 0, k = 0, w = 0, a = 0;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    bool ans = solve(hc, dc, hm, dm, k, w, a);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
  }
  cout << flush << endl;
  return 0;
}

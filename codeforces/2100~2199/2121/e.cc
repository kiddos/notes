#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 l = 0, r = 0;
  cin >> l >> r;
  string left = to_string(l), right = to_string(r);
  int digits = right.length();
  string middle = to_string((l + r) / 2);
  string diff = to_string(r-l);
  diff = string(digits - diff.length(), '0') + diff;

  // cout << "middle=" << middle << endl;
  // cout << "diff=" << diff << endl;

  int ans = 0;
  for (int i = 0; i < digits; ++i) {
    if (diff[i]-'0' > 1) {
      break;
    }

    ans += middle[i] == right[i];
    ans += middle[i] == left[i];
    if (diff[i]-'0' == 1) {
      break;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}

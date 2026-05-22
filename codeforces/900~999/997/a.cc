#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

//    1s 0s 1s 0s 1s 0s (3y)
// -> 1s 1s 0s 0s 0s 1s (2x+y)
// -> 1s 1s 0s 0s 1s 0s (x+2y)
// in 1 swap, we can group 2 separate 0s

void solve() {
  int n = 0;
  i64 x = 0, y = 0;
  cin >> n >> x >> y;
  string s;
  cin >> s;

  vector<pair<int,int>> group;
  int idx = 0;
  while (idx < n) {
    int j = idx;
    while (j+1 < n && s[j+1] == s[j]) {
      j++;
    }
    int len = j-idx+1;
    int digit = s[idx]-'0';
    group.push_back({digit, len});
    idx = j+1;
  }

  int zero_group = 0;
  for (auto [digit, len] : group) {
    if (digit == 0) {
      zero_group++;
    }
  }

  if (zero_group == 0) {
    cout << "0" << endl;
  } else {
    i64 ans = min(zero_group * y, y + (zero_group-1) * x);
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

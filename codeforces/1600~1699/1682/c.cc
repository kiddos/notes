#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  map<int,int> nums;
  for (int i = 0; i < n; ++i) {
    int a = 0;
    cin >> a;
    nums[a]++;
  }

  int first = 0;
  int second = 0;
  for (auto& [x, count] : nums) {
    if (count > 1) {
      first++;
      second++;
    } else {
      if (first <= second) {
        first++;
      } else {
        second++;
      }
    }
  }

  int ans = min(first, second+1);
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

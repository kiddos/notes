#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;

  vector<int> segment = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

  auto count_segment = [&](int x) -> int {
    string s = to_string(x);
    int ans = 0;
    for (char ch : s) {
      ans += segment[ch - '0'];
    }
    return ans;
  };

  i64 ans = 0;
  for (int i = a; i <= b; ++i) {
    ans += count_segment(i);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string n;
  cin >> n;

  auto remove = [&](const string& target) -> int {
    int j = target.length()-1;
    int m = n.length();
    int remove = 0;
    for (int i = m-1; i >= 0; --i) {
      if (target[j] == n[i]) {
        j--;
      } else {
        remove++;
      }
      if (j < 0) {
        return remove;
      }
    }
    return 1000;
  };

  int ans = min({
    remove("00"),
    remove("25"),
    remove("50"),
    remove("75")
  });
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

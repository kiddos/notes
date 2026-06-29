#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;

  vector<i64> f = {1, 2};
  while (true) {
    int size = f.size();
    i64 new_f = f[size-1] + f[size-2];
    if (new_f > n) {
      break;
    }
    f.push_back(new_f);
  }

  int ans = f.size()-1;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

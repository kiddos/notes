#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;
  // the possible n grows exponentially when k grows
  // just need to check small k
  if (k >= 100) {
    cout << "No" << endl;
    return;
  }
  set<int> mods;
  for (int i = 1; i <= k; ++i) {
    mods.insert(n % i);
  }
  if ((int)mods.size() == k) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

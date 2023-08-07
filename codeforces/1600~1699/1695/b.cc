#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  if (n % 2 == 1) {
    cout << "Mike" << endl;
    return;
  }

  int min_index = min_element(a.begin(), a.end()) - a.begin();
  if (min_index % 2 == 0) {
    cout << "Joe" << endl;
  } else {
    cout << "Mike" << endl;
  }
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

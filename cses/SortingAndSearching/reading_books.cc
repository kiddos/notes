#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  int max_t = *max_element(t.begin(), t.end());
  i64 sum = accumulate(t.begin(), t.end(), 0LL);
  i64 rest = sum - max_t;
  if (max_t > rest) {
    cout << max_t * 2 << endl;
  } else {
    cout << sum << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  auto get_answer = [&](int pos) -> int {
    int win = 0;
    int max_val = a[1];
    for (int i = 2; i <= n; ++i) {
      max_val = max(max_val, a[i]);
      if (max_val == a[pos]) {
        win++;
      }
    }
    return win;
  };

  int ans = get_answer(k);
  swap(a[k], a[1]);
  ans = max(ans, get_answer(1));
  swap(a[k], a[1]);

  int first_larger = -1;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > a[k]) {
      first_larger = i;
      break;
    }
  }

  if (first_larger >= 1) {
    swap(a[k], a[first_larger]);
    ans = max(ans, get_answer(first_larger));
    swap(a[k], a[first_larger]);
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

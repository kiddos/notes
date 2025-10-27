#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  i64 can_sum = 0;
  for (int i = 0; i < n; ++i) {
    if (x[i] <= can_sum+1) {
      can_sum += x[i];
    } else {
      cout << can_sum + 1 << endl;
      return;
    }
  }
  cout << can_sum + 1 << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

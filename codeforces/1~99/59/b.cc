#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  i64 sum = accumulate(a.begin(), a.end(), 0LL);
  if (sum % 2 == 1) {
    cout << sum << endl;
    return;
  }

  int remove = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 1) {
      remove = min(remove, a[i]);
    }
  }

  if (remove == numeric_limits<int>::max()) {
    cout << "0" << endl;
  } else {
    cout << sum-remove << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

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
  vector<bool> found(n+1);
  vector<int> to_change;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= 1 && a[i] <= n && !found[a[i]]) {
      found[a[i]] = true;
    } else {
      to_change.push_back(i);
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (!found[i]) {
      int idx = to_change.back();
      to_change.pop_back();
      a[idx] = i;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

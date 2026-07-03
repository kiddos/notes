#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool intersect(int l1, int r1, int l2, int r2) {
  return (l1 < l2 && r1 < r2 && r1 > l2) ||
    (l2 < l1 && r2 < r1 && r2 > l1);
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i+1 < n; ++i) {
    int l1 = min(a[i], a[i+1]), r1 = max(a[i], a[i+1]);
    for (int j = i+1; j+1 < n; ++j) {
      int l2 = min(a[j], a[j+1]), r2 = max(a[j], a[j+1]);
      if (intersect(l1, r1, l2, r2)) {
        cout << "yes" << endl;
        return;
      }
    }
  }
  cout << "no" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

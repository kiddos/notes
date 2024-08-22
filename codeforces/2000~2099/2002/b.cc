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
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int l1 = 0, r1 = n-1;
  int l2 = 0, r2 = n-1;
  while (l1 < r1) {
    int a1 = a[l1], a2 = a[r1];
    int b1 = b[l2], b2 = b[r2];
    if ((a1 != b1 && a1 != b2) || (a2 != b1 && a2 != b2)) {
      cout << "Alice" << endl;
      return;
    }
    if (a1 == b1) {
      l1++;
      l2++;
    } else if (a2 == b2) {
      r1--;
      r2--;
    } else if (a1 == b2) {
      l1++;
      r2--;
    } else if (a2 == b1) {
      r1--;
      l2++;
    }
  }
  cout << "Bob" << endl;
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

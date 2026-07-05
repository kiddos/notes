#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<int> a(3);
  for (int i = 0; i < 3; ++i) {
    cin >> a[i];
  }
  vector<int> b(3);
  for (int i = 0; i < 3; ++i) {
    cin >> b[i];
  }
  int extra = 0;
  for (int i = 0; i < 3; ++i) {
    if (a[i] >= b[i]) {
      extra += (a[i] - b[i]) / 2;
    }
  }

  for (int i = 0; i < 3; ++i) {
    if (a[i] < b[i]) {
      int need = b[i] - a[i];
      if (extra < need) {
        cout << "No" << endl;
        return;
      }
      extra -= need;
    }
  }
  cout << "Yes" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

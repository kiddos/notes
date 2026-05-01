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

  vector<int> count(3);
  for (int i = 0; i < n; ++i) {
    if (a[i] == 25) {
      count[0]++;
    } else if (a[i] == 50) {
      if (count[0]) {
        count[0]--;
        count[1]++;
      } else {
        cout << "NO" << endl;
        return;
      }
    } else if (a[i] == 100) {
      if (count[1] > 0 && count[0] > 0) {
        count[1]--;
        count[0]--;
        count[2]++;
      } else if (count[0] >= 3) {
        count[0] -= 3;
        count[2]++;
      } else {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

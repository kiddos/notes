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
  int last = -1;
  for (int i = 0; i < n; ++i) {
    int target = i;
    int diff = 0;
    if (i % 2 == 0) {
      diff = target - a[i];
    } else {
      diff = a[i] - target;
    }
    diff %= n;
    diff += n;
    diff %= n;

    if (last < 0) {
      last = diff;
    } else {
      if (diff != last) {
        cout << "No" << endl;
        return;
      }
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

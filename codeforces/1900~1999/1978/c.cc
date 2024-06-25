#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;

  if (k % 2 == 1) {
    cout << "NO" << endl;
    return;
  }

  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) a[i] = i;

  for (int i = 1, j = n; i <= n / 2; ++i, --j) {
    int add = (j-a[i]) * 2;
    if (k > add) {
      k -= add;
      swap(a[i], a[j]);
    } else {
      while (add > k && j > i) {
        j--;
        add = (j - a[i]) * 2;
      }
      k -= add;
      swap(a[i], a[j]);
      break;
    }
  }

  if (k > 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
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

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

  int zero_count = 0;
  for (int i = 0; i < n; ++i) {
    zero_count += a[i] == 0;
  }

  if (zero_count == n) {
    cout << "3" << endl;
    cout << n/2+1 << " " << n << endl;
    cout << "1 " << n/2 << endl;
    cout << "1 2" << endl;
  } else if (zero_count == 0) {
    cout << "1" << endl;
    cout << "1 " << n << endl;
  } else {
    if (a[0] == 0 && a.back() == 0) {
      // zero at both end
      cout << "3" << endl;
      cout << n/2+1 << " " << n << endl;
      cout << "1 " << n/2 << endl;
      cout << "1 2" << endl;
    } else if (a[0] == 0) {
      // zero at first
      cout << "2" << endl;
      cout << "1 " << n-1 << endl;
      cout << "1 2" << endl;
    } else if (a.back() == 0) {
      // zero at last
      cout << "2" << endl;
      cout << "2 " << n << endl;
      cout << "1 2" << endl;
    } else {
      // zero in the middle
      cout << "2" << endl;
      cout << "2 " << n-1 << endl;
      cout << "1 3" << endl;
    }
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

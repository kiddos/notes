#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }


  int c1 = 0, c2 = 0;
  for (int i = 0, balance = 0; i < n-1; ++i) {
    if (a[i] > k) {
      balance--;
    } else {
      balance++;
    }

    if (balance == 0) {
      if (c1 > 0) {
        cout << "YES" << endl;
        return;
      }
      c1++;
    } else if (balance > 0) {
      if (c1 > 0 || c2 > 0) {
        cout << "YES" << endl;
        return;
      }
      c2++;
    }
  }

  int c3 = 0, c4 = 0;
  for (int i = n-1, balance = 0; i >= 1; --i) {
    if (a[i] > k) {
      balance--;
    } else {
      balance++;
    }

    if (balance == 0) {
      if (c3 > 0) {
        cout << "YES" << endl;
        return;
      }
      c3++;
    } else if (balance > 0) {
      if (c3 > 0 || c4 > 0) {
        cout << "YES" << endl;
        return;
      }
      c4++;
    }
  }


  int l = 0, r = n-1;
  int balance = 0;
  while (l < n) {
    if (a[l] <= k) {
      balance++;
    } else {
      balance--;
    }
    if (balance >= 0) {
      break;
    }
    l++;
  }

  balance = 0;
  while (r >= 0) {
    if (a[r] <= k) {
      balance++;
    } else {
      balance--;
    }
    if (balance >= 0) {
      break;
    }
    r--;
  }
  if (r-l-1 > 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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

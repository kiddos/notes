#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  
  auto is_power2 = [&](int x) -> bool {
    while (x > 1) {
      if (x % 2 == 1) {
        return false;
      }
      x /= 2;
    }
    return true;
  };

  if (n % 2 == 1) {
    if (n == 3) {
      p[n] = 3;
      p[n-1] = 2;
      p[n-2] = 1;
    } else {
      p[n] = n;
      p[n-1] = n-1;
      p[n-2] = 3;
      p[n-3] = 1;
    }
  } else {
    if (is_power2(n)) {
      if (n == 2) {
        p[n] = 2;
        p[n-1] = 1;
      } else if (n == 4) {
        p[n] = 4;
        p[n-1] = 3;
        p[n-2] = 2;
        p[n-3] = 1;
      } else {
        p[n] = n;
        p[n-1] = n-1;
        p[n-2] = n-2;
        p[n-3] = 3;
        p[n-4] = 1;
      }
    } else {
      int h = 1;
      while ((h<<1) <= n) {
        h <<= 1;
      }
      p[n] = h-1;
      p[n-1] = n-1;
      p[n-2] = n;
    }
  }

  vector<bool> used(n+1);
  for (int i = 1; i <= n; ++i) {
    if (p[i] > 0) {
      used[p[i]] = true;
    }
  }
  vector<int> pool;
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      pool.push_back(i);
    }
  }

  for (int i = n; i >= 1; --i) {
    if (p[i] == 0) {
      p[i] = pool.back();
      pool.pop_back();
    }
  }

  int k = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 1) {
      k &= p[i];
    } else {
      k |= p[i];
    }
  }

  cout << k << endl;
  for (int i = 1; i <= n; ++i) {
    cout << p[i] << " ";
  }
  cout << endl;
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i < n; ++i) {
    v[i] = min(v[i], v[i-1]);
  }

  auto will_fall = [&](int remove) -> bool {
    priority_queue<int, vector<int>, greater<>> larger;
    priority_queue<int, vector<int>, less<>> smaller;
    i64 sum = 0;
    auto insert = [&](int x) {
      if ((int)larger.size() < remove) {
        larger.push(x);
        sum += x;
      } else {
        smaller.push(x);
        if (smaller.top() > larger.top()) {
          int y = larger.top();
          sum -= larger.top();
          larger.pop();
          larger.push(smaller.top());
          sum += smaller.top();
          smaller.pop();
          smaller.push(y);
        }
      }
    };

    for (int i = n-1; i >= 0; --i) {
      for (int j = 0; j < m; ++j) {
        insert(a[i][j]);
      }
      // cout << "max-" << remove << " sum=" << sum << endl;
      if (sum >= v[i]) {
        return true;
      }
    }
    return false;
  };

  int l = 1, r = m-1;
  int ans = m;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (will_fall(mid)) {
      r = mid-1;
      ans = mid;
    } else {
      l = mid+1;
    }
  }
  cout << ans << endl;
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

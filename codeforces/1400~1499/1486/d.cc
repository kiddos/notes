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

  auto possible = [&](int x) -> bool {
    vector<int> b = {0};
    for (int i = 0; i < n; ++i) {
      if (a[i] >= x) {
        b.push_back(1);
      } else {
        b.push_back(-1);
      }
    }

    vector<int> p = b;
    for (int i = 1; i <= n; ++i) {
      p[i] += p[i-1];
    }

    // cout << "x=" << x << endl;
    // for (int i = 0; i <= n; ++i) {
    //   cout << p[i] << " ";
    // }
    // cout << endl;

    int min_val = numeric_limits<int>::max();
    for (int i = k; i <= n; ++i) {
      min_val = min(min_val, p[i-k]);
      if (p[i] - min_val > 0) {
        return true;
      }
    }
    return false;
  };

  int l = 0, r = *max_element(a.begin(), a.end());
  int ans = r;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      l = mid+1;
    } else {
      r = mid-1;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

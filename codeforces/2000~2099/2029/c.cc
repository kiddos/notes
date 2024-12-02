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

  auto possible = [&](int rating) -> bool {
    vector<int> required(n+1);
    required[n] = rating;
    for (int i = n-1; i >= 0; --i) {
      if (a[i] >= required[i+1]) {
        required[i] = required[i+1] - 1;
      } else {
        required[i] = required[i+1] + 1;
      }
    }

    // cout << "require rating=" << rating << endl;
    map<int,int> found;
    for (int i = 0; i < n; ++i) {
      // cout << required[i] << " ";
      found[required[i]]++;
    }
    // cout << endl;


    int current = 0;
    for (int i = 0; i < n; ++i) {
      if (--found[required[i]] == 0) {
        found.erase(required[i]);
      }

      auto it = found.upper_bound(current);
      if (it != found.begin()) {
        return true;
      }
      if (a[i] > current) {
        current++;
      } else if (a[i] < current) {
        current--;
      }
      if (i < n-1 && current >= rating) {
        return true;
      }
    }
    return false;
  };

  int l = 0, r = n;
  int ans = 0;
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

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}

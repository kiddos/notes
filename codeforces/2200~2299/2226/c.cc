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

  auto possible = [&](int mex) -> bool {
    vector<bool> found(mex);
    map<int,int> can_mod;
    for (int i = 0; i < n; ++i) {
      if (a[i] >= mex) {
        can_mod[a[i]]++;
      } else {
        if (found[a[i]]) {
          can_mod[a[i]]++;
        } else {
          found[a[i]] = true;
        }
      }
    }

    for (int i = 0; i < mex; ++i) {
      if (found[i]) {
        continue;
      }
      auto it = can_mod.lower_bound(i * 2 + 1);
      if (it == can_mod.end()) {
        return false;
      }
      it->second--;
      if (it->second == 0) {
        can_mod.erase(it);
      }
    }
    return true;
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

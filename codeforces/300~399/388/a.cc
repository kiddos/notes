#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  sort(x.rbegin(), x.rend());

  constexpr int inf = 1e9;
  auto possible = [&](int stack_size) -> bool {
    vector<int> strength(stack_size, inf);
    for (int i = 0, j = 0; i < n; ++i) {
      if (strength[j] == 0) {
        return false;
      }
      strength[j] = min(strength[j]-1, x[i]);
      j = (j+1)%stack_size;
    }
    return true;
  };

  int l = 1, r = n;
  int ans = r;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  auto compute_answer = [&](int max_h) -> i64 {
    i64 total = 0;
    for (int i = 0; i < n; ++i) {
      total += max_h - h[i];
    }

    auto possible = [&](i64 k) -> bool {
      i64 odd = (k + 1) / 2;
      i64 even = k / 2;
      for (int i = 0; i < n; ++i) {
        i64 require = max_h - h[i];
        i64 use_even = min(require / 2, even);
        even -= use_even;
        require -= use_even * 2;
        if (odd < require) {
          return false;
        }
        odd -= require;
      }
      return true;
    };

    i64 l = 0, r = max(total * 2 - 1, 0LL);
    i64 ans = r;
    while (l <= r) {
      i64 mid = l + (r-l) / 2;
      if (possible(mid)) {
        ans = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    return ans;
  };

  int max_h = *max_element(h.begin(), h.end());
  i64 ans = compute_answer(max_h);
  ans = min(ans, compute_answer(max_h+1));
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

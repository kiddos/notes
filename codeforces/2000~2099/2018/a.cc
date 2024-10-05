#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 max_card = *max_element(a.begin(), a.end());
  i64 total = accumulate(a.begin(), a.end(), 0LL);

  auto possible = [&](int size) -> bool {
    i64 require_total = max_card * size;
    if (total == require_total) {
      return true;
    }
    if (total < require_total && total + k >= require_total) {
      return true;
    }
    if (total > require_total) {
      i64 diff = total - require_total;
      i64 count = (diff + size - 1) / size;
      i64 next_require = count * size + require_total;
      if (total + k >= next_require) {
        return true;
      }
    }

    return false;
  };

  for (int size = n; size >= 1; --size) {
    if (possible(size)) {
      cout << size << endl;
      return;
    }
  }
  cout << "0";
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

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

  unordered_map<int, int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }

  auto possible = [&](int size) -> bool {
    int max_size = 0;
    for (auto& [x, y] : count) {
      max_size = max(max_size, y);
    }
    int first_size = count.size();
    if (max_size < size) {
      return false;
    }
    if (max_size == size) {
      first_size--;
    }
    return first_size >= size;
  };

  int l = 0, r = n / 2;
  int ans = 0;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
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

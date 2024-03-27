#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// only need to consider size of 3
// if ai+1 - ai < ai - ai-1
// this is bad any other subsequence with this 3 number is also bad
// => ai+1 >= ai * 2 - ai-1

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());

  auto find_max_size = [&](int s) -> int {
    int start = a[s];
    int last = start;
    int idx = s+1;
    int size = 1;
    while (true) {
      auto it = lower_bound(a.begin()+idx, a.end(), last * 2 - start);
      if (it == a.end()) break;
      last = *it;
      idx = it - a.begin() + 1;
      size++;
    }
    return size;
  };

  int max_size = 0;
  for (int i = 0; i < n; ++i) {
    if (i == 0 || a[i] != a[i-1]) {
      int size = find_max_size(i);
      max_size = max(max_size, size);
    }
  }

  int ans = n - max_size;
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

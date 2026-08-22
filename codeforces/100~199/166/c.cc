#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  auto possible = [&](int add) -> bool {
    vector<int> b = a;
    for (int j = 0; j < add; ++j) {
      b.push_back(x);
    }
    sort(b.begin(), b.end());
    // for (int val : b) {
    //   cout << val << " ";
    // }
    // cout << endl;
    int size = b.size();
    // cout << "index=" << (size-1)/2 << endl;
    return b[(size-1)/2] == x;
  };

  int l = 0, r = n*2;
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

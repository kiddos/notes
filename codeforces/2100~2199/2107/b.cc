#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  auto first_player_lose = [&]() -> bool {
    multiset<i64> s(a.begin(), a.end());
    i64 largest = *s.rbegin();
    s.erase(s.find(largest));
    if (largest-1 > 0) {
      s.insert(largest-1);
    }
    return *s.rbegin() - *s.begin() > k;
  };

  if (first_player_lose()) {
    cout << "Jerry" << endl;
  } else {
    i64 total = accumulate(a.begin(), a.end(), 0LL);
    if (total % 2 == 0) {
      cout << "Jerry" << endl;
    } else {
      cout << "Tom" << endl;
    }
  }
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

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
  vector<int> even, odd;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 1) {
      odd.push_back(a[i]);
    } else {
      even.push_back(a[i]);
    }
  }
  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());

  while (!odd.empty() && !even.empty()) {
    odd.pop_back();
    even.pop_back();
  }

  if (!odd.empty()) {
    odd.pop_back();
  }
  if (!even.empty()) {
    even.pop_back();
  }

  i64 ans = accumulate(odd.begin(), odd.end(), 0LL) +
    accumulate(even.begin(), even.end(), 0LL);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

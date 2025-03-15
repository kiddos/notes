#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  auto possible = [&](int max_penalty) -> bool {
    int segment = 0;
    bool painting = false;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'B' && a[i] > max_penalty) {
        if (!painting) {
          painting = true;
          segment++;
        }
      } else if (s[i] == 'R' && a[i] > max_penalty) {
        if (painting) {
          painting = false;
        }
      }
    }
    return segment <= k;
  };

  int l = 0, r = *max_element(a.begin(), a.end());
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

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}

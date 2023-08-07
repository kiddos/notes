#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> b(n+1);
  for (int i = 1; i <= n; ++i) cin >> b[i];

  auto find_lower = [&](int i, int b) -> int {
    int l = 1, r = n;
    int ans = r;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (i / mid <= b) {
        ans = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    return ans;
  };

  auto find_upper = [&](int i, int b) -> int {
    int l = 1, r = n;
    int ans = l;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (i / mid >= b) {
        ans = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    return ans;
  };

  vector<array<int,3>> segments;
  for (int i = 1; i <= n; ++i) {
    int L = find_lower(i, b[i]);
    int R = find_upper(i, b[i]);
    segments.push_back({L, R, i});
  }
  sort(segments.begin(), segments.end());

  priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
  vector<int> ans(n+1);
  for (int x = 1, i = 0; x <= n; ++x) {
    while (i < n && segments[i][0] <= x) {
      pq.push({segments[i][1], segments[i][0], segments[i][2]});
      i++;
    }

    int index = pq.top()[2];
    pq.pop();
    ans[index] = x;
  }

  for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
  cout << endl;
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

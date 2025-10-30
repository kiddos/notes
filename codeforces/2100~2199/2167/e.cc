#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  i64 x = 0;
  cin >> n >> k >> x;
  vector<int> a(n);
  for (int i = 0; i < n ; ++i) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  auto possible = [&](int size) -> bool {
    i64 can_place = 0;
    for (int i = 0; i < n; ++i) {
      if (i == 0) {
        can_place += max(a[i] - size + 1, 0);
      } else {
        int start = a[i-1] + size;
        int end = a[i] - size;
        can_place += max(end - start + 1, 0);
      }

      if (i == n-1) {
        can_place += max(x - (a[i] + size) + 1, 0LL);
      }
    }
    return can_place >= k;
  };

  int l = 0, r = x;
  int gap = 0;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(mid)) {
      gap = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  // cout << "gap=" << gap << endl;
  set<int> ans;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      int pos = a[i] - gap;
      while ((int)ans.size() < k && pos >= 0) {
        ans.insert(pos--);
      }
    } else {
      int start = a[i-1] + gap;
      int end = a[i] - gap;
      for (int pos = start; pos <= end && (int)ans.size() < k; ++pos) {
        ans.insert(pos);
      }
    }

    if (i == n-1) {
      int pos = a[i] + gap;
      while ((int)ans.size() < k && pos <= x) {
        ans.insert(pos++);
      }
    }
  }

  for (int pos : ans) {
    cout << pos << " ";
  }
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

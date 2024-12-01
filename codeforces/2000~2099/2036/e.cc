#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0, q = 0;
  cin >> n >> k >> q;
  vector<vector<int>> a(n, vector<int>(k));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> a[i][j];
    }
  }

  vector<vector<int>> b = a;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      b[i][j] |= b[i-1][j];
    }
  }

  auto left_bound = [&](int j, int c) -> int {
    int l = 0, r = n-1;
    int ans = n;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (b[mid][j] > c) {
        r = mid - 1;
        ans = mid;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  };

  auto right_bound = [&](int j, int c) -> int {
    int l = 0, r = n-1;
    int ans = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (b[mid][j] < c) {
        l = mid +1;
        ans = mid;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  };

  for (int i = 0; i < q; ++i) {
    int m = 0;
    cin >> m;

    int left = 0, right = n-1;
    for (int j = 0; j < m; ++j) {
      int r = 0;
      char o = '\0';
      int c = 0;
      cin >> r >> o >> c;

      if (o == '>') {
        left = max(left, left_bound(r-1, c));
      } else if (o == '<') {
        right = min(right, right_bound(r-1, c));
      }
      // cout << "left=" << left << ",right=" << right << endl;
    }

    if (left > right) {
      cout << "-1" << endl;
    } else {
      cout << left+1 << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

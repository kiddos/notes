#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> b = a;
  if (a == vector<int>(n, -1)) {
    for (int i = 0; i < n; ++i) {
      b[i] = i % 2 == 0 ? 1 : 2;
    }
  } else {
    vector<int> indices;
    for (int i = 0; i < n; ++i) {
      if (a[i] != -1) {
        indices.push_back(i);
      }
    }

    auto get_ops = [&](int y, int x) -> int {
      int result = 0;
      while (y > x) {
        y /= 2;
        result++;
      }
      if (y != x) return -1;
      return result;
    };

    for (int k = 1; k < (int)indices.size(); ++k) {
      int i1 = indices[k - 1], i2 = indices[k];
      bool found = false;
      if (a[i1] < a[i2]) {
        int x = a[i1];
        for (int i = i1; i <= i2 && x >= 1; x /= 2, ++i) {
          int right = get_ops(a[i2], x);
          b[i] = x;

          if (right < 0) continue;
          int ops_left = i2 - i;
          if (ops_left >= right && (ops_left - right) % 2 == 0) {
            int y = a[i2];
            int j = i2;
            for (; y >= x; y /= 2, --j) {
              b[j] = y;
            }
            for (; j > i; j -= 2) {
              b[j] = x * 2;
              b[j-1] = x;
            }
            found = true;
            break;
          }
        }
      } else {
        int x = a[i2];
        for (int i = i2; i >= i1 && x >= 1; x /= 2, --i) {
          int left = get_ops(a[i1], x);
          b[i] = x;

          if (left < 0) continue;
          int ops_left = i - i1;
          if (ops_left >= left && (ops_left - left) % 2 == 0) {
            int y = a[i1];
            int j = i1;
            for (; y >= x; y /= 2, ++j) {
              b[j] = y;
            }
            for (; j < i; j += 2) {
              b[j] = x * 2;
              b[j+1] = x;
            }
            found = true;
            break;
          }
        }
      }

      if (!found) {
        cout << "-1" << endl;
        return;
      }
    }

    if (!indices.empty()) {
      int j = indices[0]-1;
      int x = a[indices[0]];
      for (int i = 0; j >= 0; ++i, --j) {
        b[j] = i % 2 == 0 ? x * 2 : x;
      }
      j = indices.back()+1;
      x = a[indices.back()];
      for (int i = 0; j < n; ++i, ++j) {
        b[j] = i % 2 == 0 ? x * 2 : x;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << b[i] << " ";
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

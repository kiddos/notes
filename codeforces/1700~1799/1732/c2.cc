#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> L(q), R(q);
  for (int i = 0; i < q; ++i) {
    cin >> L[i] >> R[i];
  }

  vector<i64> sum = a;
  for (int i = 1; i <= n; ++i) {
    sum[i] += sum[i-1];
  }
  vector<i64> x = a;
  for (int i = 1; i <= n; ++i) {
    x[i] ^= x[i-1];
  }

  auto f = [&](int l, int r) -> i64 {
    return (sum[r] - sum[l-1]) - (x[r] ^ x[l-1]);
  };

  vector<int> next_none_zero(n+1, n+1);
  vector<int> st;
  for (int i = 1; i <= n; ++i) {
    if (a[i]) {
      while (!st.empty()) {
        next_none_zero[st.back()] = i;
        st.pop_back();
      }
    }
    st.push_back(i);
  }

  st.clear();
  vector<int> prev_none_zero(n+1, 0);
  for (int i = n; i >= 1; --i) {
    if (a[i]) {
      while (!st.empty()) {
        prev_none_zero[st.back()] = i;
        st.pop_back();
      }
    }
    st.push_back(i);
  }

  auto find_right = [&](int left, int right, i64 val) -> int {
    int l = left, r = right;
    int idx = r;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      i64 new_val = f(left, mid);
      if (new_val >= val) {
        r = mid-1;
        idx = mid;
      } else {
        l = mid+1;
      }
    }
    return idx;
  };

  auto find_left = [&](int left, int right, i64 val) -> int {
    int l = left, r = right;
    int idx = l;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      i64 new_val = f(mid, right);
      if (new_val >= val) {
        l = mid+1;
        idx = mid;
      } else {
        r = mid-1;
      }
    }
    return idx;
  };

  auto query = [&](int left, int right) -> pair<int,int> {
    // cout << "query: " << left << ", " << right << endl;
    pair<int,int> ans = {left, right};
    i64 best = f(left, right);
    int l = left;
    for (int k = 0; k <= 30; ++k) {
      i64 new_val = f(l, right);
      int new_right = find_right(l, right, new_val);
      // cout << l << "~" << new_right << ":" << new_val << endl;
      if (new_val >= best && new_right - l < ans.second - ans.first) {
        best = new_val;
        ans = {l, new_right};
      }

      int next_l = next_none_zero[l];
      if (next_l > right) {
        break;
      }
      l = next_l;
    }

    int r = right;
    for (int k = 0; k <= 30; ++k) {
      i64 new_val = f(left, r);
      int new_left = find_left(left, r, new_val);
      // cout << new_left << "~" << r << ":" << new_val << endl;
      if (new_val >= best && r - new_left < ans.second - ans.first) {
        best = new_val;
        ans = {new_left, r};
      }

      int prev_r = prev_none_zero[r];
      if (prev_r < left) {
        break;
      }
      r = prev_r;
    }
    // cout << "best=" << best << endl;
    return ans;
  };

  for (int i = 0; i < q; ++i) {
    auto [l, r] = query(L[i], R[i]);
    cout << l << " " << r << endl;
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

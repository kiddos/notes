#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_D = 1000000;

class SegmentTree {
 public:
  SegmentTree(int n) : data_(4 * n) {}

  void update(int i, int tl, int tr, int idx, i64 x) {
    if (tl == tr) {
      data_[i] += x;
      return;
    }
    int tm = tl + (tr - tl) / 2;
    if (idx <= tm) {
      update(i * 2 + 1, tl, tm, idx, x);
    } else {
      update(i * 2 + 2, tm + 1, tr, idx, x);
    }
    data_[i] = data_[i * 2 + 1] + data_[i * 2 + 2];
  }

  void update(int idx, i64 x) {
    update(0, 0, MAX_D, idx, x);
  }

  i64 query(int i, int tl, int tr, int ql, int qr) {
    if (tl > qr || tr < ql) {
      return 0;
    }
    if (tl >= ql && tr <= qr) {
      return data_[i];
    }

    int tm = tl + (tr - tl) / 2;
    i64 left = query(i * 2 + 1, tl, tm, ql, min(qr, tm));
    i64 right = query(i * 2 + 2, tm + 1, tr, max(ql, tm + 1), qr);
    return left + right;
  }

  i64 query(int ql, int qr) {
    return query(0, 0, MAX_D, ql, qr);
  }

 private:
  vector<i64> data_;
};

SegmentTree tree(MAX_D+1);

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  vector<pair<int,int>> entries;
  for (int i = 0; i < n; ++i) {
    int d = 0;
    i64 a = 0;
    cin >> d >> a;
    entries.emplace_back(d, a);
  }
  sort(entries.begin(), entries.end());
  vector<pair<int,i64>> st;

  // if (debug) {
  //   cout << n << " " << m << " " << k << "\n";
  //   for (auto [d, a] : entries) {
  //     cout << d << "," << a << "    ";
  //   }
  //   cout << endl;
  // }


  auto find_max_days = [&](int start, int max_to_add) -> int {
    int l = 0, r = max_to_add;
    int d = 0;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      i64 suffix = tree.query(max(start + mid - k + 1, 0), start);
      if (suffix >= (i64) mid * m) {
        d = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return d;
  };

  auto consume = [&](int d, int days) -> bool {
    i64 need = m * days;
    while (need > 0 && !st.empty()) {
      auto [d1, a1] = st.back();
      if (d1 + k - 1 < d) {
        tree.update(d1, -a1);
        st.pop_back();
        continue;
      }
      i64 drink = min(need, a1);
      need -= drink;
      st.back().second -= drink;
      tree.update(d1, -drink);
      if (st.back().second == 0) {
        st.pop_back();
      }
    }
    return need == 0;
  };

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    auto [d, a] = entries[i];
    st.push_back(entries[i]);
    tree.update(d, a);
    if (consume(d, 1)) {
      ans++;
    }

    if (i+1 < n) {
      int possible_days = entries[i + 1].first - d - 1;
      int day = find_max_days(d, possible_days);
      if (consume(d, day)) {
        ans += day;
      }
      consume(d, possible_days - day);
    }

    // cout << "day:" << d << endl;
    // cout << "stack:";
    // for (auto [d, a] : st) {
    //   cout << d << "," << a << "  ";
    // }
    // cout << endl;
  }

  ans += find_max_days(entries.back().first, MAX_D);

  cout << ans << endl;
  
  while (!st.empty()) {
    auto [d, a] = st.back();
    tree.update(d, -a);
    st.pop_back();
  }

  // cout << "finish tree:";
  // for (int i = 0; i < 100; ++i) {
  //   cout << tree.query(i, i) << " ";
  // }
  // cout << endl;
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

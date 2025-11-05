#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

enum class UpdateType { Assign, Add };

class FenwickTree {
 public:
  FenwickTree(int n) : sums_(n+1) {}

  void update(int i, int delta) {
    int n = sums_.size();
    while (i < n) {
      sums_[i] += delta;
      i += lowbit(i);
    }
  }

  int query(int i) {
    int sum = 0;
    while (i > 0) {
      sum += sums_[i];
      i -= lowbit(i);
    }
    return sum;
  }

  int range_query(int l, int r) {
    return query(r) - query(l-1);
  }

 private:
  inline int lowbit(int x) { return x & (-x); }

  vector<int> sums_;
};

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  vector<array<int,3>> queries;
  for (int i = 0; i < q; ++i) {
    char type = '\0';
    cin >> type;
    if (type == '!') {
      int k = 0, x = 0;
      cin >> k >> x;
      queries.push_back({1, k, x});
    } else if (type == '?') {
      int a = 0, b = 0;
      cin >> a >> b;
      queries.push_back({2, a, b});
    }
  }

  vector<int> s(p.begin(), p.end());
  for (int i = 0; i < q; ++i) {
    if (queries[i][0] == 1) {
      s.push_back(queries[i][2]);
    } else if (queries[i][0] == 2) {
      s.push_back(queries[i][1]);
      s.push_back(queries[i][2]);
    }
  }
  sort(s.begin(), s.end());
  s.resize(unique(s.begin(), s.end()) - s.begin());

  int size = s.size();
  auto get_index = [&](int val) -> int {
    int l = 0, r = size-1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (s[mid] == val) {
        return mid + 1;
      } else if (s[mid] < val) {
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    return -1;
  };

  FenwickTree tree(size);
  for (int i = 0; i < n; ++i) {
    int idx = get_index(p[i]);
    tree.update(idx, 1);
  }

  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    if (queries[i][0] == 1) {
      int k = queries[i][1]-1, x = queries[i][2];
      int i1 = get_index(p[k]);
      tree.update(i1, -1);
      p[k] = x;
      int i2 = get_index(p[k]);
      tree.update(i2, 1);
    } else if (queries[i][0] == 2) {
      int a = queries[i][1], b = queries[i][2];
      int i1 = get_index(a), i2 = get_index(b);
      ans.push_back(tree.range_query(i1, i2));
    }
  }
  for (int count : ans) {
    cout << count << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

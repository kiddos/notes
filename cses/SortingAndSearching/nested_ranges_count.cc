#include <bits/stdc++.h>
 
using namespace std;
 
using i64 = long long;
 
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
  int n = 0;
  cin >> n;
  vector<array<int,3>> interval;
  set<int> s;
  for (int i = 0; i < n; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    interval.push_back({x, y, i});
    s.insert(x);
    s.insert(y);
  }
 
  map<int, int> ids;
  int id = 1;
  for (int pos : s) {
    ids[pos] = id++;
  }
 
  sort(interval.begin(), interval.end(), [&](auto& i1, auto& i2) {
    if (i1[1] == i2[1]) {
      return i1[0] > i2[0];
    }
    return i1[1] < i2[1];
  });
 
  FenwickTree tree1(id);
  vector<int> ans1(n);
  for (int i = 0; i < n; ++i) {
    auto [x, y, idx] = interval[i];
    ans1[idx] = tree1.range_query(ids[x], id-1);
    tree1.update(ids[x], 1);
  }
 
  FenwickTree tree2(id);
  vector<int> ans2(n);
 
  sort(interval.begin(), interval.end(), [&](auto& i1, auto& i2) {
    if (i1[0] == i2[0]) {
      return i1[1] > i2[1];
    }
    return i1[0] < i2[0];
  });
  for (int i = 0; i < n; ++i) {
    auto [x, y, idx] = interval[i];
    ans2[idx] = tree2.range_query(ids[y], id-1);
    tree2.update(ids[y], 1);
  }
 
  for (int i = 0; i < n; ++i) {
    cout << ans1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    cout << ans2[i] << " ";
  }
  cout << endl;
}
 
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  solve();
  return 0;
}

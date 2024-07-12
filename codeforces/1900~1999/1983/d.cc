#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class FenwickTree {
 public:
  FenwickTree(int n) : data_(n) {}

  int get(int i) {
    int total = 0;
    while (i > 0) {
      total += data_[i];
      i -= (i & -i);
    }
    return total;
  }

  void update(int i, int x) {
    int n = data_.size();
    while (i < n) {
      data_[i] += x;
      i += (i & -i);
    }
  }

 private:
  vector<int> data_;
};

constexpr int MAX_A = 200000;

FenwickTree t1(MAX_A+1);
FenwickTree t2(MAX_A+1);

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  vector<int> c = a, d = b;
  sort(c.begin(), c.end());
  sort(d.begin(), d.end());
  if (c != d) {
    cout << "NO" << endl;
    return;
  }

  for (int i = 0; i < n; ++i) {
    t1.update(a[i], 1);
    t2.update(b[i], 1);
  }
  i64 s1 = 0, s2 = 0;
  for (int i = 0; i < n; ++i) {
    t1.update(a[i], -1);
    s1 += t1.get(a[i] - 1);
    t2.update(b[i], -1);
    s2 += t2.get(b[i] - 1);
  }

  if (s1 % 2 == s2 % 2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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

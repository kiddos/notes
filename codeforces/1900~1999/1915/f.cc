#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class FenwickTree {
 public:
  FenwickTree(int n) : data_(n+1) {}

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

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> ab;
  for (int i = 0; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    ab.emplace_back(a, b);
  }

  sort(ab.begin(), ab.end(), [&](auto& p1, auto& p2) {
    return p1.second < p2.second;
  });

  set<int> A;
  for (auto& [a, b] : ab) A.insert(a);
  
  map<int, int> index;
  int id = 0;
  for (int a : A) index[a] = ++id;

  FenwickTree tree(index.size());
  i64 ans = 0;
  int max_a = *A.rbegin();
  for (auto& [a, b] : ab) {
    ans += tree.get(index[max_a]) - tree.get(index[a]);
    tree.update(index[a], 1);
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

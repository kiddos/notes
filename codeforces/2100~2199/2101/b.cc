#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class FenwickTree {
 public:
  FenwickTree(int n) : data_(n+1) {}

  i64 get(int i) {
    i64 total = 0;
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
  vector<i64> data_;
};

i64 count_inversion(vector<int>& a, int start, int n) {
  i64 inversion = 0;
  FenwickTree tree(n);
  for (int i = start; i <= n; i += 2) {
    i64 larger = tree.get(n) - tree.get(a[i]);
    inversion += larger;
    tree.update(a[i], 1);
  }
  return inversion;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  i64 inversion_p = count_inversion(a, 1, n) + count_inversion(a, 2, n);
  // cout << "inversion =" << inversion_p << endl;
  inversion_p %= 2;

  vector<int> odd, even;
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 1) {
      odd.push_back(a[i]);
    } else {
      even.push_back(a[i]);
    }
  }
  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());

  vector<int> ans(n);
  for (int i = 0, k = 0; i < (int)odd.size(); ++i, k += 2) {
    ans[k] = odd[i];
  }
  for (int i = 0, k = 1; i < (int)even.size(); ++i, k += 2) {
    ans[k] = even[i];
  }
  if (inversion_p == 1) {
    swap(ans[n-1], ans[n-3]);
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
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

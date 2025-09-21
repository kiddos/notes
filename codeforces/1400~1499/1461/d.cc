#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  set<i64> sums;
  auto divide = [&](const auto& self, vector<i64>& arr) -> void {
    if (arr.size() == 0) {
      return;
    }

    i64 max_val = *max_element(arr.begin(), arr.end());
    i64 min_val = *min_element(arr.begin(), arr.end());
    i64 sum = accumulate(arr.begin(), arr.end(), 0LL);
    sums.insert(sum);
    i64 mid = (max_val + min_val) / 2;
    vector<i64> left, right;
    for (int ai : arr) {
      if (ai <= mid) {
        left.push_back(ai);
      } else {
        right.push_back(ai);
      }
    }

    if (left.size() != 0 && right.size() != 0) {
      self(self, left);
      self(self, right);
    }
  };

  divide(divide, a);

  vector<bool> ans;
  for (int i = 0; i < q; ++i) {
    i64 s = 0;
    cin >> s;
    ans.push_back(sums.count(s));
  }

  for (int i = 0; i < q; ++i) {
    if (ans[i]) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
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

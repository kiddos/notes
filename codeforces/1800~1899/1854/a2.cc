#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<pair<int,int>> make_large_pos(vector<int> arr, int max_idx, int min_idx) {
  int n = arr.size();
  vector<pair<int,int>> ops;
  for (int k = 0; k < 33 && arr[max_idx] < abs(arr[min_idx]); ++k) {
    arr[max_idx] += arr[max_idx];
    ops.emplace_back(max_idx, max_idx);
  }
  for (int i = 0; i < n; ++i) {
    if (arr[i] < 0) {
      arr[i] += arr[max_idx];
      ops.emplace_back(i, max_idx);
    }
  }
  return ops;
};

vector<pair<int,int>> make_small_neg(vector<int> arr, int max_idx, int min_idx) {
  int n = arr.size();
  vector<pair<int,int>> ops;
  for (int k = 0; k < 33 && abs(arr[min_idx]) < arr[max_idx]; ++k) {
    arr[min_idx] += arr[min_idx];
    ops.emplace_back(min_idx, min_idx);
  }
  for (int i = 0; i < n; ++i) {
    if (arr[i] > 0) {
      arr[i] += arr[min_idx];
      ops.emplace_back(i, min_idx);
    }
  }
  return ops;
};

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int min_idx = min_element(a.begin(), a.end()) - a.begin();
  int max_idx = max_element(a.begin(), a.end()) - a.begin();
  vector<pair<int,int>> ops1 = make_large_pos(a, max_idx, min_idx);
  vector<pair<int,int>> ops2 = make_small_neg(a, max_idx, min_idx);

  vector<pair<int,int>> ans;
  if (ops1.size() <= ops2.size()) {
    ans = ops1;
    // prefix sum
    for (int i = 1; i < n; ++i) {
      ans.emplace_back(i, i-1);
    }
  } else {
    ans = ops2;
    // suffix sum
    for (int i = n-2; i >= 0; --i) {
      ans.emplace_back(i, i+1);
    }
  }

  cout << ans.size() << endl;
  for (auto [i, j] : ans) {
    cout << i+1 << " " << j+1 << endl;
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

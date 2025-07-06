#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

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

  vector<pair<int,int>> ans;

  auto move = [&](vector<int>& arr, int type, int i1, int i2) {
    int j = i1-1;
    while (j >= i2) {
      ans.emplace_back(type, j);
      swap(arr[j], arr[j+1]);
      j--;
    }
  };

  auto fix = [&](vector<int>& arr, int type) {
    for (int i = 0; i < n; ++i) {
      int idx = -1;
      int min_val = arr[i];
      for (int j = i+1; j < n; ++j) {
        if (arr[j] < min_val) {
          idx = j;
          min_val = arr[j];
        }
      }
      if (idx >= 0) {
        move(arr, type, idx, i);
      }
    }
  };

  fix(a, 1);
  fix(b, 2);
  for (int i = 0; i < n; ++i) {
    if (a[i] > b[i]) {
      ans.emplace_back(3, i);
      swap(a[i], b[i]);
    }
  }
  fix(a, 1);
  // fix(b, 2);

  
  cout << ans.size() << endl;
  for (auto [type, idx] : ans) {
    cout << type << " " << idx +1 << endl;
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << a[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i < n; ++i) {
  //   cout << b[i] << " ";
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

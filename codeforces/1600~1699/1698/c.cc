#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> pos, neg, zeros;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      pos.push_back(a[i]);
    } else if (a[i] < 0) {
      neg.push_back(a[i]);
    } else if (zeros.size() < 2) {
      zeros.push_back(a[i]);
    }
  }

  if (pos.size() > 2 || neg.size() > 2) {
    cout << "NO" << endl;
    return;
  }

  vector<int> arr;
  for (int p : pos) arr.push_back(p);
  for (int n : neg) arr.push_back(n);
  for (int z : zeros) arr.push_back(z);

  set<int> s(arr.begin(), arr.end());
  int m = arr.size();
  for (int i = 0; i < m; ++i) {
    for (int j = i+1; j < m; ++j) {
      for (int k = j+1; k < m; ++k) {
        i64 sum = arr[i] + arr[j] + arr[k];
        if (!s.count(sum)) {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  cout << "YES" << endl;
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

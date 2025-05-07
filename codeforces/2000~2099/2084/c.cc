#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  map<pair<int,int>, vector<int>> indices;
  for (int i = 0; i < n; ++i) {
    pair<int,int> key = {min(a[i], b[i]), max(a[i], b[i])};
    indices[key].push_back(i);
  }
  if ((int)indices.size() != (n+1) / 2) {
    cout << "-1" << endl;
    return;
  }

  vector<int> pb(n+1);
  for (int i = 0; i < n; ++i) {
    pb[b[i]] = i;
  }

  vector<pair<int,int>> ans;

  auto swap_to = [&](int i1, int i2) {
    ans.push_back({i1, i2});
    swap(a[i1], a[i2]);
    swap(b[i1], b[i2]);
    pb[b[i1]] = i1;
    pb[b[i2]] = i2;
  };

  int middle = n/2;
  if (n % 2 == 1) {
    int middle_element = -1;
    for (int i = 0; i < n; ++i) {
      if (pb[a[i]] == i) {
        middle_element = i;
        break;
      }
    }
    if (middle_element != middle) {
      swap_to(middle_element, middle);
    }
  }

  for (int i = 0; i < middle; ++i) {
    int i1 = i, i2 = pb[a[i]];
    if (i1 != n-i2-1) {
      swap_to(i2, n-i1-1);
    }
  }

  cout << ans.size() << endl;
  for (auto [i1, i2] : ans) {
    cout << i1+1 << " " << i2+1 << endl;
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

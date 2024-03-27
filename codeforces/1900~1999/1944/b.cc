#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n * 2);
  for (int i = 0; i < n*2; ++i) cin >> a[i];

  vector<int> left(n+1), right(n+1);
  for (int i = 0; i < n; ++i) {
    left[a[i]]++;
    right[a[i+n]]++;
  }

  vector<int> l1, r1, l2, r2;
  for (int i = 1; i <= n; ++i) {
    if (left[i] == 2) {
      l2.push_back(i);
    } else if (left[i] == 1) {
      l1.push_back(i);
    }
    if (right[i] == 2) {
      r2.push_back(i);
    } else if (right[i] == 1) {
      r1.push_back(i);
    }
  }

  sort(l1.begin(), l1.begin());
  sort(l2.begin(), l2.begin());
  sort(r1.begin(), r1.begin());
  sort(r2.begin(), r2.begin());

  vector<int> l, r;
  int m = k * 2;
  while (m > 0 && !l2.empty() && !r2.empty()) {
    l.push_back(l2.back());
    l.push_back(l2.back());
    l2.pop_back();

    r.push_back(r2.back());
    r.push_back(r2.back());
    r2.pop_back();

    m -= 2;
  }

  while (m > 0 && !l1.empty() && !r1.empty()) {
    l.push_back(l1.back());
    l1.pop_back();
    r.push_back(r1.back());
    r1.pop_back();
    m--;
  }

  for (int x : l) cout << x << " ";
  cout << endl;
  for (int x : r) cout << x << " ";
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
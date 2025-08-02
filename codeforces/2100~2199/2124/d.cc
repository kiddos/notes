#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_palindrome(vector<int>& a) {
  int n = a.size();
  int l = 0, r = n-1;
  while (l < r) {
    if (a[l] != a[r]) {
      return false;
    }
    l++;
    r--;
  }
  return true;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (k <= 2) {
    cout << "YES" << endl;
    return;
  }

  int keep = k-1;
  vector<int> b = a;
  sort(b.begin(), b.end());
  b.resize(keep);

  vector<int> c;
  for (int i = 0; i < n; ++i) {
    if (a[i] <= b.back()) {
      c.push_back(a[i]);
    }
  }
  int size = c.size();
  int l = 0, r = size-1;
  vector<int> remove(size);
  while (l <= r) {
    if (c[l] == c[r]) {
      l++;
      r--;
    } else {
      if (c[l] > c[r]) {
        remove[l] = 1;
        l++;
      } else {
        remove[r] = 1;
        r--;
      }
    }
  }
  for (int i = 0; i < size; ++i) {
    if (remove[i] && c[i] != b.back()) {
      cout << "NO" << endl;
      return;
    }
  }
  int can_remove = size - b.size();
  int total_remove = accumulate(remove.begin(), remove.end(), 0);
  if (total_remove > can_remove) {
    cout << "NO" << endl;
    return;
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_palindrome(vector<int>& a, int ignore) {
  vector<int> b;
  for (int x : a) if (x != ignore) {
    b.push_back(x);
  }
  int size = b.size();
  int l = 0, r = size-1;
  while (l <= r) {
    if (b[l] != b[r]) {
      return false;
    }
    l++;
    r--;
  }
  return true;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int l = 0, r = n-1;
  while (l <= r) {
    if (a[l] != a[r]) {
      if (is_palindrome(a, a[l]) || is_palindrome(a, a[r])) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      return;
    }
    l++;
    r--;
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

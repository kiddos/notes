#include <bits/stdc++.h>
 
using namespace std;

bool is_permutation(vector<int>& p) {
  int n = p.size();
  vector<bool> found(n+1);
  for (int i = 0; i < n; ++i) {
    found[p[i]] = true;
  }
  for (int i = 1; i <= n; ++i) if (!found[i]) return false;
  return true;
}
 
void solve() {
  int n = 0;
  cin >> n;
  vector<int> b;
  int l = 0, r = n-1;
  while (l <= r) {
    if (l == r) {
      b.push_back(l++);
    } else {
      b.push_back(l++);
      b.push_back(r--);
    }
  }
 
  vector<int> a = {n};
  for (int i = 1; i < n; ++i) {
    a.push_back((b[i] - b[i-1] + n) % n);
  }
 
  // cout << "a: ";
  //   for (int i = 0; i < n; ++i) {
  //     cout << a[i] << " ";
  //   }
  // cout << endl;
  // cout << "b: ";
  //   for (int i = 0; i < n; ++i) {
  //     cout << b[i] << " ";
  //   }
  // cout << endl;
 
  if (is_permutation(a)) {
    for (int i = 0; i < n; ++i) {
      cout << a[i] << " ";
    }
    cout << endl;
  } else {
    cout << "-1" << endl;
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

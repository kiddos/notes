#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>& p) {
  int n = p.size();
  for (int l = 0; l < n; ++l) {
    for (int r = l+1; r < n; ++r) {
      int sum = 0;
      for (int i = l; i <= r; ++i) {
        sum += p[i];
      }
      if (sum % (r-l+1) == 0) {
        cout << l << ", " << r << endl;
        return false;
      }
    }
  }
  return true;
}

void solve() {
  int n = 0;
  cin >> n;
  if (n == 1) {
    cout << "1" << endl;
    return;
  } else if (n % 2 == 1){
    cout << "-1" << endl;
    return;
  }
  vector<int> p(n);

  for (int i = 1; i < n; i += 2) {
    p[i] = i;
  }
  for (int i = 2; i <= n; i += 2) {
    p[i-2] = i;
  }
  for (int i = 0; i < n; ++i) {
    cout << p[i] << " ";
  }
  cout << endl;

  // cout << check(p) << endl;
}


// 1 4 3 2
// 1 4 5 2 3 x
// 1 6 3 4 5 2 
// 1 8 3 6 5 4 7 2

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

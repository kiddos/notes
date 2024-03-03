#include <bits/stdc++.h>
 
using namespace std;
 
using i64 = long long;

int msb(i64 n) {
  for (int i = 62; i >= 0; --i) {
    if (n & (1LL<<i)) {
      return i;
    }
  }
  return 0;
}
 
void solve() {
  i64 n = 0;
  cin >> n;
  if (n < 2) {
    cout << "-1" << endl;
    return;
  }
 
  int m = msb(n);
 
  vector<int> ans;
  int d = 0;
  for (int i = m-1; i >= 0; --i) {
    ans.push_back(d++);
  }
  for (int i = m-1; i >= 0; --i) {
    if (n & (1LL << i)) {
      ans.insert(ans.begin()+i, d++);
    }
  }
 
  cout << ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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

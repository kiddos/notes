#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  bool sorted = true;
  for (int i = 1; i < n; ++i) {
    if (s[i-1] > s[i]) {
      sorted = false;
      break;
    }
  }

  if (sorted) {
    cout << "0" << endl;
    return;
  }

  int total = 0;
  for (int i = 0; i < n; ++i) {
    total += s[i] == '1';
  }

  vector<int> ans;
  for (int i = n-1; i >= n-total; --i) {
    if (s[i] != '1') {
      ans.push_back(i+1);
    }
  }
  for (int i = 0; i < n-total; ++i) {
    if (s[i] == '1') {
      ans.push_back(i+1);
    }
  }

  sort(ans.begin(), ans.end());
  cout << "1" << endl;
  cout << ans.size() << " ";
  for (int i : ans)  cout << i << " ";
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }

  vector<int> left_dec(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    if (p[i] > p[i-1]) {
      left_dec[i] = left_dec[i-1] + 1;
    }
  }
  vector<int> right_dec(n+1, 1);
  for (int i = n-1; i >= 1; --i) {
    if (p[i] > p[i+1]) {
      right_dec[i] = right_dec[i+1] + 1;
    }
  }

  map<int, vector<int>> path_count;
  for (int i = 1; i <= n; ++i) {
    int l = right_dec[i];
    int r = left_dec[i];
    path_count[l].push_back(i);
    path_count[r].push_back(i);
  }

  // if there is no peak
  // daniel can just block right in front of qingshan
  // and qingshan will always lose
  if (path_count.empty()) {
    cout << "0" << endl;
    return;
  }

  // if there is another path that is greater or equal to the current longest downhill
  // daniel can always win
  if (path_count.rbegin()->second.size() != 2) {
    cout << "0" << endl;
    return;
  }

  vector<int>& possible = path_count.rbegin()->second;
  if (possible[0] != possible[1]) {
    cout << "0" << endl;
    return;
  }

  int x = path_count.rbegin()->second.back();

  int ans = 0;
  int len = left_dec[x];
  if (len % 2 == 1) {
    ans++;
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int balance = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      balance++;
    } else if (s[i] == 'b') {
      balance--;
    }
  }
  if (balance == 0) {
    cout << "0" << endl;
    return;
  }

  map<int,int> index = {{0, -1}};
  int current = 0;
  int ans = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      current++;
    } else if (s[i] == 'b') {
      current--;
    }

    int target = current - balance;
    if (index.count(target)) {
      ans = min(ans, i - index[target]);
    }
    index[current] = i;
  }

  if (ans == n) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
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

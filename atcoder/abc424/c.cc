#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1), b(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
  }

  vector<vector<int>> can_learn(n+1);
  for (int i = 1; i <= n; ++i) {
    if (a[i] > 0) {
      can_learn[a[i]].push_back(i);
    }
    if (b[i] > 0) {
      can_learn[b[i]].push_back(i);
    }
  }
  queue<int> q;
  vector<bool> learned(n+1);
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 0 && b[i] == 0) {
      q.push(i);
      learned[i] = true;
    }
  }

  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int skill = q.front();
      q.pop();
      for (int skill2 : can_learn[skill]) {
        if (learned[skill2]) {
          continue;
        }
        q.push(skill2);
        learned[skill2] = true;
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (learned[i]) {
      ans++;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

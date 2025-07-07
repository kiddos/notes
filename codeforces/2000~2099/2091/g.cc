#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int s = 0, k = 0;
  cin >> s >> k;

  if (s % k == 0) {
    cout << k << endl;
    return;
  }

  if (s > k * k) {
    cout << max(k-2, 1) << endl;
    return;
  }

  vector<bool> visited(s+1);
  visited[0] = true;

  auto move_with_power = [&](int power, int dir) {
    queue<int> q;
    for (int i = 0; i <= s; ++i) {
      if (visited[i]) {
        q.push(i);
      }
    }
    fill(visited.begin(), visited.end(), false);
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        int pos = q.front();
        q.pop();
        int pos2 = pos + dir * power;
        if (pos2 >= 0 && pos2 <= s && !visited[pos2]) {
          visited[pos2] = true;
          q.push(pos2);
        }
      }
    }
  };

  int ans = 1;
  for (int power = k, dir = 1; power >= 2; --power, dir = -dir) {
    move_with_power(power, dir);
    if (visited[s]) {
      ans = power;
      break;
    }
  }

  cout << ans << endl;
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

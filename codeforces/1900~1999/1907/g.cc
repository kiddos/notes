#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  s = " " + s;

  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<int> indegree(n+1);
  for (int i = 1; i <= n; ++i) {
    indegree[a[i]]++;
  }

  auto rev = [&](char& c) {
    c = c == '0' ? '1' : '0';
  };

  vector<bool> visited(n+1);
  vector<int> ans;
  function<void()> turn_off_non_cycle = [&]() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
      if (indegree[i] == 0) {
        q.push(i);
        visited[i] = true;
      }
    }

    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        int j = q.front();
        q.pop();
        if (s[j] == '1') {
          rev(s[j]);
          rev(s[a[j]]);
          ans.push_back(j);
        }

        indegree[a[j]]--;
        if (!visited[a[j]] && indegree[a[j]] == 0) {
          visited[a[j]] = true;
          q.push(a[j]);
        }
      }
    }
  };

  turn_off_non_cycle();
  // cout << "is cycle:";
  // for (int i = 1; i <= n; ++i) {
  //   cout << is_cycle[i];
  // }
  // cout << endl;
  // cout << "visted:";
  // for (int i = 1; i <= n; ++i) {
  //   cout << visited[i];
  // }
  // cout << endl;
  // cout << ans.size() << endl;
  // cout << "s=";
  // cout << s << endl;

  function<bool(int)> turn_off_cycle = [&](int i) -> bool {
    int node = i;
    int ones = 0;
    vector<int> cycle;
    while (!visited[node]) {
      visited[node] = true;
      ones += s[node] == '1';
      cycle.push_back(node);
      node = a[node];
    }

    if (ones % 2 == 1) {
      return false;
    }

    // cout << "s=" << s << endl;
    // cout << "cycle: ";
    // for (int j : cycle) cout << j << " ";
    // cout << endl;

    vector<int> ans1, ans2;
    int size = cycle.size();
    // choice1
    for (int k = 0; k < size; ++k) {
      int j = cycle[k];
      if (k == 0 || s[j] == '1') {
        rev(s[j]);
        rev(s[a[j]]);
        ans1.push_back(j);
      }
    }
    for (int j : ans1) {
      rev(s[j]);
      rev(s[a[j]]);
    }

    // choice2
    for (int k = 1; k < size; ++k) {
      int j = cycle[k];
      if (k != 0 && s[j] == '1') {
        rev(s[j]);
        rev(s[a[j]]);
        ans2.push_back(j);
      }
    }

    if (ans1.size() < ans2.size()) {
      for (int node : ans1) ans.push_back(node);
    } else {
      for (int node : ans2) ans.push_back(node);
    }
    return true;
  };

  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      if (!turn_off_cycle(a[i])) {
        cout << "-1" << endl;
        return;
      }
    }
  }

  cout << ans.size() << endl;
  for (int i : ans) cout << i << " ";
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

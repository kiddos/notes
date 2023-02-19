#include <bits/stdc++.h>

using namespace std;

struct State {
  int s11;
  int s00;
  int s01;
  int s10;
};

string hash_state(const State& state) {
  return to_string(state.s11) + "#" +
      to_string(state.s00) + "#" +
      to_string(state.s01) + "#" +
      to_string(state.s10);
}

int solve(string a, string b) {
  int n = a.size();
  State init{0, 0, 0, 0};
  for (int i = 0; i < n; ++i) {
    if (a[i] == '1' && b[i] == '1') {
      init.s11++;
    } else if (a[i] == '0' && b[i] == '0') {
      init.s00++;
    } else if (a[i] == '1' && b[i] == '0') {
      init.s10++;
    } else if (a[i] == '0' && b[i] == '1') {
      init.s01++;
    }
  }

  int step = 0;
  queue<State> q;
  q.push(init);
  unordered_set<string> visited;
  visited.insert(hash_state(init));
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto [s11, s00, s01, s10] = q.front();
      // cout << hash_state(q.front()) << endl;
      q.pop();
      if (s01 == 0 && s10 == 0) return step;

      if (s11) {
        State next_state{s01+1, s10, s11-1, s00};
        string h = hash_state(next_state);
        if (!visited.count(h)) {
          visited.insert(h);
          q.push(next_state);
        }
      }

      if (s10) {
        State next_state{s01, s10-1, s11, s00+1};
        string h = hash_state(next_state);
        if (!visited.count(h)) {
          visited.insert(h);
          q.push(next_state);
        }
      }
    }
    step++;
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int ans = solve(a, b);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}

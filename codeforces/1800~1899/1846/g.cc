#include <bits/stdc++.h>

using namespace std;

struct State {
  int symp;
  int day;
};

struct CompareState {
  bool operator()(const State& s1, const State& s2) {
    return s1.day > s2.day;
  }
};

int to_int(const string& s) {
  int a = 0;
  for (char c : s) {
    a = (a << 1) + (c-'0');
  }
  return a;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s;
  cin >> s;

  int state = to_int(s);
  vector<array<int, 3>> edges;
  for (int i = 0; i < m; ++i) {
    int d = 0;
    cin >> d;
    string s1, s2;
    cin >> s1 >> s2;

    edges.push_back({to_int(s1), to_int(s2), d});
  }

  constexpr int MAX_VAL = 1e9;
  vector<int> dist(1<<n, MAX_VAL);
  priority_queue<State, vector<State>, CompareState> q;
  q.push({state, 0});
  dist[state] = 0;

  while (!q.empty()) {
    auto [symp, d] = q.top();
    q.pop();
    if (symp == 0) {
      cout << d << endl;
      return;
    }

    for (auto& [s1, s2, days] : edges) if (s1 & symp) {
      int remove = s1 & symp;
      int s3 = (symp ^ remove) | s2;
      int d2 = d + days;
      if (d2 < dist[s3]) {
        dist[s3] = d2;
        q.push({s3, d+days});
      }
    }
  }

  cout << "-1" << endl;
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

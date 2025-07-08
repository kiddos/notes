#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct TrieNode {
  int next[10];
  bool has_value;
  int failure;

  TrieNode() : has_value(false), failure(0) { fill(begin(next), end(next), 0); }
};

constexpr int ROOT = 0;

void add_string(vector<TrieNode>& nodes, const string& word) {
  int v = ROOT;
  for (char ch : word) {
    int c = ch - '0';
    if (!nodes[v].next[c]) {
      nodes[v].next[c] = nodes.size();
      nodes.emplace_back();
    }
    v = nodes[v].next[c];
  }
  nodes[v].has_value = true;
}

int move(vector<TrieNode>& nodes, int v, char ch) {
  int c = ch - '0';
  while (v > 0 && !nodes[v].next[c]) {
    v = nodes[v].failure;
  }
  return nodes[v].next[c];
}

void aho_corasick(vector<TrieNode>& nodes) {
  queue<int> q;
  nodes[ROOT].failure = ROOT;
  for (int c = 0; c < 10; ++c) {
    if (nodes[ROOT].next[c]) {
      int child = nodes[ROOT].next[c];
      nodes[child].failure = ROOT;
      q.push(child);
    }
  }

  while (!q.empty()) {
    int id = q.front();
    q.pop();

    for (int c = 0; c < 10; ++c) {
      if (nodes[id].next[c]) {
        int child = nodes[id].next[c];
        nodes[child].failure = move(nodes, nodes[id].failure, '0' + c);
        if (nodes[nodes[child].failure].has_value) {
          nodes[child].has_value = true;
        }
        q.push(child);
      }
    }
  }
}

void solve() {
  int x = 0;
  string s;
  cin >> s >> x;

  string t;
  vector<string> should_ignore;
  auto gen = [&](const auto& self, int sum) -> void {
    if (sum == x) {
      int size = t.size();
      bool bad = true;
      for (int l = 0; l < size; ++l) {
        int cur = 0;
        for (int r = l; r < size; ++r) {
          cur += (t[r] - '0');
          if (x % cur == 0 && cur != x) {
            bad = false;
          }
        }
      }
      if (bad) {
        should_ignore.push_back(t);
      }
      return;
    }

    for (int j = 1; j <= min(x - sum, 9); ++j){
      t.push_back('0' + j);
      self(self, sum + j);
      t.pop_back();
    }
  };

  gen(gen, 0);

  vector<TrieNode> nodes(1);
  int m = should_ignore.size();
  for (int i = 0; i < m; ++i) {
    // cout << should_ignore[i] << " ";
    add_string(nodes, should_ignore[i]);
  }
  // cout << endl;

  aho_corasick(nodes);

  int n = s.length();
  int size = nodes.size();
  constexpr int inf = 1e9;
  vector<vector<int>> dp(n + 1, vector<int>(size, inf));
  dp[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < size; ++j) {
      if (dp[i][j] >= inf) {
        continue;
      }

      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
      int next = move(nodes, j, s[i]);
      if (!nodes[next].has_value) {
        dp[i + 1][next] = min(dp[i + 1][next], dp[i][j]);
      }
    }
  }

  int ans = inf;
  for (int j = 0; j < size; ++j) {
    ans = min(ans, dp[n][j]);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

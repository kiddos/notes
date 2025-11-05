#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s = "01";
  int len = s.length();

  unordered_set<string> visited;
  vector<int> edges;
  auto dfs = [&](const auto& self, const string& node) -> void {
    for (int i = 0; i < len; ++i) {
      string seq = node + s[i];
      if (!visited.count(seq)) {
        visited.insert(seq);
        self(self, seq.substr(1));
        edges.push_back(i);
      }
    }
  };

  string start_node = string(n-1, s[0]);
  dfs(dfs, start_node);
  int l = pow(len, n);
  string ans;
  for (int i = 0; i < l; ++i) {
    ans.push_back(s[edges[i]]);
  }
  ans += start_node;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

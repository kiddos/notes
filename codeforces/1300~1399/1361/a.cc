#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.push_back({a, b});
  }
  vector<int> t(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
  }

  vector<vector<int>> adj(n+1);
  for (auto [a, b] : edges) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<pair<int,int>> blogs;
  for (int i = 1; i <= n; ++i) {
    blogs.push_back({t[i], i});
  }
  sort(blogs.begin(), blogs.end());

  vector<int> last_seen_topic(n + 1, 0);
  for (auto [ti, blog] : blogs) {
    int smaller = 0;
    for (int next_blog : adj[blog]) {
      if (t[next_blog] == ti) {
        cout << "-1" << endl;
        return;
      }

      if (t[next_blog] < ti) {
        if (last_seen_topic[t[next_blog]] != blog) {
          last_seen_topic[t[next_blog]] = blog;
          smaller++;
        }
      }
    }
    if (smaller != ti - 1) {
      cout << "-1" << endl;
      return;
    }
  }

  for (auto [ti, blog] : blogs) {
    cout << blog << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int MAX_SIZE = 200000;
constexpr ll MOD = 1e13 + 1337;

vector<ll> F(MAX_SIZE+1);

void precompute() {
  mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

  for (int i = 0; i <= MAX_SIZE; ++i) {
    F[i] = gen();
  }
}

void solve() {
  int n = 0;
  cin >> n;

  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<ll> hashes(n+1);
  vector<int> sizes(n+1);
  vector<bool> is_symmetric(n+1);
  function<void(int,int)> dfs = [&](int node, int parent) {
    map<ll, int> hash_codes;
    hashes[node] = 66666661;
    for (int child : adj[node]) if (child != parent) {
      dfs(child, node);
      sizes[node] += sizes[child];
      hashes[node] += (F[sizes[child]] ^ hashes[child]) % MOD;

      // cout << "node=" << child << ", hash=" << hashes[child] << endl;
      
      if (hash_codes.count(hashes[child])) {
        hash_codes.erase(hashes[child]);
      } else {
        hash_codes[hashes[child]] = child;
      }
    }

    if (hash_codes.size() > 1) {
      is_symmetric[node] = false;
    } else {
      if (hash_codes.size() == 0) {
        is_symmetric[node] = true;
      } else {
        int child = hash_codes.begin()->second;
        is_symmetric[node] = is_symmetric[child];
      }
    }
    sizes[node]++;
  };

  dfs(1, -1);

  if (is_symmetric[1]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}

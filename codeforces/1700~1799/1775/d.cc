#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int s = 0, t = 0;
  cin >> s >> t;

  if (a[s] == a[t]) {
    if (s == t) {
      cout << "1" << endl;
      cout << s << endl;
    } else if (a[s] == 1) {
      cout << "-1" << endl;
    } else {
      cout << "2" << endl;
      cout << s << " " << t << endl;
    }
    return;
  }

  const int max_val = *max_element(a.begin(), a.end());

  vector<int> index(max_val+1, -1);
  for (int i = 1; i <= n; ++i) {
    if (index[a[i]] >= 0) continue;
    index[a[i]] = i;
  }

  vector<vector<int>> all_primes(max_val+1);
  vector<vector<int>> prime2idx(max_val+1);
  vector<pair<int,int>> edges;
  for (int i = 1; i <= n; ++i) {
    int x = a[i];

    vector<int> primes;
    for (int d = 2; d*d <= x; ++d) {
      if (x % d == 0) {
        while (x % d == 0) {
          x /= d;
        }
        primes.push_back(d);
      }
    }

    if (x > 1) {
      primes.push_back(x);
    }

    for (int p : primes) {
      prime2idx[p].push_back(a[i]);
      all_primes[a[i]].push_back(p);
    }
  }

  for (vector<int>& next_nodes : prime2idx) {
    sort(next_nodes.begin(), next_nodes.end());
    next_nodes.erase(unique(next_nodes.begin(), next_nodes.end()), next_nodes.end());
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << a[i] << ": ";
  //   for (int p : all_primes[a[i]]) cout << p << " ";
  //   cout << endl;;
  // }

  vector<int> parent(max_val+1, -1);
  vector<bool> vp(max_val+1);
  vector<bool> va(max_val+1);
  queue<int> q;
  q.push(a[s]);
  va[a[s]] = true;

  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int val = q.front();
      q.pop();

      for (int p : all_primes[val]) {
        if (vp[p]) continue;
        vp[p] = true;
        
        for (int val2 : prime2idx[p]) {
          if (va[val2]) continue;
          va[val2] = true;

          q.push(val2);
          parent[val2] = val;
        }
      }
    }
  }

  vector<int> path = {t};
  int node = a[t];
  while (parent[node] >= 0) {
    int p = parent[node];
    path.push_back(index[p]);
    node = p;
  }

  if (node != a[s]) {
    cout << "-1" << endl;
  } else {
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    cout << s << " ";
    for (int i = 1; i < path.size(); ++i) {
      cout << path[i] << " ";
    }
    cout << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

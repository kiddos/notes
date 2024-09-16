#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n+1);
  for (int i = 2; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }

  vector<int> current_p(n+1);
  vector<vector<int>> children_index(n+1);
  function<void(int,int,int)> dfs = [&](int l, int r, int parent) {
    int root = l;
    current_p[p[root]] = p[parent];
    if (l != r) {
      int children_size = (r - l) / 2;
      dfs(l + 1, l + children_size, root);
      dfs(l + children_size + 1, r, root);
      children_index[root] = {l+1, l + children_size + 1};
    }
  };

  dfs(1, n, 0);

  vector<int> correct_p = a;

  // cout << "initial: " << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << current_p[i] << " ";
  // }
  // cout << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << correct_p[i] << " ";
  // }
  // cout << endl;

  set<int> incorrect;
  for (int i = 1; i <= n; ++i) {
    int node = p[i];
    if (current_p[node] != correct_p[node]) {
      incorrect.insert(node);
    }
  }

  auto update_correct = [&](int idx1) {
    int node = p[idx1];
    if (correct_p[node] != current_p[node]) {
      incorrect.insert(node);
    } else {
      incorrect.erase(node);
    }
    for (int child : children_index[idx1]) {
      if (node != correct_p[p[child]]) {
        incorrect.insert(p[child]);
      } else{
        incorrect.erase(p[child]);
      }
    }
  };

  for (int i = 0; i < q; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;

    // cout << "query: " << i << endl;
    for (int idx : children_index[x]) {
      current_p[p[idx]] = p[y];
    }
    for (int idx : children_index[y]) {
      current_p[p[idx]] = p[x];
    }

    swap(current_p[p[x]], current_p[p[y]]);
    swap(p[x], p[y]);
    update_correct(x);
    update_correct(y);

    // cout << "incorrect: " << incorrect.size() << endl;
    if (incorrect.size() == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }

    // cout << "current:" << endl;
    // for (int i = 1; i <= n; ++i) {
    //   cout << p[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; ++i) {
    //   cout << current_p[i] << " ";
    // }
    // cout << endl << "correct:" << endl;
    // for (int i = 1; i <= n; ++i) {
    //   cout << correct_p[i] << " ";
    // }
    // cout << endl << endl;
  }
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

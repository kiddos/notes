#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 100000;

int n = 0, m = 0;
int block_size = 0;
int a[MAX_N];
int last[MAX_N];
int jumps[MAX_N];
int next_node[MAX_N];
bool updated[MAX_N] = {false};

void dfs(int i) {
  if (updated[i]) {
    return;
  }
  updated[i] = true;
  // cout << "update node:" << i << endl;

  int b1 = i / block_size;
  if (i + a[i] >= n) {
    last[i] = i;
    jumps[i] = 0;
    next_node[i] = n;
  } else {
    int i2 = i+a[i];
    int b2 = i2 / block_size;
    if (b2 == b1) {
      last[i] = last[i2];
      jumps[i] = jumps[i2]+1;
      next_node[i] = i2;
    } else {
      last[i] = i;
      jumps[i] = 0;
      next_node[i] = i2;
    }
  }
};

pair<int,int> move(int i) {
  if (i == last[i]) {
    if (next_node[i] >= n) {
      return {i, 1};
    } else {
      auto result = move(next_node[i]);
      return {result.first, result.second+1};
    }
  } else {
    auto result = move(last[i]);
    return {result.first, result.second + jumps[i]};
  }
};

void update_block(int b) {
  int start = -1, end = -1;
  for (int j = 0; j < block_size; ++j) {
    int i = b * block_size + j;
    if (start < 0) {
      start = i;
    }
    end = i;
    if (i >= n) {
      break;
    }
    updated[i] = false;
  }
  // cout << "update block..." << endl;
  for (int i = end; i >= start; --i) {
    dfs(i);
  }
};

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  block_size = sqrt(n);

  for (int i = n-1; i >= 0; --i) {
    dfs(i);
  }

  for (int i = 0; i < m; ++i) {
    int type = 0;
    cin >> type;
    if (type == 0) {
      int node = 0, power = 0;
      cin >> node >> power;
      node--;
      a[node] = power;
      update_block(node / block_size);
    } else if (type == 1) {
      int node = 0;
      cin >> node;
      node--;
      auto [last_node, jump] = move(node);
      cout << last_node+1 << " " << jump << '\n';
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

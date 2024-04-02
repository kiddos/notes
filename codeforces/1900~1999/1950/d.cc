#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 100000;
vector<bool> is_prod(MAX_N+1);

bool is_binary_decimal(int x) {
  string s = to_string(x);
  for (char ch : s) if (ch != '0' && ch != '1') {
    return false;
  }
  return true;
}

void precompute() {
  vector<int> bd;
  for (int i = 0; i <= MAX_N; ++i) {
    if (is_binary_decimal(i)) {
      bd.push_back(i);
    }
  }

  queue<int> q;
  for (int x : bd) {
    q.push(x);
    is_prod[x] = true;
  }

  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      i64 x = q.front();
      q.pop();
      for (i64 y : bd) {
        i64 z = x * y;
        if (z > MAX_N) continue;
        if (is_prod[z]) continue;

        is_prod[z] = true;
        q.push(z);
      }
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;
  if (is_prod[n]) {
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 power(i64 x, i64 n, i64 mod) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= mod;
    }
    n >>= 1;
    x = x * x;
    x %= mod;
  }
  return ans;
}

void solve() {
  int N = 0;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  vector<int> B(N);
  for (int i = 0; i < N; ++i) cin >> B[i];

  int M = 0;
  cin >> M;
  vector<int> C(M);
  for (int i = 0; i < M; ++i) cin >> C[i];
  vector<int> D(M);
  for (int i = 0; i < M; ++i) cin >> D[i];

  map<int,int> X, Y;
  for (int i = 0; i < N; ++i) {
    X[A[i]] = B[i];
  }
  for (int i = 0; i < M; ++i) {
    Y[C[i]] = D[i];
  }

  auto possible = [&](map<int,int>& x, map<int,int>& y) {
    for (auto& [p, e] : y) {
      if (x.count(p)) {
        if (x[p] < e) {
          return false;
        }
      } else {
        return false;
      }
    }
    return true;
  };

  auto compute = [&](map<int,int>& x, map<int,int>& y) -> int {
    int count = 0;
    for (auto& [p, e] : x) {
      if (e > y[p]) {
        count++;
      }
    }
    return count;
  };

  constexpr int MOD = 998244353;
  if (possible(X, Y)) {
    int count = compute(X, Y);
    i64 ans = power(2, count, MOD);
    cout << ans << endl;
  } else {
    cout << "0" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

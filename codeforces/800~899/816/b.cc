#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 200000;

void solve() {
  int n = 0, k = 0, q = 0;
  cin >> n >> k >> q;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }
  vector<int> a(q), b(q);
  for (int i = 0; i < q; ++i) {
    cin >> a[i] >> b[i];
  }

  vector<int> line(MAX_N+2);
  for (int i = 0; i < n; ++i) {
    line[l[i]]++;
    line[r[i]+1]--;
  }

  for (int i = 0, current = 0; i<= MAX_N; ++i) {
    current += line[i];
    line[i] = current >= k;
  }

  vector<int> p = line;
  for (int i = 1; i <= MAX_N; ++i) {
    p[i] += p[i-1];
  }

  for (int i = 0; i < q; ++i) {
    int count = p[b[i]] - p[a[i]-1];
    cout << count << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

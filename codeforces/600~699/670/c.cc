#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int m = 0;
  cin >> m;
  vector<int> b(m), c(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> c[i];
  }

  map<int,int> lan;
  for (int i = 0; i < n; ++i) {
    lan[a[i]]++;
  }

  vector<array<int,3>> movies;
  for (int i = 0; i < m; ++i) {
    int very = lan.count(b[i]) ? lan[b[i]] : 0;
    int almost = lan.count(c[i]) ? lan[c[i]] : 0;
    movies.push_back({very, almost, i+1});
  }
  sort(movies.rbegin(), movies.rend());
  cout << movies[0][2] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0, t = 0;
  cin >> n >> m >> k >> t;
  vector<vector<int>> waste(n+1);
  for (int i = 0; i < k; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    waste[a].push_back(b);
  }

  for (int r = 1; r <= n; ++r) {
    sort(waste[r].begin(), waste[r].end());
  }

  vector<int> waste_count(n+1);
  for (int i = 1; i <= n; ++i) {
    waste_count[i] = waste_count[i-1] + waste[i].size();
  }

  vector<string> crops = {"Carrots", "Kiwis", "Grapes"};
  for (int i = 0; i < t; ++i) {
    int r = 0, c = 0;
    cin >> r >> c;

    auto it = upper_bound(waste[r].begin(), waste[r].end(), c);
    int count = it - waste[r].begin();
    count += waste_count[r-1];

    int total = (r-1) * m + c - count;

    if (it != waste[r].begin()) {
      --it;
      if (*it == c) {
        cout << "Waste" << endl;
      } else {
        cout << crops[(total-1)%3] << endl;
      }
    } else {
      cout << crops[(total-1)%3] << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

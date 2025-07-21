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

  map<int, int> count;
  for (int i = 1; i < n; ++i) {
    int diff = a[i] - a[i-1];
    count[diff]++;
  }
  while (count.size() > 1) {
    map<int,int> count2;
    for (auto [x, c] : count) {
      if (c > 1) {
        count2[0] += c-1;
      }
    }

    for (auto it = next(count.begin()); it != count.end(); ++it) {
      int diff = it->first - prev(it)->first;
      count2[diff]++;
    }
    count = std::move(count2);
  }
  if (count.begin()->second > 1) {
    cout << "0" << endl;
  } else {
    cout << count.begin()->first << endl;
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

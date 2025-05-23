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
  map<int,int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  for (auto [day, c] : count) {
    if (c >= 4) {
      cout << "YES" << endl;
      return;
    }
  }
  vector<pair<int,int>> days(count.begin(), count.end());
  int size = days.size();
  int i = 0;
  while (i < size) {
    int j = i;
    while (j+1 < size && days[j+1].first == days[j].first+1) {
      j++;
    }
    int with_two_guess = 0;
    for (int k = i; k <= j; ++k) {
      if (days[k].second >= 2) {
        with_two_guess++;
      }
    }
    if (with_two_guess >= 2) {
      cout << "YES" << endl;
      return;
    }
    i = j+1;
  }

  cout << "NO" << endl;
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

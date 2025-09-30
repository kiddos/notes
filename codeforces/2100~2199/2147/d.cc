#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  map<i64,i64> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }

  vector<pair<i64,i64>> odd;
  i64 even_sum = 0;
  for (auto [ai, c] : count) {
    if (ai % 2 == 1) {
      odd.push_back({c, ai});
    } else {
      even_sum += c * ai;
    }
  }

  sort(odd.rbegin(), odd.rend());
  i64 alice = 0, bob = 0;
  int size = odd.size();
  for (int i = 0; i < size; ++i) {
    if (i % 2 == 0) {
      alice += odd[i].first;
    } else {
      bob += odd[i].first;
    }
    even_sum += (odd[i].second-1) * odd[i].first;
  }
  alice += even_sum / 2;
  bob += even_sum / 2;

  cout << alice << " " << bob << endl;
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

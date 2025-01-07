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

  // if number is not distinct
  // the answer is false
  set<i64> s(a.begin(), a.end());
  if (s.size() != a.size()) {
    cout << "NO" << endl;
    return;
  }

  auto pigeon_hole = [&](int p) -> bool {
    vector<int> count(p);
    for (int i = 0; i < n; ++i) {
      count[a[i] % p]++;
    }
    return *min_element(count.begin(), count.end()) >= 2;
  };

  bool valid = true;
  for (int prime = 2; prime <= n / 2; ++prime) {
    if (pigeon_hole(prime)) {
      valid = false;
      break;
    }
  }

  if (valid) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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

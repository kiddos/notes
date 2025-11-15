#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string a, b;
  cin >> a >> b;
  map<char,int> count_a;
  for (int i = 0; i < n; ++i) {
    count_a[a[i]]++;
  }
  map<char,int> count_b;
  for (int i = 0; i < n; ++i) {
    count_b[b[i]]++;
  }
  for (auto& [ca, count] : count_a) {
    auto it = count_b.begin();
    char cb = it->first;
    if (cb < ca) {
      cout << "NO" << endl;
      return;
    } else if (ca == cb) {
      if (it->second > count) {
        cout << "NO" << endl;
        return;
      }
      int left = count - it->second;
      count_b.erase(it);
      if (left % k == 0) {
        if (left > 0) {
          count_a[ca+1] += left;
        }
      } else {
        cout << "NO" << endl;
        return;
      }
    } else if (ca < cb) {
      if (count % k != 0) {
        cout << "NO" << endl;
        return;
      }
      count_a[ca+1] += count;
    }
  }
  cout << "YES" << endl;
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

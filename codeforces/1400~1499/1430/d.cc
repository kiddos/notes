#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void find_answer(vector<int>& a) {
  int n = a.size();
  set<int> two, one;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 1) {
      two.insert(i);
    } else {
      one.insert(i);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      continue;
    }

    if (a[i] > 1) {
      ans++;
    } else {
      while (!one.empty() && *one.begin() < i) {
        one.erase(one.begin());
      }
      while (!two.empty() && *two.begin() < i) {
        two.erase(two.begin());
      }

      if (!two.empty()) {
        auto idx = *two.begin();
        a[idx]--;
        if (a[idx] == 1) {
          two.erase(two.begin());
          one.insert(idx);
        }
      } else if (!one.empty()) {
        auto idx = *one.rbegin();
        one.erase(prev(one.end()));
        a[idx]--;
      }

      ans++;
    }
  }

  cout << ans << endl;
}

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  vector<int> sizes;
  int i = 0;
  while (i < n) {
    int j = i;
    while (j+1 < n && s[j+1] == s[j]) {
      j++;
    }
    int len = j-i+1;
    i = j+1;
    sizes.push_back(len);
  }

  find_answer(sizes);
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

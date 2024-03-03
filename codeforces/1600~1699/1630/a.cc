#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

//  0 0000
//  1 0001
//  2 0010
//  3 0011
//  4 0100
//  5 0101
//  6 0110
//  7 0111
//  8 1000
//  9 1001
// 10 1010
// 11 1011
// 12 1100
// 13 1101
// 14 1110
// 15 1111

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  int msb = 0;
  for (int i = 0; i <= 16; ++i) {
    if (n & (1<<i)) {
      msb = i;
      break;
    }
  }

  auto complement = [&](int x) -> int {
    int ans = 0;
    for (int b = msb-1; b >= 0; --b) {
      if (!(x & (1<<b))) {
        ans |= (1<<b);
      }
    }
    return ans;
  };

  vector<pair<int,int>> ans;
  if (k == 0) {
    int l = 0, r = n-1;
    while (l < r) {
      ans.emplace_back(l++, r--);
    }
  } else if (k == n-1) {
    if (n == 4) {
      cout << "-1" << endl;
      return;
    }

    ans.emplace_back(n-1, n-2);
    ans.emplace_back(1, 3);
    ans.emplace_back(complement(3), 0);
    vector<bool> used(n);
    used[n-1] = used[n-2] = used[0] = used[1] = used[3] = used[complement(3)] = true;
    for (int i = 0; i < n; ++i) if (!used[i]) {
      ans.emplace_back(i, complement(i));
      used[i] = used[complement(i)] = true;
    }
  } else {
    vector<bool> used(n);
    ans.emplace_back(k, n-1);
    ans.emplace_back(complement(k), 0);
    used[k] = used[complement(k)] = used[0] = used[n-1] = true;
    for (int i = 0; i < n; ++i) if (!used[i]) {
      ans.emplace_back(i, complement(i));
      used[i] = used[complement(i)] = true;
    }
  }

  for (auto& [a, b] : ans) {
    cout << a << " " << b << endl;
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

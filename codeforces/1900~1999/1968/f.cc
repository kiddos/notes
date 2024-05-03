#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_BIT = 30;

// x = g1 ^ g2 ^ g3 ^ g4 ^ g5
// if g1 == g2 == g3 == g4 == g5
// x = g ^ g ^ g ^ g ^ g
// so x = g
// each segment should be x
//
// so only need to think about group of 2 or 3
// since if the group can be divide into 5, 7, 9, it can also be 3
// if the group can be divide into 4, 6, 8, it can also be 2

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<vector<int>> bits(n+1, vector<int>(MAX_BIT+1));
  for (int i = 1; i <= n; ++i) {
    for (int b = 0; b <= MAX_BIT; ++b) {
      bits[i][b] += bits[i-1][b];
      if (a[i] & (1<<b)) {
        bits[i][b]++;
      }
    }
  }

  auto find_one = [&](int l, int r) -> bool {
    for (int b = 0; b <= MAX_BIT; ++b) {
      int sum = bits[r][b] - bits[l-1][b];
      if (sum == 1) {
        return true;
      }
    }
    return false;
  };

  vector<int> px(n+1);
  for (int i = 1; i <= n; ++i) {
    px[i] = px[i-1] ^ a[i];
  }

  map<int, vector<int>> indices;
  for (int i = 0; i <= n; ++i) {
    indices[px[i]].push_back(i);
  }

  auto find = [&](vector<int>& arr, int upper) -> int {
    int size = arr.size();
    int l = 0, r = size-1;
    int idx = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (arr[mid] <= upper) {
        idx = arr[mid];
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    return idx;
  };

  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    if (find_one(l, r)) {
      cout << "NO" << endl;
      continue;
    }
    int x = px[r] ^ px[l-1];
    int x2 = px[r] ^ x;
    int idx = find(indices[x2], r);
    if (idx < l || idx > r) {
      cout << "NO" << endl;
      continue;
    }
    
    int x3 = px[idx] ^ px[l-1];
    // x3 must be x or 0
    if (x3 == x) {
      // size of 2
      cout << "YES" << endl;
    } else if (x3 == 0) {
      // this is possibly group of 3
      int x4 = px[idx] ^ x;
      int idx2 = find(indices[x4], idx);
      if (idx2 >= l && idx2 <= idx) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  cout << endl;
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

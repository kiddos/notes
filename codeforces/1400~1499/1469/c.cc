#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  priority_queue<pair<int,int>, vector<pair<int,int>>, less<>> pq;
  for (int i = 0; i < n; ++i) {
    pq.push({h[i], i});
  }

  vector<i64> assigned(n, -1);
  while (!pq.empty()) {
    auto [hi, i] = pq.top();
    pq.pop();
    if (assigned[i] >= 0) {
      continue;
    }

    queue<int> q;
    q.push(i);
    assigned[i] = 0;
    while (!q.empty()) {
      int idx = q.front();
      q.pop();

      i64 first_block = h[idx] + assigned[idx] + 1;
      for (int d : {-1, 1}) {
        int idx2 = idx + d;
        if (idx2 < 0 || idx2 >= n || h[idx2] > h[idx]) {
          continue;
        }

        if (assigned[idx2] >= 0) {
          if (h[idx2] + k - 1 + k < first_block) {
            cout << "No" << endl;
            return;
          }
        } else {
          i64 require_height = first_block - k + 1;
          i64 require_assignment = max(require_height - h[idx2] - 1, 0LL);
          if (require_assignment > k-1) {
            cout << "NO" << endl;
            return;
          }
          assigned[idx2] = require_assignment;
          q.push(idx2);
        }
      }
    }
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << assigned[i] << " ";
  // }
  // cout << endl;

  if (assigned[0] != 0 || assigned[n-1] != 0) {
    cout << "NO" << endl;
    return;
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  if (k % 2 == 1) {
    for (int i = 0; i < k; ++i) {
      cout << n << " ";
    }
    cout << endl;
    return;
  }

  // now k is even
  // if ith bit is 1, one of index cannot have that bit
  // if ith bit is 0, we want to try to insert as many 1 as possible,
  //  but the count must be even
  // we should do the following greedy:
  // if ith bit is 1, move 1 of the index to a set, where we can add as many 1 as possible
  deque<int> indices;
  for (int i = 0; i < k; ++i) {
    indices.push_back(i);
  }
  vector<int> greedy;
  vector<int> a(k);
  for (int b = 30; b >= 0; --b) {
    if (n & (1<<b)) {
      if (!indices.empty()) {
        int idx = indices.front();
        indices.pop_front();
        for (int i = 0; i < k; ++i) {
          if (i == idx) {
            continue;
          }
          a[i] |= (1<<b);
        }
        greedy.push_back(idx);
      } else {
        // we still need to exclude 1 index to not have this bit
        for (int i = 0; i < k-1; ++i) {
          a[i] |= (1<<b);
        }
      }
    } else {
      int size = greedy.size() / 2 * 2;
      for (int i = 0; i < size; ++i) {
        a[greedy[i]] |= (1<<b);
      }
    }
  }

  for (int i = 0; i < k; ++i) {
    cout << a[i] << " ";
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 11000 X -> Alice can select 1000
// 1100
// 00011110011111100
// =>
// some 0 -> even number of 1 -> even number of 0
//        -> even number of 1 -> even number of 0 -> 
//        ... -> some 1

bool will_lose(vector<pair<int,int>>& p) {
  int size = p.size();
  for (int i = 0; i < size; ++i) {
    if (i == 0 && p[i].first == 0) {
      continue;
    }
    if (i == size-1 && p[i].first == 1) {
      continue;
    }

    if (p[i].first == 1) {
      if (p[i].second % 2 == 1) {
        return false;
      }
    } else if (p[i].first == 0) {
      if (p[i].second % 2 == 1) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int idx = 0;
  vector<pair<int,int>> p;
  while (idx < n) {
    int j = idx;
    while (j+1 < n && s[j+1] == s[j]) {
      j++;
    }
    int len = j-idx+1;
    p.push_back({s[idx]-'0', len});
    idx = j+1;
  }

  if (will_lose(p)) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
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

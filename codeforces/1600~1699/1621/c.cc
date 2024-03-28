#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// p  = [4, 2, 1, 3]
// q1 = [1, 2, 3, 4]
// q2 = [4, 2, 1, 3]
// q3 = [3, 2, 4, 1]
// q4 = [1, 2, 3, 4]
//
// p =  [1, 3, 4, 2]
// q =  [1, 2, 3, 4]
// q =  [1, 3, 4, 2]
// q =  [1, 4, 2, 3]
// q =  [1, 2, 3, 4]

int query(int idx) {
  cout << "? " << idx << endl;
  int output = 0;;
  cin >> output;
  return output;
}

void answer(vector<int>& a) {
  cout << "! ";
  for (int i = 1; i < (int)a.size(); ++i) cout << a[i] << " ";
  cout << endl;
}

void solve() {
  int n = 0;
  cin >> n;

  int offset = 0;
  vector<bool> visited(n+1);
  vector<int> ans(n+1);

  for (int i = 1; i <= n; ++i) {
    if (visited[i]) continue;

    int o = offset;
    vector<int> group;
    int x = i;
    while (true) {
      x = query(i);
      if (visited[x]) break;
      visited[x] = true;
      offset++;
      group.push_back(x);
    }

    int size = group.size();
    for (int i = 0, j = (o+1); i < size; ++i, ++j) {
      ans[group[j % size]] = group[(j+1) % size];
    }
  }

  answer(ans);
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

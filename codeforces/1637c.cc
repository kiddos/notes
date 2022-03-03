#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL solve(vector<int>& a) {
  set<int> not_ok;
  queue<int> q;
  int n = a.size();
  for (int i = 1; i < n-1; ++i) {
    if (a[i] % 2 == 1) not_ok.insert(i);
    q.push(i);
  }

  LL ans = 0;
  while (!q.empty()) {
    int index = q.front();
    q.pop();
    LL supply = a[index] / 2;
    bool left_over = a[index] % 2 == 1;
    ans += supply;
    while (supply) {
      bool found = false;
      if (!not_ok.empty() && *not_ok.begin() < index) {
        int next_index = *not_ok.begin();
        a[next_index]++;
        q.push(next_index);
        not_ok.erase(next_index);
        found = true;
      }

      if (!not_ok.empty() && *not_ok.rbegin() > index) {
        int next_index = *not_ok.rbegin();
        a[next_index]++;
        q.push(next_index);
        not_ok.erase(next_index);
        found = true;
      }

      if (found) {
        supply--;
      } else {
        break;
      }
    }

    if (left_over){
      a[index] = 1;
      not_ok.insert(index);
    } else {
      a[index] = 0;
    }
  }

  if (not_ok.size() > 0) {
    return -1;
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    LL ans = solve(a);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}

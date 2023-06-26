#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> building(n);
  for (int i = 0; i < n; ++i) cin >> building[i];

  auto find_min = [&](string& floor) -> int {
    int i = 0;
    vector<int> lens;
    while (i < m) {
      if (floor[i] == '1') {
        int j = i+1;
        while (j < m && floor[j] == '1') {
          j++;
        }
        lens.push_back(j - i);
        i = j;
      } else {
        i++;
      }
    }

    int two = m / 4, one = m / 2;
    int ans = 0;
    for (int len : lens) {
      int t = min(two, len / 2);
      two -= t;
      ans += t;

      int o = min(len - t * 2, one);
      one -= o;
      ans += o;
    }
    return ans;
  };

  auto find_max = [&](string& floor) -> int {
    int i = 0;
    int two = 0;
    // count number of two-bedroom with 1 or 0 lights on
    // so the number of two-bedroom with 2 lights on will be m / 4 - this number
    while (i < m-1) {
      if (floor[i] != '1' || floor[i+1] != '1') {
        i += 2;
        two++;
      } else {
        i++;
      }
    }
    two = min(two, m / 4);
    int on = 0;
    for (int i = 0; i < m; ++i) {
      on += floor[i] == '1';
    }
    // ans will be total lights on - number of two-bedroom with 2 lights on
    return on - (m / 4 - two);
  };

  int max_val = 0, min_val = 0;
  for (int f = 0; f < n; ++f) {
    min_val += find_min(building[f]);
    max_val += find_max(building[f]);
  }

  cout << min_val << " " << max_val << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

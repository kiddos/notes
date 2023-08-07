#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

char type1(int i) {
  cout << "? 1 " << i << endl;
  char ch = '\0';
  cin >> ch;
  return ch;
}

int type2(int l, int r) {
  cout << "? 2 " << l << " " << r << endl;
  int count = 0;
  cin >> count;
  return count;
}

void answer(const string& s) {
  cout << "! " << s << endl;
}

void solve() {
  int n = 0;
  cin >> n;

  string ans(n+1, ' ');
  vector<int> last_occur;
  for (int i = 1; i <= n; ++i) {
    if (i == 1) {
      char ch = type1(1);
      ans[i] = ch;
      last_occur.push_back(i);
    } else {
      int size = last_occur.size();
      int l = 0, r = size-1;
      // find the last index j where
      // count(j, i) == count(j, i-1)
      int s = -1;
      while (l <= r) {
        int mid = l + (r-l) / 2;
        int count = type2(last_occur[mid], i);
        if (count <= size - mid) {
          s = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }

      if (s == -1) {
        char ch = type1(i);
        ans[i] = ch;
        last_occur.push_back(i);
      } else {
        ans[i] = ans[last_occur[s]];
        last_occur[s] = i;
        sort(last_occur.begin(), last_occur.end());
      }
    }
  }

  ans = ans.substr(1);
  answer(ans);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

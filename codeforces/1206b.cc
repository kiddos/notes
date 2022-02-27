#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) cin >> nums[i];

  long long pos = 0, neg = numeric_limits<int>::max();
  for (int num : nums) {
    long long p = min(pos + abs(num-1), neg + abs(num+1));
    long long n = min(pos + abs(num+1), neg + abs(num-1));
    pos = p;
    neg = n;
  }
  cout << pos << endl;
  return 0;
}

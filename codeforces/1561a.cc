#include <bits/stdc++.h>

using namespace std;

bool sorted(vector<int>& arr) {
  int n = arr.size();
  for (int i = 0; i < n; ++i) {
    if (arr[i] != i+1) return false;
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    int it = 1;
    while (!sorted(arr)) {
      if (it % 2 == 1) {
        for (int i = 1; i < n-1; i+=2) {
          if (arr[i-1] > arr[i]) {
            swap(arr[i-1], arr[i]);
          }
        }
      } else {
        for (int i = 2; i < n; i+=2) {
          if (arr[i-1] > arr[i]) {
            swap(arr[i-1], arr[i]);
          }
        }
      }
      it++;
    }
    cout << it-1 << endl;
  }
  return 0;
}

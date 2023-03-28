#include <bits/stdc++.h>
#define int int64_t
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
using namespace std;
 
const int N = 555;

int32_t main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> a(n + 1),b(n + 1),rem(n + 1),x(n + 1);
  for (int i = 1;i <= n;i++) {
    cin >> a[i];
  }
  for (int i = 1;i <= n;i++) {
    cin >> b[i];
    x[i] = b[i];
  }
  int tq;
  cin >> tq;
  int time = 0,cnt = 0;
  vector<int> ct(n + 1,0),wt(n + 1,0),tat(n + 1,0);

  int tot = 0;
  while (1) {
    int cnt = 0;
    for (int i = 1;i <= n;i++) {
      int temp = tq;
      if (x[i] == 0) {
        cnt++;
        continue;
      }

      if (x[i] > tq) {
        x[i] -= tq;
      }else {
        if (x[i] >= 0) {
          temp = x[i];
          x[i] = 0;
        }
      }
      tot += temp;
      tat[i] = tot - a[i];
    }
    if (cnt == n) break;
  }
  double tot1 = 0,tot2 = 0;
  for (int i = 1;i <= n;i++) {
    wt[i] = tat[i] - b[i];
    tot1 += tat[i];
    tot2 += wt[i];
  }
  tot1 = tot1 / (n * 1.0);
  tot2 = tot2 / (n * 1.0);
  cout << "Average turn around time: " << tot1 << '\n';
  cout << "Average waiting time: " << tot2 << '\n';
  return 0;
}

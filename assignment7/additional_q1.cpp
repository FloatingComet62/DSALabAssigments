#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) std::cin >> a[i];
  int mn = a[0], mx = a[0];
  for (int i = 1; i < n;i++) {
    if (a[i] < mn) mn = a[i];
    if (a[i] > mx) mx = a[i];
  }
  int range = mx - mn + 1;
  int cnt[range];
  for (int i = 0; i < range; i++) cnt[i] = 0;
  for (int i = 0; i < n; i++) cnt[a[i] - mn]++;
  for (int i = 0; i < range; i++) {
    while(cnt[i]--)
      std::cout << i + mn << " ";
  }
  return 0;
}

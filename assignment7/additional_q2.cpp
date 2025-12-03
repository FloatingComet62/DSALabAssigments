#include <iostream>

int getMax(int a[], int n) {
  int mx = a[0];
  for(int i = 1; i < n; i++)
    if (a[i] > mx) mx = a[i];
  return mx;
}

void countSort(int a[], int n, int exp) {
  int output[n];
  int cnt[10];
  for (int i = 0; i < 10; i++) cnt[i] = 0;
  for (int i = 0; i < n; i++) cnt[(a[i] / exp) % 10]++;
  for (int i = 1; i < 10; i++) cnt[i] += cnt[i - 1];
  for (int i = n-1; i >= 0;i--) {
    int digit = (a[i] / exp) % 10;
    output[cnt[digit] - 1] = a[i];
    cnt[digit]--;
  }
  for(int i = 0;i < n; i++) a[i] = output[i];
}

void radixSort(int a[], int n){
  int mx = getMax(a,n);
  for (int exp = 1; mx / exp > 0; exp *= 10)
    countSort(a,n,exp);
}

int main(){
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) std::cin >> a[i];
    radixSort(a,n);
    for (int i = 0; i < n; i++) std::cout << a[i] << " ";
    return 0;
}

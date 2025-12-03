#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr) {
  int n = arr.size();
  for (int i = 0; i < n-1; i++) {
    int minIndex = i;
    for(int j = i+1; j < n; j++) {
      if(arr[j] < arr[minIndex]) minIndex = j;
    }
    std::swap(arr[i], arr[minIndex]);
  }
}

void insertionSort(std::vector<int>& arr) {
  int n = arr.size();
  for(int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

void bubbleSort(std::vector<int>& arr) {
  int n = arr.size();
  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
  std::vector<int> temp;
  int i = left, j = mid+1;

  while (i <= mid && j <= right) {
    if (arr[i] < arr[j]) temp.push_back(arr[i++]);
    else temp.push_back(arr[j++]);
  }
  while (i <= mid) temp.push_back(arr[i++]);
  while (j <= right) temp.push_back(arr[j++]);

  for (int k = 0; k < temp.size(); k++)
    arr[left + k] = temp[k];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
  if (left >= right) return;
  int mid = (left + right) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid+1, right);
  merge(arr, left, mid, right);
}

void quickSort(std::vector<int>& arr, int low, int high) {
  if(low >= high) return;

  int pivot = arr[high];
  int i = low - 1;
  for(int j = low; j < high; j++) {
    if(arr[j] >= pivot) continue;
    i++;
    std::swap(arr[i], arr[j]);
  }
  std::swap(arr[i+1], arr[high]);

  quickSort(arr, low, i);
  quickSort(arr, i + 2, high);
}

int main() {
  std::vector<int> arr = {64, 25, 12, 22, 11};
  std::cout << "Original array: ";
  for(int x : arr) std::cout << x << "\n";

  selectionSort(arr);
  insertionSort(arr);
  bubbleSort(arr);
  mergeSort(arr, 0, arr.size()-1);
  quickSort(arr, 0, arr.size()-1);

  std::cout << "Sorted array: ";
  for(int x : arr) std::cout << x << "\n";
  return 0;
}

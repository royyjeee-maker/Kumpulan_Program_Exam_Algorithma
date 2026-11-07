#include <stdio.h>
 void modify(int *arr, int n) {
 int i;
 for (i = 0; i < n; i++) {
 if (i % 2 == 0)
 arr[i] = arr[i] * 2;
 else
 arr[i] = arr[i] + 1;
 }
 }
 int main() {
 int data[6] = {3, 4, 5, 6, 7, 8};
 int i, total = 0;
 modify(data, 6);
 for (i = 0; i < 6; i++) {
 total += data[i];
 printf("data[%d]=%d\n", i, data[i]);
 }
 printf("total=%d\n", total);
 printf("%s\n", total % 2 == 0 ? "genap" : "ganjil");
 return 0;
 }

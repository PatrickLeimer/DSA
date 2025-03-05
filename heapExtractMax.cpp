#include <iostream>
using namespace std;

int* extractMax(int arr[], int size)
{
    // code here
    // cout << arr[0] << " size: " << size << endl;
    // 2p + 1 -> 2p + 2      
    int i = 0;
    arr[i] = arr[--size];
    while(true) {
      int root = i;
      int l = 2 * i + 1;
      int r = 2 * i + 2;

      if(l < size & arr[l] > arr[root]) {
        root = l;
      }
      if (r < size & arr[r] > arr[root]) {
        root = r;
      }
      if (root == i) {
        break;
      } else {
        int temp = arr[root];
        arr[root] = arr[i];
        arr[i] = temp;
        i = root;
      }

      
    }

    // main prints the final heap array from 0 to size - 2
	// you don't need to print the array but instead return
	return arr; 
}
#include <iostream>
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void  bubbleSort(int arr[]){
    int k = 5;
   for(int i = 0; i < 4; i++){
      for(int j = 0; j < k; j++){
if(arr[j] > arr[j+1]){
    swap(arr[j],arr[j+1]);
}

      }
      k--;
   }
}
int main(){
    int arr[5] = {
        2,1,4,5,3
    };
//    int N = 3;
    bubbleSort(arr);
    for(int i = 0; i < 5; i++){
        cout << arr[i] << endl;
    }
}

// traverse from left and compare adjacent elements and the higher one is placed at right side
// eg 2 1 4 5 3
// first we check if j+1 is greater than j if yes swap so now  1 2 4 5 3
// now 4 is not greater than 2 so j++ now check 4 is greater than 5 is yes j++ now check if 5 is greater than 3 
// if yes then swap them so now 1 2 4 3 5 and we do k-- because the largest that is 5 will be placed in the right position 
// now i ++ check 2 > 4 so not if 

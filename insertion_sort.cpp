#include <iostream>
using namespace  std;
void insertionSort(int arr[])
{
    int key;
    int j;
    for(int i = 1 ; i < 5; i++){
        key = arr[i];
        j = i - 1;
        while(arr[j] > key && j >= 0){
        arr[j + 1] = arr[j];
        j--;
        
        }
        arr[j+1] = key;
    }   
}
int main()
{
    int arr[5] = {2,5,1,3,9};
    insertionSort(arr); 
    for(int i = 0; i < 5; i++){
        cout << arr[i] << endl;
    }
} // namespace  std;


// eg 2 5 1 3 9
// first check 2 is greater than 5 or not if not i ++ check 1 is greater than 5 or not if yes
// move 1 to left side such that the element less than 1 will be in sorter order
// now the new series will be 1 2 5 3 9 .
// now again i++ 3 is greater than 5 so insert 3 such that the elemnt before 3 are all sorted 
// now the series will be 1 2 3 5 9
// selection short
// bubble short
// insertion short
// merge short
// quick sort long

#include <iostream>
#include <climits>
using namespace std;
int min(int arr[] , int i,int min){
    min = i;
    for(int j = i+1 ; j < 5; j ++){
        if(arr[min] > arr[j]){
           min = j;
        }
    }
    return min;

}
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void selectionSort(int arr[])
{
    int mini = INT_MAX;
    for(int i = 0; i < 5; i++){
       mini = min (arr,i,mini);
       swap(arr[i], arr[mini]);
    }
} // namespace std;

int main(){
    int arr[5] = {4,1,5,9,1};

    selectionSort(arr);
    for(int i = 0 ; i < 5 ; i++){
        cout << arr[i] << endl;
    }
}

// select the min element from the array and swap it if the first element
// eg 4 1 9 5 1
// the min elemetn is 1 so swap it with 4 and 1  then i ++ so now 1 4 9 5 1 
// the min element is again 1 so swap it with 4 and 1 then i++ so now 1 1 4 9 5
// the min elemtn is 4 so no swaping  and i++
// the min element is 5 so swap it with i that is 9 



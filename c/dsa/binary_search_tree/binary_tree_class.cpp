#include <iostream>
using namespace std;










int main(){
    BinaererSuchbaum test;
    int arr[] = {10, 4, 6, 15, 13, 12, 15, 20, 11, 15};
    for(int i=0; i<10; i++){
        test.insert(arr[i]);
    }
    test.display();
}

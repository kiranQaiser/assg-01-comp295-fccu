#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void ArrayMaking(int array[][4]) {// declaring array(2d)//a,array willl represent the grid 
    
    for (int i = 0; i < 4; i++) {// loop iterates over the rows
        for (int j = 0; j < 4; j++) {//loop iterates over the col
                array[i][j] = 0;// sets the value of the element at that position to 0.
            }}
    }
void print(int a[][4]) {
    for (int i = 0; i < 4; i++) {
        cout << "|------|------|------|------|" << endl;
        for (int j = 0; j < 4; j++) {
            if (a[i][j] == 0) {
                cout << "|      ";
            } else {
                cout << "| ";
                cout << a[i][j];
                cout << " ";
            }
        }
        cout << "|" << endl;
    }
    cout << "|------|------|------|------|" << endl;
    cout << endl;
}
int main(){  
   int array[4][4];
   ArrayMaking(array);
   print(array);
   return 0;
}

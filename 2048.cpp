#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void ArrayMaking(int array[][4]) {// declaring array(2d)//a,array willl represent the grid 
	// srand()
	//The rand() function uses the srand() function to establish the seed value for the random number generator 
	//The rand() function uses the srand() function to establish the seed value for the random number generator 
    srand(time(0));//sets the seed value for the random number generator based on the current time.
    int r1,r2,c1,c2,v1,v2,randomValue1,randomValue2;// initializing variables rows and col and value (r1)row1(c1)col1
    //to get two random positions
    r1 = rand() % 4;// random number will be generated from 0 to 3 which will be used as the index of the row for 1st pos
    c1 = rand() % 4;// random number will be generated from 0 to 3 which will be used as the index of the col for 1st pos
    r2 = rand() % 4;// random number will be generated from 0 to 3 which will be used as the index of the row for 2nd pos
    c2 = rand() % 4;// random number will be generated from 0 to 3 which will be used as the index of the col for 2nd pos

    randomValue1 = rand() % 3;//4
    randomValue2 = rand() % 3;//4

    if (randomValue1 == 0) {//check if box is empty
        v1 = 2;// if empty assign 2
    } else  {
        v1 = 4;//or 4
    }if (randomValue2 == 0) {
        v2 = 2;
    } else {
        v2 = 4;
    }
    array[r1][c1] = v1;// set values at generated position on the board 
    array[r2][c2] = v2;
    
    for (int i = 0; i < 4; i++) {// loop iterates over the rows
        for (int j = 0; j < 4; j++) {//loop iterates over the col
        if (array[i][j] != v1 && array[i][j] != v2) { // if the current element is not equal to val1 and val2
               
            }}
    }}
void print(int a[][4]) {
    for (int i = 0; i < 4; i++) {//itterate through each row 
        cout << "|------|------|------|------|" << endl;
        for (int j = 0; j < 4; j++) {// itterate through each col of the row at which u will be at that time 
            if (a[i][j] == 0) {// if current element is 0
                cout << "|      "; //print empty box 
            } else {
                cout << "| ";
                
				                  // or print that number
                cout << a[i][j];
                cout << " ";
            }
        }
        cout << "|" << endl;// printing closing for the row in which you r
    }
    cout << "|------|------|------|------|" << endl;//printing ending line
    cout << endl;
}
int main(){  
   int array[4][4];
   ArrayMaking(array);
   print(array);
   return 0;
}

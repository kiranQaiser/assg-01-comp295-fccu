#include <iostream>
#include <cstdlib>
#include <ctime>
#include<conio.h>
#include<climits>
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
          array[i][j] = 0;// sets the value of the element at that position to 0 //setting value instead of memmory
            }}
    }}
void print(int a[][4]) {
	
    for (int i = 0; i < 4; i++) { //itterate through each row 
        cout << "|------|------|------|------|" << endl;
        for (int j = 0; j < 4; j++) {// itterate through each col of the row at which u will be at that time 
            if (a[i][j] == 0) {// if current element is 0
                cout << "|      "; //print empty box 
            } else {
                cout << "|";
				                  // or print that number
                printf("%4d  ", a[i][j]);//// and print the value with a padding of 4 spaces
            }
        }
        cout << "|" << endl;// printing closing for the row in which you r
    }
    cout << "|------|------|------|------|" << endl << endl; //printing ending line
}

void moveupwords(int a[][4]) // function to move up the elements 
{
  int row, col, up, s; //s(store the curr element ), up (element above it )
  for (col = 0; col < 4; col++) {//itterate over col till 4 from 0 to 3
    for (row = 1; row < 4; row++) {//itterate over row from 1st row as current element is compared with element above it as there is no element at top row
      if (a[row][col] != 0) { // we will check that current box in the grid is empty or not if not
        s = a[row][col]; // we will save the curr num in the s(used to move num up)
        up = row - 1;//set up bethe num above the curr num
        while (up >= 0 && a[up][col] == 0) { // Move the num up until up>=0
          a[up][col] = s; //move ccurrent num up and 
          a[up+1][col] = 0;//set previous box to empty
          up=up-1;
        }
        if (up >= 0 && a[up][col] == s) { // check if both box have same num
         a[up][col] += s; // add both num 
		 a[row][col] = 0;	// set box to empty
        }} }}}
void movedownwords(int a[][4]) {
  int row, col, d, s;
  for (col = 0; col < 4; col++) {// itterate over col
    for (row = 2; row >= 0; row--) {//itterate over rows from 0 to 2 so that elent cannot overwrite
      if (a[row][col] != 0) { // we will check that current box in the grid is empty or not if not
        s = a[row][col]; // we will save the curr num in the s(used to move element down)
        d = row + 1;     //set d bethe num below the curr num
        while (d <= 3 && a[d][col] == 0) { // Move the num downwards 
          a[d][col] = s;//move stored current num down  and 
          a[d-1][col] = 0;// set box to empty
          d=d+1;//move next
        }if (d <= 3 && a[d][col] == s) { // check if both box have same num
          a[d][col] += s; // add them 
          a[row][col] = 0;	// set box to empty
        }}}}}
void moveleft(int a[][4]){
    int row,col, l, s;
    for (row = 0; row < 4; row++) {// itterate over row
        for (col = 1; col < 4; col++) {//itterate over col
            if (a[row][col] != 0) { // we will check that current box in the grid is empty or not if not
                s = a[row][col]; // we will save the curr num in the s(used to move element down)
                l = col - 1; //set l be left of the current column 
                while (l >= 0 && a[row][l] == 0) { // move the element to the left 
                    a[row][l] = s;//move stored current num down  and 
                    a[row][l+1] = 0;// set box to empty
                    l=l-1;
                }
                if (l >= 0 && a[row][l] == s) { // check if both box have same num
                    a[row][l] += s;  // add them 
                    a[row][col] = 0;// set box to empty
                 }}}}}
void moveright(int a[][4]){
  int row, col, r, s;
  for (row = 0;row< 4;row++) {//itterate over row
    for (col = 2; col>= 0; col--) {//itterate ove col
      if (a[row][col] != 0) { 
        s = a[row][col];
        r = col+ 1;
        while (r < 4 && a[row][r] == 0) { 
          a[row][r] = s;
          a[row][r-1] = 0;
          r=r+1;
        }
        if (r < 4 && a[row][r] == s) { 
          a[row][r] += s;
          a[row][col] = 0;
           }}}}}
void join(int a[][4])
{
  int left,right,num;//variables will store the new random numbers 
  srand(time(0));//sets the seed value for the random number generator based on the current time.
  while(1)//while 
  {
    left=rand()%4;// random number will be generated from 0 to 3 which will be used as the index of the row for the new line 
    right=rand()%4;
    if(a[left][right]==0)// will check that box is empty or not 
    {
      num = (rand() % 2 + 1) * 2;//num is multiplyied with 2 to generate 2 or 4 
      a[left][right] =num;
      
      break;
    
    }}}



bool isGameOver(int a[][4]) {
    bool emp_box = false; // flag for empty cell check
    bool adj_box = false; // flag for adjacent matching element check
    
    for (int i = 0; i < 4; i++) {//itterate over rows
        for (int j = 0; j < 4; j++) {//itterate over col
            if (a[i][j] == 0) { //check if array is empty
                emp_box = true; // Set empty cell to true
            } else if (a[i][j] == 2048) {
                return true; // If we have reached 2048, return true for game over
            }
        }
    }
    
    for (int i = 0; i < 3; i++) {//itterate upto 2nd last row
        for (int j = 0; j < 3; j++) { //itterate upto 2nd last col
            if (a[i][j] == a[i+1][j] || a[i][j] == a[i][j+1]) {
                adj_box= true; // Set adjacent matching element  to true
            }
        }
    }
    
        // Check last row and column for adjacent matching elements
    if (a[3][2] == a[3][3] || a[2][3] == a[3][3]) {
        adj_box= true; // Set adjacent matching element flag to true
    }
    
    // Return true if no empty cells and no adjacent matching elements
    if (!(emp_box|| adj_box)) {
    return true;
}
}



bool check(const int temp[][4], const int a[][4])
{
    for(int r=0;r<4;r++)
        for(int c=0;c<4;c++)//itterate over col
            if(temp[r][c]!=a[r][c])
                return false;
    return true;
}

void game() {
  int array[4][4];
  ArrayMaking(array);
  print(array);
  
  getch();  // function waits for a key to be pressed and then returns the ASCII code of the character that was pressed
  system("cls");
  int a1, a2, a3, a4, r, c;
  int a[4][4] = {0}, temp[4][4] = {0};  // initialize all elements to 0
  a1 = rand() % 4;
  a2 = rand() % 4;
  while (1) {
    a3 = rand() % 4;  // generate random num for a3
    a4 = rand() % 4;  // for a4
    if (a3 != a1 && a4 != a2) break;  // not equal
  }
  
  a[a1][a2] = 2;  // assign 2
  a[a3][a4] = 4;  // assign 4
  print(a);

  int character;
  while (1) {
    for (r = 0; r < 4; r++)  // iterate over rows
      for (c = 0; c < 4; c++)  // iterate over col
        temp[r][c] = a[r][c];  // copy num
    character = getch();  // assign the value to character
    system("cls");
    switch (character) {
      case 72:  // up arrow
        moveupwords(a);
        break;
      case 80:  // down arrow
        movedownwords(a);
        break;
      case 75:  // left arrow
        moveleft(a);
        break;
      case 77:  // right arrow
        moveright(a);
        break;
      default:
        continue;  // continue the loop if the input is not valid
    }

    if (!check(temp, a))
        join(a);
    print(a);

    if (isGameOver(a)) {
      cout << endl << endl << endl << "you lost the game " << endl << endl;
      cout << "  ..........press enter to continue.........to get other options  " << endl;

      getch();
      break;
    }
  }
}
void menu(){
  cout << "Welcome to 2048 game!" << endl;
  cout << "1. Start" << endl;
  cout << "2. Instructions" << endl;
  cout << "3. Quit" << endl;

  // Get user input
  int selection ;
  cout << "select one of the following from 1 to 3 : ";
  cin >> selection;
  while(selection < 1 || selection > 3) {
    cout << endl<<"wrong input" <<endl<< "Please select a valid option from 1 to 3: ";
    cin >> selection;
  
  while (!cin >> selection) {//to fix bugs 
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}
  }
  switch (selection) {
    case 1:
      
      cout << "     GAME START '''''''play'''''''' " << endl;
      break;
    case 2:
      cout << "Instructions for this game are :" << endl;
      cout << "                                 arrow keys will be use to merge " << endl<<"                                 merge with the same number ";
      cout<<endl<<                                      "you will score the addition of numbers for 1 merge ";
      exit(0);
    case 3:
      // Quit game
      cout << "Game exit" << endl;
      exit(0);
    default:
      menu();
      break;
  }
	
}
int main(){  

   menu();
   game();
   return 0;
}

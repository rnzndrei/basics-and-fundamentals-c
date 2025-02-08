//GITHUB EXERCISE TEST
/*
Directions:
1. Create a remote repository on your GitHub account. (name of repository 'basics-and-fundamentals-c')
2. Clone that repository into your local machine.
3. Create a new branch.
4. Add the .cpp file from your Exercise: C++ Basics and Fundamentals activity to that repository. 
5. Add and commit the changes to that new branch.
6. Push the changes from that new branch up to your remote repository in GitHub.
7. Merge that pull request.
8. Submit here the repository link of your remote repository in GitHub.
Note: Use git commands
*/

/*DEL ROSARIO RENZ ANDREI   -     IT2C     -     INTEPROG  -    Exercise: Basics and Fundamentals of C++
Description: A program that accepts elements for 2 arrays and merge the elements into another array in descending order. The array would only accept a total of 20 elements,
comprising of 10 from array 1 and 10 from array 2. The accepted elements are only numbers. Letters, words, and symbols would not be accepted*/

#include <iostream>
#include <limits>
using namespace std;

void line (){
    cout << "\n-----------------------------------------------------------------" << endl;           // To output lines
}
void inputSize (int &size, const string& text){
    cout << "\nHow many elements would you like to enter in " << text;
        while (true) {  
            cin >> size;
            
            // Check if the input failed
            if (cin.fail() || cin.peek() != '\n' || size < 1 || size > 10) {  
                cout << "\nInvalid input. Please enter a valid number (Minimum of 1 and Maximum of 10): ";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Remove input
            } else {
                break;  // Valid input, exit loop
            }
        }
}

void inputElements (int size, float array[], const string& text) {
    cout << "\nInput " << size << " numbers in the " << text << endl;
        for (int i = 0; i < size; i++){
        cout << "\tIndex " << i << ": ";
            while (true) {
            cin >> array [i];
                // Check for invalid input or multiple numbers
                    if (cin.fail() || cin.peek() != '\n') {
                        cout << "Invalid input. Please enter a single number in Index " << i << ": ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Remove Input
                    } else {
                        break;  // Valid input, exit loop
                    }
            }
        }
}

int main (){
    char ans;

    do {
    //Input the size and elements of Array 1
    int sizeArr1 = 0;
    line(); cout << "\t\t\tELEMENTS OF ARRAY 1"; line ();
        inputSize (sizeArr1, "Array 1 (1-10): ");
            float numArr1 [sizeArr1] = {};
                inputElements (sizeArr1, numArr1, "Array 1 elements: ");

    //Input the size and elements of Array 2
    int sizeArr2 = 0;
    line(); cout << "\t\t\tELEMENTS OF ARRAY 2"; line ();
        inputSize (sizeArr2, "Array 2 (1-10): ");
            float numArr2 [sizeArr2] = {};
                inputElements (sizeArr2, numArr2, "Array 2 elements: ");

    //Merge Array 1 and Array 2 to a single Array
    int mergedSize = sizeArr1 + sizeArr2;
    float mergedArr [mergedSize] = {};
        for (int i = 0; i < sizeArr1; i++) {
            mergedArr[i] = numArr1[i];
        }
        for (int i = 0; i < sizeArr2; i++) {
            mergedArr[sizeArr1 + i] = numArr2[i];
        }

    //Bubble Sort
    float temp;
        for (int start = 0; start < mergedSize - 1; start++) {
            for (int i = 0; i < mergedSize - 1 - start; i ++){
                if (mergedArr[i] < mergedArr[i + 1]) {
                    temp = mergedArr[i];
                    mergedArr[i] = mergedArr[i + 1];
                    mergedArr[i + 1] = temp;
                }
            }
        }

    //Print merged Array in a descending order
    line();
    cout << "Array Elements in Descending Order: " << endl;
    cout << "\t";
        for (int i = 0; i < mergedSize; i++) {
            cout << mergedArr[i] << " ";
        }
    line();

    // To repeat the process if the user inputs y, it would repeat if neither n or y is inputted.
    while (true) {
            cout << "\nDo you want to input another set of arrays? (Y/N): ";
            cin >> ans;
                if (cin.fail() || cin.peek() != '\n') {
                    cout << "Invalid input. Please enter Y or N." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else if (ans == 'Y' || ans == 'y' || ans == 'N' || ans == 'n') {
                    break;  // Valid input
                } else {
                    cout << "Invalid input. Please enter only Y or N." << endl;
                }
        }
    } while (ans == 'Y' || ans == 'y');

    return 0;
}
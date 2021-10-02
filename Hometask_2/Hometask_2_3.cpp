#include <iostream>
using namespace std;

int* createArray(int n) {
	return new int[n] { 0 };
}

void deleteArray(int* &arr) {
    delete[] arr;
    arr = nullptr;
}

int TopPosition(int* arr, int n) {

    int i = n - 1;
    while (i >= 0 && arr[i] == 0) {
    i = i - 1;
    }

    return i;

}

void PrintPegs(int* arr1, int* arr2, int* arr3, int n) {

    int i = 0;

    cout << "A: ";
    for (i = 0; i < n; ++i) {
        cout << arr1[i] << " ";
    }
    cout << endl << "B: ";
    for (i = 0; i < n; ++i) {
        cout << arr2[i] << " ";
    }
    cout << endl << "C: ";
    for (i = 0; i < n; ++i) {
        cout << arr3[i] << " ";
    }

}

void HanoiTowersOdd (int n) {

    int* A = createArray(n);
    int* B = createArray(n);
    int* C = createArray(n);

    //Starting position
    for (int i=0; i < n; i++) {
        A[i] = n - i;
        B[i] = 0;
        C[i] = 0;
    }
    cout << "Starting position: " << endl;
    PrintPegs(A,B,C,n);
    cout << endl;

    int k=1;
    while (A[0] != 0 || C[0] != 0) {
    // Make a legal move between A and B (in either direction)
    if (A[TopPosition(A,n)] < B[TopPosition(B,n)]) {
        cout << "Move disc " << A[TopPosition(A,n)]<< " from A to B." << endl;
        B[TopPosition(B,n) + 1] = A[TopPosition(A,n)];
        A[TopPosition(A,n)] = 0;
    }
    else {
        cout << "Move disc " << B[TopPosition(B,n)]<< " from B to A." << endl;
        A[TopPosition(A,n) + 1] = B[TopPosition(B,n)];
        B[TopPosition(B,n)] = 0;   
    }
    cout << "Position after " << k << ". move: " << endl;
    PrintPegs(A,B,C,n);
    cout << endl;
    k=k+1;
    

    if (A[0] != 0 || C[0] != 0) {
    //Make a legal move between A and C (in either direction)
    if (A[TopPosition(A,n)] < C[TopPosition(C,n)]) {
        cout << "Move disc " << A[TopPosition(A,n)]<< " from A to C." << endl;
        C[TopPosition(C,n) + 1] = A[TopPosition(A,n)];
        A[TopPosition(A,n)] = 0;
    }
    else {
        cout << "Move disc " << C[TopPosition(C,n)]<< " from C to A." << endl;
        A[TopPosition(A,n) + 1] = C[TopPosition(C,n)];
        C[TopPosition(C,n)] = 0;
    }
    cout << "Position after " << k << ". move: " << endl;
    PrintPegs(A,B,C,n);
    cout << endl;
    k=k+1;
    }

    if (A[0] != 0 || C[0] != 0) {
    //Make a legal move between B and C (in either direction)
    if (B[TopPosition(B,n)] < C[TopPosition(C,n)]) {
        cout << "Move disc " << B[TopPosition(B,n)]<< " from B to C." << endl;
        C[TopPosition(C,n) + 1] = B[TopPosition(B,n)];
        B[TopPosition(B,n)] = 0;
    }
    else {
        cout << "Move disc " << C[TopPosition(C,n)]<< " from C to B." << endl;
        B[TopPosition(B,n) + 1] = C[TopPosition(C,n)];
        C[TopPosition(C,n)] = 0;
    }
    cout << "Position after " << k << ". move: " << endl;
    PrintPegs(A,B,C,n);
    cout << endl;
    k=k+1;
    }
    }

    deleteArray(A);
    deleteArray(B);
    deleteArray(C);

}

void HanoiTowersEven (int n) {

    int* A = createArray(n);
    int* B = createArray(n);
    int* C = createArray(n);

    //Starting position
    for (int i=0; i < n; i++) {
        A[i] = n - i;
        B[i] = 0;
        C[i] = 0;
    }
    cout << "Starting position: " << endl;
    PrintPegs(A,B,C,n);
    cout << endl;

    int k=1;
    while (A[0] != 0 || C[0] != 0) {
    // Make a legal move between A and C (in either direction)
    if (A[TopPosition(A,n)] < C[TopPosition(C,n)]) {
        cout << "Move disc " << A[TopPosition(A,n)]<< " from A to C." << endl;
        C[TopPosition(C,n) + 1] = A[TopPosition(A,n)];
        A[TopPosition(A,n)] = 0;
    }
    else {
        cout << "Move disc " << C[TopPosition(C,n)]<< " from C to A." << endl;
        A[TopPosition(A,n) + 1] = C[TopPosition(C,n)];
        C[TopPosition(C,n)] = 0;   
    }
    cout << "Position after " << k << ". move: " << endl;
    PrintPegs(A,B,C,n);
    cout << endl;
    k=k+1;
    

    if (A[0] != 0 || C[0] != 0) {
    //Make a legal move between A and B (in either direction)
    if (A[TopPosition(A,n)] < B[TopPosition(B,n)]) {
        cout << "Move disc " << A[TopPosition(A,n)]<< " from A to B." << endl;
        B[TopPosition(B,n) + 1] = A[TopPosition(A,n)];
        A[TopPosition(A,n)] = 0;
    }
    else {
        cout << "Move disc " << B[TopPosition(B,n)]<< " from B to A." << endl;
        A[TopPosition(A,n) + 1] = B[TopPosition(B,n)];
        B[TopPosition(B,n)] = 0;
    }
    cout << "Position after " << k << ". move: " << endl;
    PrintPegs(A,B,C,n);
    cout << endl;
    k=k+1;
    }

    if (A[0] != 0 || C[0] != 0) {
    //Make a legal move between B and C (in either direction)
    if (B[TopPosition(B,n)] < C[TopPosition(C,n)]) {
        cout << "Move disc " << B[TopPosition(B,n)]<< " from B to C." << endl;
        C[TopPosition(C,n) + 1] = B[TopPosition(B,n)];
        B[TopPosition(B,n)] = 0;
    }
    else {
        cout << "Move disc " << C[TopPosition(C,n)]<< " from C to B." << endl;
        B[TopPosition(B,n) + 1] = C[TopPosition(C,n)];
        C[TopPosition(C,n)] = 0;
    }
    cout << "Position after " << k << ". move: " << endl;
    PrintPegs(A,B,C,n);
    cout << endl;
    k=k+1;
    }
    }

    deleteArray(A);
    deleteArray(B);
    deleteArray(C);
}

void HanoiTowers (int n) {

    if (n % 2 == 0) {
        HanoiTowersEven(n);
    }
    else {
        HanoiTowersOdd(n);
    }

}

int main(int argc, char* argv[]) {

HanoiTowers(3);

return EXIT_SUCCESS;

}
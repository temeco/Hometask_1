#include<iostream>
#include <algorithm>

using namespace std;

void randomizeArray(int* a, int n) {
    const int N = 180;
    int basic[N]{ 0 };

    for (int i = 0; i < 90; ++i) {
        basic[i] = i-99;
    }
    for (int i = 90; i < 180; ++i) {
        basic[i] = i - 80;
    }

    for (int i = 0; i < n; ++i) {
        int k = rand() % N;
        while (basic[k] == 200) {
            k = (k + 1) % N;
        }
        a[i] = basic[k];
        basic[k] = 200;
    }
}

void printArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int sumOfElements(int* a, int n) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = res + a[i];
    }
    return res;
}

int productOfNegatives(int* a, int n) {
    int res = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            res = res*a[i];
        }
    }
    return res;
}

int countOfEven(int* a, int n) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            res = res + 1;
        }
    }
    return res;
}

int secondMin(int* a, int n) {
    int res = a[0];
    int min = a[0];
    for(int i = 0; i < n; ++i) {
        if (a[i] < min) {
            res = min;
            min = a[i];
        }
        else if (a[i] < res) {
            res = a[i];
        }
    }
    return res;
}

int indSecMax(int* a, int n) {
    int max = a[0];
    int max2 = a[0];
    int indMax = 0;
    int indMax2 = 0;
    for(int i = 0; i < n; ++i) {
        if (a[i] > max) {
            max2 = max;
            indMax2 = indMax;
            max = a[i];
            indMax = i;
        }
        else if (a[i] > max2) {
            max2 = a[i];
            indMax2 = i;
        }
    }
    return indMax2;
}

void swapElem(int* a, int n) {
    int temp = 0;
    int i = 0;
    while (i + 1 < n) {
        temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
        i = i + 2;
    }
}

void reverseArray(int* a, int n)
{
	for (int i = 0; i < n / 2; ++i)
	{
		int temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
	}
}

void deleteMiddle(int* &a, int &n) {
    int max = a[0];
    int min = a[0];
    int maxind = 0;
    int minind = 0;
    int start = 0;
    int end = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] < min) {
            min = a[i];
            minind = i;
        }
        if (a[i] > max) {
            max = a[i];
            maxind = i;
        }
    }

    if (maxind < minind) {
        start = maxind;
        end = minind;
    }
    else {
        start = minind;
        end = maxind;
    }

    int* newA = new int[n - (end - start) + 1]{ 0 };

    for (int i = 0; i < start + 1; ++i) {
        newA[i] = a[i];
    }
    for (int i = start + 1; i < n - (end - start) + 1; ++i) {
        newA[i] = a[i + end - start - 1];
    }

    delete[] a;
	a = newA;
	n = n - (end - start) + 1;

}

void insertZero(int* &a, int &n) {

    int* newA = new int[n + 1]{ 0 };

    for (int i = 0; i < n/2; ++i) {
        newA[i] = a[i];
    }
    for (int i = n/2; i < n; ++i) {
        newA[i + 1] = a[i];
    }

    delete[] a;
    a = newA;
    n = n + 1;
}
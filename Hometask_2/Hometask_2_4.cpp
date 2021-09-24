#include<iostream>
#include<string>

using namespace std;


void output(string str)
{
    int k = str.length();
    int i = 0;
    
    if (k%2==0) {
        for (i = 0; i < k/2 ; i++) {
            cout << "(" << str[i];
        }
        for (i = k/2; i < k; i++) {
            cout << str[i] << ")";
        }
    }
    else {
        for (i = 0; i < k/2; i++) {
            cout << "(" << str[i];
        }
        cout << "(";
        for (i = k/2; i < k; i++) {
            cout << str[i] << ")";
        }
    }
	
}

int main() {

    string str = " ";
    cout << "Please enter a string: ";
    cin >> str;
	output(str);
	return EXIT_SUCCESS;
}
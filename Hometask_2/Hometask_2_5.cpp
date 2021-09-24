#include<iostream>
#include<string>

using namespace std;

void shortCuts(string str)
{
    int i = 0;
    int l = str.length();

	for (i = 0; i < l/2; i++) {
        if (str[i] != str[l - 1 - i]) {
            cout << str[i];
       }
    }
    if (l % 2 != 0) {
        cout << str[l/2];
    }
    for (i = l/2; i < l; i++) {
        if (str[i] != str[l - 1 - i]) {
            cout << str[i];
        }
    }
	
}

int main() {

    string str = "";

    cout << "Please enter a string: ";
    cin >> str;
    cout << "The string without all symmetric positions is: ";
    
    shortCuts(str);

    return EXIT_SUCCESS;
}
#include<iostream>
#include<string>

using namespace std;

void shortCuts(string& str, int index = 0)
{ 
	if (index*2 < str.length()) {
        if (str[index] != str[str.length() - 1 - index]) {
            cout << str[index];
        }
        shortCuts(str, index + 1);
        if (index*2 + 1 == str.length()) {
            cout << str[index];
        }
        if (str[index] != str[str.length() - 1 - index]) {
            cout << str[str.length() - 1 - index];
        }
    }

    return;
	
}

int int main(int argc, char* argv[]) {

    string str = "";
    cout << "Please enter a string: ";
    cin >> str;
    cout << "The string without all symmetric positions is: ";
    
    shortCuts(str);

    return EXIT_SUCCESS;
}
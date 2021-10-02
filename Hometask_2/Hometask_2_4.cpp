#include<iostream>
#include<string>

using namespace std;


void output(string& str, int index = 0) {

    cout << str[index];

    if ((index + 1)*2 < str.length()) {
        cout << "(";
        output(str, index + 1);
        cout << ")";
    }

    if (index*2 + 1 != str.length()) {
        cout << str[str.length() - 1 - index];
    }

}

int main(int argc, char* argv[]) {

    string str = " ";
    cout << "Please enter a string: ";
    cin >> str;
	output(str);
	return EXIT_SUCCESS;
}
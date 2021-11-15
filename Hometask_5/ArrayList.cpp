#include<iostream>
#include"ArrayList.h"

using namespace std;

//destructor
ArrayList::~ArrayList() {
	delete[] data;
}

//prints the array
void ArrayList::print() {
	cout << "[" << count << "/" << length << "] { ";
	for (int i = 0; i < count; ++i) {
		cout << data[i] << " ";
	}
	cout << "}" << endl;
}

//expands the ArrayList
void ArrayList::expand(int rate) {
	if (rate == 0) {
		rate = length;
	}
	int* newA = new int[length + rate]{ 0 };
	for (int i = 0; i < length; ++i)
	{
		newA[i] = data[i];
	}
	delete[] data;
	data = newA;
	length += rate;
}

//adds a new element at the end of the list
void ArrayList::push_back(int element) {
	if (count == length) {
		expand();
	}
	data[count] = element;
	++count;
}

//adds a new element at the beginning of the list
void ArrayList::push_forward(int element) {
	if (count == length) {
		expand();
	}
	for (int i = count; i > 0; --i) {
		data[i] = data[i - 1];
	}
	data[0] = element;
	++count;
}

//inserts a new element at the given index, all elements on the right are shifted 
void ArrayList::insert(int element, int index) {
	if (index < count) {
		if (count == length) {
			expand();
		}
		for (int i = count; i > index; --i) {
			data[i] = data[i - 1];
		}
		data[index] = element;
		++count;
	}
	else {
		if (index >= length) {
			expand(index - length + 1);
		}
	data[index] = element;
	count = index + 1;
	}
}

//extracts the element with given index from the list and returns its value
int ArrayList::extract_ind(int index) {
	int res = data[index];
	for (int i = index; i < count; ++i) {
		data[i] = data[i + 1];
	}
	--count;
	return res;
}

//extracts the first appearing elemet with given value from the list and returns its index
//if the value is not in the list, -1 is returned
int ArrayList::extract_val(int value) {
	for (int i = 0; i < count; ++i) {
		if (data[i] == value) {
			for (int j = i; j < count; ++j) {
				data[j] = data[j + 1];
			}
			--count;
			return i;
		}
	}
	return -1;
}

//adds an ArrayList to an ArrayList
ArrayList ArrayList::append(ArrayList list) {
	expand(list.length);
	for (int i = count; i < count + list.count; ++i) {
		data[i] = list.data[i - count];
	}
	count = count + list.count;
	return *this;
}

bool ArrayList::operator==(ArrayList& list) {
	bool res = true;
	for (int i = 0; i < length; ++i) {
		if (list.data[i] != data[i]) {
			res = false;
			return res;
		}
	}
	return res;
}

ArrayList& ArrayList::operator=(ArrayList& list) {
	for (int i = 0; i < length; ++i) {
		data[i] = list.data[i];
	}
	return *this;
}

ArrayList& ArrayList::operator+= (int value){
		push_back(value);
		return (*this);
	}

ArrayList& ArrayList::operator+= (ArrayList& list){
		append(list);
		return (*this);
	}

std::ostream& operator<<(std::ostream& stream, const ArrayList& list){
	stream << "[" << list.count << "/" << list.length << "] {";
	for (int i = 0; i < list.count; ++i) {
		stream << " " << list.data[i];
	}
	stream << " }";
	return stream;
}


int main(int argc, char* argv[])
{
	ArrayList list(2);
	list.push_back(5);
	list += 3;
	list.print();

	list.push_forward(34);
	list.print();

	cout << list.extract_ind(1) << endl;
	list.print();

	list.insert(67, 3);
	list.print();

	ArrayList newlist = list;
	newlist += list;
	newlist.print();

	newlist.extract_val(67);

	cout << newlist;

	return EXIT_SUCCESS;
}
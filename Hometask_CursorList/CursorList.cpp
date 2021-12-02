#include<iostream>
#include<string>

using namespace std;

struct CursorList {
	int count;
	int length;
	int* data;
    int* cursor;

	CursorList(int length = 10) : count(0), length(length), data(new int[length] { 0 }), cursor(new int[length] { 0 }) {};
	
	CursorList(CursorList& list) {
		this->length = list.length;
		this->count = list.count;
		this->data = new int[list.length]{ 0 };
        this->cursor = new int[list.length]{ 0 };
		for (int i = 0; i < list.count; ++i)
		{
			this->data[i] = list.data[i];
            this->cursor[i] = list.cursor[i];
		}
	}
	
	~CursorList() {
		delete[] this->data;
        delete[] this->cursor;
	}

	bool indexValid(int index)
	{
		return (index >= 0 && index < count);
	}

	void expand(int expandRate = 0)
	{
		if (expandRate == 0) {
			expandRate = length;
		}
		int* newData = new int[length + expandRate]{ 0 };
        int* newCursor = new int[length + expandRate]{ 0 };
		for (int i = 0; i < count; ++i)
		{
			newData[i] = data[i];
            newCursor[i] = cursor[i];
		}
		delete[] data;
        delete[] cursor;
		data = newData;
        cursor = newCursor;
		length += expandRate;
	}

	void push_back(int element) 
    {
    if (count == length) {
        expand();
    }
    int i = 0;
    while (cursor[i] != 0) {
        // look for the first free space in array
        ++i;
    }
    data[i] = element;
    int last = 0;
    while (cursor[last] != -1) {
        ++last;
    }
    cursor[last] = count;
    cursor[i] = -1;
    ++count;
    }
		
    void push_forward(int value) {
		if (count == length) {
			expand();
		}
		for (int i = count; i > 0; --i)
		{
			data[i] = data[i - 1];
            if (cursor[i - 1] == -1) {
                cursor[i] = -1;
            }
            else {
                cursor[i] = cursor[i - 1] + 1;
            }
		}
		++count;
		data[0] = value;
        cursor[0] = 1;
	}

	void insert(int element, int index) {
		//the integer "element" is inserted after the index-th element of the list
		if (index == 0) {
			push_forward(element);
		}
		else if (index > count) {
			push_back(element);
		}
		else {
			if (count == length) {
				expand();
			}
			int i = 0;
			for (int k = 0; k < index - 1; ++k) {
				i = cursor[i];
			}
			int prevCursor = cursor[i];
			int insertingIndex = 0;
			while (cursor[insertingIndex] != 0) {
				//find next free space
				++insertingIndex;
			}
			cursor[i] = insertingIndex;
			data[insertingIndex] = element;
			cursor[insertingIndex] = prevCursor;
			++count;
		}
	}

	int extract_first() {
		int extracted = data[0];
		for (int i = 0; i < count; ++i) {
				data[i] = data[i + 1];
				if (cursor[i + 1] > 0) {
					cursor[i] = cursor[i + 1] - 1;
				}
				else if (cursor[i + 1] == -1) {
					cursor[i] = -1;
				}
			}
		--count;
		return extracted;
	}

	int extract_ind(int index) {
		//extract the index-th element from the list
		if (index > count) {
			return 0;
		}
		if (index <= 1) {
			extract_first();
		}
		else {
			int i = 0;
			for (int k = 1; k < index - 1; ++k) {
				i = cursor[i];
			}
			int extractingIndex = cursor[i];
			cursor[i] = cursor[cursor[i]];
			int extractedValue = data[extractingIndex];
			data[extractingIndex] = 0;
			cursor[extractingIndex] = 0;
			--count;
			return extractedValue;
		}
		return 0;
	}

	int extract_val(int element) {
		//extracts the first appearing element in the list with given value
		if (data[0] == element) {
			extract_first();
		}
		int extractingInd = 0;
		while (data[cursor[extractingInd]] != element and extractingInd != -1) {
			extractingInd = cursor[extractingInd];
		}
		if (data[cursor[extractingInd]] != element) {
			//element not contained in list
			return 0;
		}
		else {
			int extract = cursor[extractingInd];
			cursor[extractingInd] = cursor[cursor[extractingInd]];
			cursor[extract] = 0;
			data[extract] = 0;
			--count;
			return element;
		}
		return 0;
	}

    void print()  {
    cout << "[" << count << "/" << length << "] { ";
    int i = 0;
	for (int k = 0; k < count; ++k) {
		cout << data[i] << " ";
        i = cursor[i];
	}
    cout << "}" << endl;
	}

	void print_all() {
		cout << "[" << count << "/" << length << "]" << endl;
		cout << "Data: { ";
    	for (int i = 0; i < length; ++i) {
			cout << data[i] << " ";
		}
		cout << "} " << endl;
		cout << "Cursor: { ";
		for (int i = 0; i < length; ++i) {
			cout << cursor[i] << " ";
		}
		cout << "}" << endl;
	}

    CursorList& operator+= (int value)
	{
		push_back(value);
		return (*this);
	}

    CursorList& operator+= (CursorList& list) {
		int end = list.count;
		if (length < count + list.count) {
			expand(count + end - length + 1);
		}

		for (int i = 0; i < end; ++i)
		{
           push_back(list.data[i]);
		}

		return (*this);
	}

	CursorList& operator-=(int element) {
		extract_val(element);
		return (*this);
	}

	CursorList& operator=(CursorList& list) {
		for (int i = 0; i < length; ++i) {
			data[i] = list.data[i];
			cursor[i] = list.cursor[i];
		}
		return (*this);
	}

	friend std::ostream& operator<<(std::ostream& stream, const CursorList& list){
	stream << "[" << list.count << "/" << list.length << "] {";
	int i = 0;
	for (int k = 0; k < list.count; ++k) {
		stream << " " << list.data[i];
		i = list.cursor[i];
	}
	stream << " }"<< endl;
	return stream;
}
};

int main()
{
	CursorList list(2);
	list.push_back(3);
    list.push_back(6);
    list.push_back(8);
    list.push_back(12);
    list += 11;
    list.push_forward(2);
    list.print();
    CursorList list1 = list;
	list1.insert(99,3);
    cout << list1 << endl;
	list1.print_all();
	list1 -= 99;
	cout << list1;
	list1.print_all();

	return EXIT_SUCCESS;
}
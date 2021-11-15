#include<iostream>

using namespace std;

struct ArrayList {

    //fields
	int* data;
	int length;
	int count;

    //constructor
    ArrayList();
    //parametrized constructor
	ArrayList(int length = 10) : data(new int[length] { 0 }), length(length), count(0) {};	
    //copying constructor
	ArrayList(ArrayList& list) : data(new int[list.length]), length(list.length), count(list.count) {
	for (int i = 0; i < length; ++i) {
		data[i] = list.data[i];
	}
    };	

    //destructor
	~ArrayList();

    //operators
    bool operator==(ArrayList& list);
	ArrayList& operator=(ArrayList& list);
	ArrayList& operator+= (int value);
	ArrayList& operator+= (ArrayList& list);
    friend std::ostream& operator<<(std::ostream& stream, const ArrayList& list);

    //methods

	void print();

	void expand(int rate = 0);

    //adds a new element at the end of the list
    void push_back(int element);

	//adds a new element at the beginning of the list
	void push_forward(int element);

	//inserts a new element at the given index, all elements on the right are shifted 
	void insert(int element, int index);

	//extracts the element with given index from the list and returns its value
	int extract_ind(int index);

	//extracts the elemet with given value from the list and returns its index
	//if the value is not in the list, -1 is returned
	int extract_val(int value);

	//adds an ArrayList to an ArrayList
	ArrayList append(ArrayList list);
};
	


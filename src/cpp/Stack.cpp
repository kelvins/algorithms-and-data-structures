#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

void Test_ABS();
void Test_ABS_Cases(float scale_factor, int N);

/*================ CLASS DEFINITION ================*/
template <typename T>
class ABS {
	T* _data; // What the class store-- the "real data
	unsigned int _size; //How many elements ARE we storing?
	unsigned int _capacity; // How many elementws CAN we store?
	float _scale_factor = 2.0f; //Scale factor to reduce or expand the capacity 
	unsigned int _total_resizes; //How many resizes there were?
	void CopyFromObject(const T& rhs);

public:
	//Construction // Destruction
	ABS();
	ABS(int capacity);
	ABS(int capacity, float scale_factor);

	~ABS();

	//Copy Constructor
	ABS(const ABS& d);

	//Copy assignment operator
	ABS& operator=(const ABS& d);

	/*========= Accessors ==========*/
	T peek() const;
	unsigned int getSize() const; //Returns the size of the ABS
	unsigned int get_capacity() const; //Returns the max capacity of the ABS
	unsigned int get_scale_factor() const; //Returns the scale factor
	unsigned int getTotalResizes() const; //Returns the total resizes
	T* getData() const;

	/*========= Mutators ==========*/
	void push(T data); // Add a new item to the top of the stack and resize if necessary.
	T pop();
	/*========= Behaviors ==========*/
};


/*================ CLASS MEMBER DEFINITIONS ================*/

template <typename T>
void ABS<T>::CopyFromObject(const T& d)
{
	_size = 0;
	_total_resizes = 0;
	_capacity = d._capacity;
	_data = new T[_capacity];

	for (unsigned int i = 0; i < d._size; i++)
		push(d[i]);
}
template <typename T>
ABS<T>::ABS() {

	_size = 0;
	_capacity = 1;
	_total_resizes = 0;
	_data = new T[_capacity];
}
template <typename T>
ABS<T>::ABS(int capacity) {

	_size = 0;
	_capacity = capacity;
	_total_resizes = 0;
	_data = new T[_capacity];

}
template <typename T>
ABS<T>::ABS(int capacity, float scale_factor)
{
	_size = 0;
	_capacity = capacity;
	_total_resizes = 0;
	_scale_factor = scale_factor;
	_data = new T[_capacity];
}
template <typename T>
ABS<T>::~ABS() {
	//cout << "Destroying ABS..." << endl;
	delete[] _data;
}
template <typename T>
ABS<T>::ABS(const ABS& d)
{
	CopyFromObject(d);

}
template <typename T>
ABS<T>& ABS<T>::operator=(const ABS& d)
{
	delete[] _data; //Get rid of old data and reset to a default state

	CopyFromObject(d); //Copy data from other object

	return *this;
}
template <typename T>
T ABS<T>::peek() const {
	if (_size == 0) {

		throw std::runtime_error("An error has occurred.");
	}
	return _data[_size - 1];
}
template <typename T>
unsigned int ABS<T>::getSize() const {
	return _size;
}
template <typename T>
unsigned int ABS<T>::get_capacity() const {
	return _capacity;
}
template <typename T>
unsigned int ABS<T>::get_scale_factor() const {
	return _scale_factor;
}
template <typename T>
unsigned int ABS<T>::getTotalResizes() const {
	return _total_resizes;
}
template <typename T>
T* ABS<T>::getData() const {
	return *this;
}
template <typename T>
void ABS<T>::push(T data) {
	//Should we resize the array?
	if (_size == _capacity) // We full
	{
		_capacity *= _scale_factor; //Resize our array (grow by _scale_factor)
		//Allocates new array of Ts
		T* newArray = new T[_capacity];
		//Copy the data 
		for (unsigned int i = 0; i < _size; i++)
			newArray[i] = _data[i];
		delete[] _data;
		_data = newArray;
		_total_resizes++;
	}
	_data[_size] = data; //Makes last member equals to the item to be added

	++_size; // Increases the size

}

template <typename T>
T ABS<T>::pop()
{
	if (_size == 0) {

		throw std::runtime_error("An error has occurred.");
	}

	T removed_object = _data[_size - 1];

	if ((float)_size / _capacity < (1 / _scale_factor))
	{
		_capacity = _capacity / _scale_factor;
		T* newObj = new T[_capacity];
		for (unsigned int i = 0; i < _size - 1; i++)
			newObj[i] = _data[i];
		delete[] _data;
		_data = newObj;
		_total_resizes++;
		_size--;


	}
	else {
		_size--;
	}

	return removed_object;

}

int main()
{
	int number_of_items[] = { 10000000, 30000000, 50000000, 75000000, 100000000 };
	float scale_factors[] = { 1.5, 2.0, 3.0, 10.0, 100.0 };
	unsigned int i;
	unsigned int j;

	// ABS Tests
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++)
		{
			Test_ABS_Cases(scale_factors[i], number_of_items[j]);
		}
	}

	return 0;
}

void Test_ABS_Cases(float scale_factor, int N)
{	
	//cout << "********** Begin of Test **********" << endl;
	cout << endl;
	cout << "ABS," << scale_factor << "," << N << ",";

	ABS<int> intABS(2, scale_factor);
	{
		for (int i = 0; i < N; i++)
			intABS.push(i);
	}	
	unsigned int resizes_during_push = intABS.getTotalResizes();

	cout << resizes_during_push << ",";
	{
		for (int i = 0; i < N; i++)
			intABS.pop();
	}
	cout << intABS.getTotalResizes() - resizes_during_push << ",";
	//cout << "********** End of Test **********" << endl;
}
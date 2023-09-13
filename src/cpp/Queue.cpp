#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;

void Test_ABQ();
void Test_ABQ_Cases(float scale_factor, int N);

template <typename T>
class ABQ {
	T* _data;  // What the class store-- the "real data
	unsigned int _size; //How many elements ARE we storing?
	unsigned int _capacity; // How many elementws CAN we store?
	float _scale_factor = 2.0f; //Scale factor to reduce or expand the capacity
	unsigned int _total_resizes; //How many resizes there were?
	unsigned int _first_in;
	void CopyFromObject(const T& rhs);

public:
	//Construction // Destruction
	ABQ();
	ABQ(int capacity);
	ABQ(int capacity, float scale_factor);

	~ABQ();

	//Copy Constructor
	ABQ(const ABQ& d);

	//Copy assignment operator
	ABQ& operator=(const ABQ& d);

	/*========= Accessors ==========*/
	T peek() const;
	unsigned int getSize() const; //Returns the size of the ABS
	unsigned int getMaxCapacity() const; //Returns the max capacity of the ABS
	unsigned int getScaleFactor() const; //Returns the scale factor
	unsigned int getTotalResizes() const; //Returns the total resizes
	T* getData() const;

	/*========= Mutators ==========*/
	void enqueue(T data); // Add a new item to the top of the stack and resize if necessary.
	T dequeue();
	/*========= Behaviors ==========*/
};

/*================ CLASS MEMBER DEFINITIONS ================*/

template <typename T>
void ABQ<T>::CopyFromObject(const T& d)
{
	_size = 0;
	_total_resizes = 0;
	_first_in = d._first_in;
	_capacity = d._capacity;
	_data = new T[_capacity];

	for (unsigned int i = 0; i < d._size; i++)
		enqueue(d[i]);
}
template <typename T>
ABQ<T>::ABQ() {

	_size = 0;
	_capacity = 1;
	_first_in = 0;
	_total_resizes = 0;
	_data = new T[_capacity];
}
template <typename T>
ABQ<T>::ABQ(int capacity) {

	_size = 0;
	_capacity = capacity;
	_first_in = 0;
	_total_resizes = 0;
	_data = new T[_capacity];

}
template <typename T>
ABQ<T>::ABQ(int capacity, float scale_factor)
{
	_size = 0;
	_capacity = capacity;
	_total_resizes = 0;
	_first_in = 0;
	_scale_factor = scale_factor;
	_data = new T[_capacity];
}
template <typename T>
ABQ<T>::~ABQ() {
	//cout << "Destroying ABS..." << endl;
	delete[] _data;
}
template <typename T>
ABQ<T>::ABQ(const ABQ& d)
{
	CopyFromObject(d);

}
template <typename T>
ABQ<T>& ABQ<T>::operator=(const ABQ& d)
{
	delete[] _data; //Get rid of old data and reset to a default state

	CopyFromObject(d); //Copy data from other object

	return *this;
}
template <typename T>
T ABQ<T>::peek() const {
	if (_size == 0) {

		throw std::runtime_error("An error has occurred.");
	}
	return _data[0];
}
template <typename T>
unsigned int ABQ<T>::getSize() const {
	return _size;
}
template <typename T>
unsigned int ABQ<T>::getMaxCapacity() const {
	return _capacity;
}
template <typename T>
unsigned int ABQ<T>::getScaleFactor() const {
	return _scale_factor;
}
template <typename T>
unsigned int ABQ<T>::getTotalResizes() const {
	return _total_resizes;
}
template <typename T>
T* ABQ<T>::getData() const {
	return *this;
}
template <typename T>
void ABQ<T>::enqueue(T data) {
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

	_size++; // Increases the size
}
template <typename T>
T ABQ<T>::dequeue()
{

	if (_size == 0) {
		throw std::runtime_error("An error has occured");
	}

	T object_to_be_removed = _data[_first_in];

	float percent_full = ((float)(_size) / _capacity);

	// check if queue is strictly less than 1/scale_factor
	if (percent_full < (1 / _scale_factor))
	{
		_capacity = _capacity / _scale_factor;

		T* newObj = new T[_capacity];

		for (unsigned int i = 1; i < _size; i++) {
			newObj[i - 1] = _data[i];
		}
		delete[] _data;
		_data = newObj;
		_total_resizes++;
		_first_in = 0;
	}
	else
	{
		_first_in++;
	}
	_size--;

	return object_to_be_removed;
}

int main()
{
	int number_of_items[] = { 10000000, 30000000, 50000000, 75000000, 100000000 };
	float scale_factors[] = { 1.5, 2.0, 3.0, 10.0, 100.0 };
	unsigned int i;
	unsigned int j;

	// ABQ Tests
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++)
		{
			Test_ABQ_Cases(scale_factors[i], number_of_items[j]);
		}
	}

	return 0;
}



void Test_ABQ_Cases(float scale_factor, int N)
{
	//cout << "********** Begin of Test **********" << endl;
	cout << endl;

	cout << "ABQ," << scale_factor << "," << N << ",";
	ABQ<int> intABQ(2, scale_factor);
	{
		for (int i = 0; i < N; i++)
			intABQ.enqueue(i);
	}
	unsigned int resizes_during_enqueue = intABQ.getTotalResizes();
	cout << resizes_during_enqueue << ",";

	{
		for (int i = 0; i < N; i++)
			intABQ.dequeue();
	}
	cout << intABQ.getTotalResizes() - resizes_during_enqueue << ",";
	//cout << "********** End of Test **********" << endl;
}

/**
 *
 * Circular buffer template class 
 * Author: Jayanth G
 *
**/

#include <iostream>
#define MAX 100

template <typename K>
class buffer
{
	unsigned int capacity;
	unsigned int size;
	int head;
	int tail;
	K* buf;
public:
	buffer(int s){
		head = tail = 0;
		size = 0;
		
		capacity = s;
		buf = new K[s];
	};
	~buffer(){
		delete[] buf;
	};
	
	bool insert(K x);
	K get(void);
	unsigned int get_size(void){
		return size;
	};	
};

template<typename K>
bool buffer<K>::insert(K x)
{
	if(size == capacity){
		std::cout << "Buffer Full!" << std::endl;
		return false;
	}
		
	tail = (tail + 1) % capacity;
	buf[tail] = x;
	size++;
	std::cout << "Inserted " << x << std::endl;
	return true;
}

template<typename K>
K buffer<K>::get(void)
{
	if(size > 0){
		size--;
		head = (head + 1) % capacity;
		return buf[head];	
	}
	else
		return 0;
}

int main()
{
	buffer<int> B(5);
	std::cout << B.get_size() << std::endl;
	B.insert(2);
	B.insert(3);
	B.insert(4);
	B.insert(5);
	B.insert(6);
	std::cout << B.get_size() << std::endl;
	B.insert(7);
}

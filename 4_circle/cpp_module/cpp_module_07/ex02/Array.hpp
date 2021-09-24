#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
template<class T>
class	Array
{
public :
	Array(){
		try {
			_Arr = new T[0];
			_size = 0;
		}
		catch (const std::bad_alloc &e) {
			std::cout << "bad_alloc : " << e.what() << std::endl;
		}
	}
	Array(unsigned int n){
		try {
			_Arr = new T[n];
			for (unsigned int i = 0; i < n; i ++)
				_Arr[i] = T();
			_size = n;
		}
		catch (const std::bad_alloc &e) {
			std::cout << "bad_alloc : " << e.what() << std::endl;
		}
	}
	Array(const Array &other){
		(*this) = other;
	}
	Array	&operator=(const Array &other){
		if (this != &other){
			this->~Array();
			this->_size = other._size;
			if (other._size == 0){
				try {
					this->_Arr = new T();
				}
				catch (const std::bad_alloc &e) {
				std::cout << "bad_alloc : " << e.what() << std::endl;
				}
			}
			else if (other._size > 0){
				try {
					this->_Arr = new T[other._size];
					for (unsigned int i = 0; i < other._size; i ++)
						_Arr[i] = other._Arr[i];
				}
				catch (const std::bad_alloc &e) {
					std::cout << "bad_alloc : " << e.what() << std::endl;
				}
			}
		}
		return (*this);
	}
	~Array(){
		delete[] (this->_Arr);
	}

	T &operator[](unsigned int i){
		if (i < 0 || i >= this->_size)
			throw std::out_of_range("out of range");
		return _Arr[i];
	}


	T	*getArr() const{
		return (this->_Arr);
	}
	unsigned int	size() const {
		return (this->_size);
	}

private :
	T *_Arr;
	unsigned int _size;
};

#endif
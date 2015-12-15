#pragma once
#include "list.h"
template <class T>
class hash
{
private:
	size_t table_size;
	size_t current = 0;
	list<T>** table;
	bool separate_chaining = false;
public:
	hash(int table_size_ = 0,int list_size = 0,bool seperate = false) {
		separate_chaining = seperate;
		if (separate_chaining) {
			list_size = 999;
		}
		else {
			table_size = table_size_ * list_size;
			list_size = 1;
		}
		table_size = table_size_;
		table = new list<T>*[table_size];
		for (unsigned int i = 0; i < table_size; i++) {
			table[i] = new list<T>(list_size);
		}
	}
	~hash(){}
	bool remove(std::string);
	bool remove(int);
	bool insert(std::string);
	bool insert(int);
	bool find(std::string);
	bool find(int);
	//bool find(std::string);
	int key(T key,int i) {
		return ((int)key + i) % table_size;
	}
	int sfold(const char* key, int i_ = 0) {
		unsigned int *lkey = (unsigned int *)key;
		int intlength = strlen(key) / 4;
		unsigned int sum = 0;
		for (int i = 0; i<intlength; i++)
			sum += lkey[i];
		int extra = strlen(key) - intlength * 4;
			char temp[4];
			lkey = (unsigned int *)temp;
			lkey[0] = 0;
			for (int i = 0; i<extra; i++)
				temp[i] = key[intlength * 4 + i];
			sum += lkey[0];
			return (sum + i_) % table_size;
	}
};


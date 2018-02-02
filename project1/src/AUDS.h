#ifndef _AUDS_H
#define _AUDS_H

#include <iostream>
#include <string>

template <typename T>

class AUDS{

public:
	AUDS(){
		current_size = 100;
		current_value = 0;
		data = new T[current_size];
	}
     
	AUDS(const AUDS &other){
		current_size = other.current_size;
		current_value = other.current_value;
          
		data = new T[current_size];
		for(int i = 0; i < current_size; i++){
			data[i] = other.data[i];
		}
	}

	AUDS& operator=(AUDS other){
		std::swap(current_size, other.current_size);
		std::swap(current_value, other.current_value);
		std::swap(data, other.data);

		return *this;
	}

     
	~AUDS(){
		delete[] data;
	}

	int size(){
		return current_value;
	}
	void push(T x){
		if(current_value == current_size){
			current_size *= 1.5;
			T* temp = new T[current_size];
			for(int i = 0; i < current_size; i++){
                        	temp[i] = data[i];
                	}
			delete[] data;
			data = temp;
		}
		data[current_value] = x;
		current_value++;
	}
     
	T pop(){
		T rtn;
		int randomNum = rand() % (current_value+1);    
		rtn = data[randomNum];
		data[randomNum] = data[current_value];
		current_value--;
	
        	return rtn;
	}
	
	void print_data(){
		for(int i = 0; i < current_size; i++){
			std::cout << data[i] << std::endl;
		}
	}	

private:
	int current_size;
	int current_value;
     
	T* data;
};


#endif 

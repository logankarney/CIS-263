#ifndef _AUDS_H
#define _AUDS_H

#include <iostream>
#include <string>
#include <ctime>

template <typename T>

/*
  Simulation of an ArrayList style object.
  Features include dynamic memory allocation and generic programming

  @author Logan Karney
  @version Winter 2018
  */
class AUDS{

public:
	/* 
 	  Default constructor  
	*/
	AUDS(){
		current_size = 100;
		current_value = 0;
		data = new T[current_size];
	}
     	
	/* 
 	  Copy constructor 
	  @param other AUDS object from which data will be pulled from	  
 	*/
	AUDS(const AUDS &other){

		//constructor preforms a DEEP copy on other
		current_size = other.current_size;
		current_value = other.current_value;
          	
		data = new T[current_size];
		for(int i = 0; i < current_size-1; i++){
			data[i] = other.data[i];
		}
	}

	/*
 	  Copy operator
	  @param other AUDS object from which data will be pulled from  
	*/
	AUDS& operator=(AUDS other){
		std::swap(current_size, other.current_size);
		std::swap(current_value, other.current_value);
		std::swap(data, other.data);

		return *this;
	}

     	/* 
 	  Default destructor  
	*/
	~AUDS(){

		//returns memory used by the data array
		delete[] data;
	}
	
	/*
 	  Returns the amount of elements stored in the object
	  @return current_value	
   	*/
	int size(){
		return current_value;
	}

	/*
 	  Adds element to the array
	  @param x element being added
  	*/
	void push(T x){

		//fires when the number of elements
		//exceeds the array's size
		if(current_value == current_size){

			//increases array size by 50%
			current_size *= 1.5;
			T* temp = new T[current_size];
	
			//moves values from the old array to the new
			for(int i = 0; i < current_value; i++){
                        	temp[i] = data[i];
                	}
	
			//frees memory from old array
			delete[] data;

			//moves pointer from old memory location
			//to the new one
			data = temp;
		}

		//adds element to the array
		data[current_value] = x;

		//increments current_value
		current_value++;
	}
     	/*
 	  Removes a random element from the array	
	  @return T element randomly popped from array
  	*/
	T pop(){

		//declaration of return value
		T rtn;
		srand(time(NULL));
		
		//random number chosen by 
		//the number of elements in the array
		int randomNum = rand() % (current_value);    
	 	rtn = data[randomNum];
		
		//decreases current_value to compensate for
		//removing an element
		current_value--;

		//replaces chosen element with last element		
		data[randomNum] = data[current_value];
		

        	return rtn;
	}	

private:
	/** current holding size of the array 
	 *  default size is 100 elements  */
	int current_size;

	/** current element in the array  */
	int current_value;
     	
	/** array that will hold the chosen type of elements  */
	T* data;
};


#endif 

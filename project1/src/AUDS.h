#ifndef _AUDS_H
#define _AUDS_H

#include <iostream>
#include <string>

template <typename T>

class AUDS{

public:
     AUDS(){
          initial_size = 0;
          current_size = 0;
          data = new T[initial_size];
     }
     
     AUDS(const AUDS &other){
          initial_size = other.initial_size;
          current_size = other.current_size;
          
          data = new T[initial_size];
          for(int i = 0; i < initial_size; i++){
               data[i] = other.data[i];
          }
     }
     
     ~AUDS(){
          delete[] data;
     }
     
     AUDS& operator=(AUDS other){
          std::swap(initial_size, other.inital_size);
          std::swap(current_size, other.current_size);
          std::swap(data, other.data);
  
          return *this;
     }

     int size(){
         return current_size;
     }
     void push(T x){
     }
     
     T pop(){
        //code here
        return data[0];
     }
private:
     int initial_size;
     int current_size;
     
     T* data;
};


#endif 

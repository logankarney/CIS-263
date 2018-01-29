#ifndef _AUDS_H
#define _AUDS_H

template <typename T>

class AUDS{

public:
     AUDS(){
          initial_size = 0;
          current_size = 0;
     }
     
     AUDS(const AUDS &other){
     }
     
     AUDS& operator=(AUDS other){
     }

     int size(){
         return current_size;
     }
     void push(T x){
     }

     ~AUDS(){
          //delete[] "data";
     }
private:
     int initial_size;
     int current_size;
     

};


#endif 

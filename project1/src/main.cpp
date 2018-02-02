#include <algorithm>
#include <string>
#include "catch.hpp"
#include "AUDS.h"

int main(){
       
        AUDS<std::string> a;

        for(int i = 0; i < 5; i++){
      
                a.push(std::to_string(i));
        }

        a.print_data();

        std::cout << std::endl;

        for(int i = 0; i < 5; i++){
                std::cout << a.pop() << std::endl;
        }
        std::cout << std::endl << a.size() << std::endl;
        return 0;
}


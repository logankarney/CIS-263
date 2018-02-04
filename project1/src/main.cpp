#define CATCH_CONFIG_MAIN  
#include <algorithm>
#include <string>
#include "catch.hpp"
#include "AUDS.h"

#include <algorithm>
#include <string>
#include "catch.hpp"
#include "AUDS.h"

/*int main(){       
        AUDS<std::string> a;

        for(int i = 0; i < 1000; i++){
      
                a.push(std::to_string(i));
        }

//        a.print_data();

        std::cout << a.size() <<  std::endl;

        //for(int i = 0; i < 1000; i++){
          //      std::cout << a.pop() << std::endl;
        //}
        //std::cout << std::endl << a.size() << std::endl;
     
	return 0;
}

*/

TEST_CASE( "Constructor test", "[creation]" ){
	AUDS<int> a;
	AUDS<float> b;
	AUDS<AUDS<int> > c;
	CHECK( a.size() == 0 );
	CHECK( b.size() == 0 );
	CHECK( c.size() == 0 );
}

TEST_CASE( "Push test", "[inner]" ){
	AUDS<int> a;
	for(int i=0; i<1000; i++){
		a.push(i);
	}
	CHECK( a.size() == 1000 );
}

TEST_CASE( "Pop test", "[inner]" ){
	AUDS<std::string> s;
	for(int i=0; i<100; i++){
		s.push("Item " + std::to_string(i));
	}
	for(int i=0; i<100; i++){
		std::cout << s.pop() << std::endl;
	}
	CHECK( s.size() == 0 );
} 


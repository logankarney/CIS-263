#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES /*https://www.quantstart.com/articles/Mathematical-Constants-in-C*/

int main(){
     float radius;
     std::cout << std::endl << "What is the radius of the circle?" << std::endl;

     std::cin >> radius;

     float area = pow(radius, 2);
     float perimeter = 2*M_PI*radius;

     std::cout << "The area of the circle is " << area << std::endl;
     std::cout << "The perimeter of the circle is " << perimeter << std::endl << std::endl; 
}

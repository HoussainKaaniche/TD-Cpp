#include "my_class.h"
#include <iostream>

my_class::my_class() {
    element = "";
}

my_class::my_class(std::string value) {
    element = value;
}

void my_class::print_my_element() {
    std::cout << element << std::endl;
}
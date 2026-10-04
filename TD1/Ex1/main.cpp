#include <iostream>
#include <string>

#include "main.h"
#include "my_class.h"

void print(std::string texte) {
    std::cout << texte << std::endl;
}

int main() {

    // Question 1
    std::cout << "Hello World !" << std::endl;

    // Questions 2 et 3
    print("Hello World !");

    // Question 4
    my_class objet1;
    my_class objet2("Hello World !");

    objet1.print_my_element();
    objet2.print_my_element();

    return 0;
}
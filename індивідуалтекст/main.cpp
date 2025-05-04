#include <iostream>
#include "text_processor.h"

int main() {
    char text[100]; 
    std::cout << "Write a text: ";
    std::cin.getline(text, 100);

    processText(text);

    std::cout << "Result: " << text << std::endl;
    return 0;
}

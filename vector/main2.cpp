#include <iostream>
#include <vector>


void shiftRight(std::vector<int>& vec, int shift) {
    int n = vec.size();
    shift = shift % n; 

    std::vector<int> temp(vec.end() - shift, vec.end());
    vec.insert(vec.begin(), temp.begin(), temp.end());   
    vec.erase(vec.end() - shift, vec.end());             
}


int main() {
    
    std::vector<int> vec(10);
    for (int i = 0; i < 10; i++) {
        vec[i] = i + 1;
    }

    std::cout << "До зсуву: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    shiftRight(vec, 3); 

    std::cout << "Після зсуву: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
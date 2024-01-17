#include <iostream>
#include <vector>

int main(){

    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    // {1,2,3}
    
    vec.erase(vec.begin() + 1);
    std::cout << vec.size();
    std::cout << vec.capacity();
    
   
    // vec.insert(vec.begin() + 1, 4);

    // vec.clear(); //удаляетвсе элементы


}
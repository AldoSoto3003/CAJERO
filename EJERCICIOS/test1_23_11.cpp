#include <iostream>

int main(){
    int x {};
    std::cout << (5 > 3 && 4 < 8) << '\n';
    std::cout << (4 > 6 && true ) << '\n';
    std::cout << (3 >= 3 || false) << '\n';
    std::cout << (true || false) ? 4: x ;
    return 0;
}
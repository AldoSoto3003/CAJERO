#include <iostream>

int main(){

    std::cout << (true && true) || false << '\n';
    std::cout << (false && false) || true << '\n';
    std::cout << (false && false) || false || true << '\n';
    std::cout << ( 5 > 6 || 4 > 3) && ( 7 > 8 ) << '\n';
    std::cout << !( 7 > 6 || 3 > 4) << '\n';
    return 0;
}
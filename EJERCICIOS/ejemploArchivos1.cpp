#include <fstream>  
#include <iostream>
#include <string>

int main(){
    std::ofstream outf{"sample.dat", std::ios::app};

    if (!outf){

        std::cerr << "Uh oh, Sample.dat no puede ser abierto en modo escritura! " << std::endl;
        return 1;
    }

outf << "this is line 3" << '\n';
outf << "This is line 4 "<< '\n';



    return 0;
}
#include <fstream>  
#include <iostream>
#include <string>

int main(){
    std::ofstream outf{"sample.dat", std::ios::app};

    if (!outf){

        std::cerr << "Uh oh, Sample.dat no puede ser abierto en modo escritura! " << std::endl;
        return 1;
    }

outf << "this is line 1" << '\n';
outf << "This is line 2 "<< '\n';
outf.close();

outf.open ("sample.dat" , std::ios::app);
outf << "This is line 3 \n";
outf << "This is line 4 \n";



 
    return 0;
}
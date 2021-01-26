#include<iostream>
#include<fstream>
#include<string>

int main(){ 
using std::ios;
   std::ifstream inf( "sample_1.dat", std::ifstream::binary);

    if (!inf){
        std::cerr << "Uh oh, Sample.dat no puede ser abierto en modo escritura! \n";
        return 1;
    }

std::string strData;

inf.seekg(5);
getline(inf,strData);
std::cout << strData << '\n';

inf.seekg(21, ios::cur);
std::getline(inf,strData);
std::cout << strData << '\n';

inf.seekg(-11, ios::end);
std::getline(inf,strData);
std::cout << strData << '\n';
}
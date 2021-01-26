
#include <fstream>  
#include <iostream>
#include <string>

int main(){
    using std::ios;
    std::ifstream inf{"sample.dat", std::ios::app};

inf.seekg (14, ios::cur);
inf.seekg (-18, ios::cur);
inf.seekg (22, ios::beg);
inf.seekg (24);
inf.seekg(-28, ios::end);
inf.seekg(0,ios::beg);
inf.seekg(0,ios::beg);

 
    return 0;
}
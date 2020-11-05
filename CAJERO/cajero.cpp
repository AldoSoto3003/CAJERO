#include<iostream>
#include<string>
#include<conio.h>
  //empiezo declaración de variables goblaes
    char *nombre[] = {"aldo soto" , "Fernando", "Gabriel" };
    int noCuenta[3];
    int passCuenta[3]; 
    int fondoCuenta1[3] = {100, 200, 300};
    int key{}, aux {0};
  //Termino declaración de 1varaibles globales
   


int login (){
    //variables locales
    int numeroCuenta{}, nip {};

    std::cout<<"Ingrese su numero de cuenta"<<'\n';
    std::cin >> numeroCuenta;


    std::cout<<"Ingrese su nip"<<'\n';
    std::cin >> nip;

    for (int i=0; i < 3, i++;){
     
        if ((numeroCuenta == noCuenta[i])  && (nip == passCuenta[i])){
            aux = 1;
            break;
         }

    }
    return 0;
}



int main(){
    noCuenta[0] = {111};
    passCuenta[0] = {444};

    login();

   if (aux == 0){
       std::cout<<"                             "<<'\n';
       std::cout<<"Numero de cuenta y/o password incorrectas"<<'\n';
       getch();
       exit(-1);
   }

    //Menú del programa 
    std::cout<<"Seleccione la opción que desea realizar:"<<'\n';
    std::cout<<"1.- consulta de saldo "<< '\n';
    std::cout<<"2.- retiro "<< '\n';
    std::cout<<"3.- deposito "<< '\n';
    std::cout<<"4.- trasnferencia "<< '\n';
    std::cout<<"5.- cambio de nip "<< '\n';

    std::cin >> key;
    
    //en el siguiente ciclo, valido que entre una opcion permitida
    //de lo contrario, que vuelva a ingresar una opción
    while((key > 5) or (key <1)){
        std::cout<<"Debe eligir una de las opciones validas"<<'\n';
        std::cin >> key;
    }
    
    switch (key){
        case 1:
          
        break;
        case 2:

        break;
        case 3:

        break;
        case 4:

        break;
        case 5:

        break;

    }
    getch();
    return 0  ;
}


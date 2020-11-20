#include<iostream>
#include<string>
#include<conio.h>
  //empiezo declaración de variables goblaes
    std::string nombres[3] = {"Aldo Soto", "Gabriel Valdez", "Ruben Berrelleza"};
    int noCuenta[3] = {123, 456, 789};
    int passCuenta[3] = {123, 456 ,789}; 
    int fondoCuenta[3] = {100, 200, 300};
    int key{}, aux {0}, pivote {}, opcion{};

  //Termino declaración de 1varaibles globales  
   
int login (){
    //variables locales
    int numeroCuenta{}, nip {};

    std::cout<<"Ingrese su numero de cuenta"<<'\n';
    std::cin >> numeroCuenta;

    std::cout<<"Ingrese su nip"<<'\n';
    std::cin >> nip;

    for(int i=0; i <= 3; i+=1){

         if (numeroCuenta == noCuenta[i]){
             if(nip == passCuenta[i]){
                 pivote = i;
                 aux = 1;
             }
        }
    }
    return 0;
}

int consultaDeSaldo(){

    std::cout <<"Hola estimado "  << nombres[pivote] << '\n';
    std::cout <<"su saldo actualmente es de: " << fondoCuenta[pivote] << '\n';

    std::cout << "desea realizar otra opcion ?" << '\n';
    std::cout << "1.- SI    2.- NO"<< '\n';
    std::cin >> opcion;
   
    return 0;
}

int retiro(){
    int montoRetirar {};

    std::cout <<" ingrese el monto a retirar: " << '\n';
    std::cin >> montoRetirar;

    if (montoRetirar > fondoCuenta[pivote]){
        std::cout << "Fondos insufucientes" << '\n';
    }else{ 
        fondoCuenta[pivote] -= montoRetirar;
        std::cout << "Retiro realizado con exito! " << '\n';
    }

    std::cout << "                 " << '\n';
    std::cout << "desea realizar otra opcion ?" << '\n';
    std::cout << "1.- SI    2.- NO"<< '\n';
    std::cin >> opcion;

    return 0;
}

int trasnferencia(){

    int cuentaTransferir {}, montoTransferir {}, pivote2{};

    std::cout << "Ingrese numero de cuenta a transferir " << '\n';
    std::cin >> cuentaTransferir;

    if(cuentaTransferir == noCuenta[pivote]){
        std::cout << "No se puede transferir a su misma cuenta" << '\n';
        exit(-1);
    }

    for(int i = 0; i < 3; i+=1){
        if (cuentaTransferir == noCuenta[i]){
            pivote2 = i;
            std::cout << "Ingrese monto a trasnferir ";
            std::cin >> montoTransferir;

            if (montoTransferir <= fondoCuenta[pivote]){
                fondoCuenta[pivote] -= montoTransferir;
                fondoCuenta[pivote2] += montoTransferir;

            }else if (montoTransferir > fondoCuenta[pivote]){
                std::cout << "Fondos insuficientes" << '\n';
            }
            
        }else if (i == 3){
            std::cout << "Ingrese un numero de cuenta valido "<< '\n';      
            i=4;   
        }
    }
    
    std::cout << "                 " << '\n';
    std::cout << "desea realizar otra opcion ?" << '\n';
    std::cout << "1.- SI    2.- NO"<< '\n';
    std::cin >> opcion;
    return 0;
}


int menu(){

     //Menú del programa 
    std::cout<<"Seleccione la opción que desea realizar:"<<'\n';
    std::cout<<"1.- consulta de saldo "<< '\n';
    std::cout<<"2.- retiro "<< '\n';
    std::cout<<"3.- deposito "<< '\n';
    std::cout<<"4.- trasnferencia "<< '\n';
    std::cout<<"5.- cambio de nip "<< '\n';
    std::cout<<"6.- salir"<< '\n';

    std::cin >> key;
    
    //en el siguiente ciclo, valido que entre una opcion permitida
    //de lo contrario, que vuelva a ingresar una opción
    while((key > 5) or (key <1)){
        std::cout<<"Debe eligir una de las opciones validas"<<'\n';
        std::cin >> key;
    }
    
    switch (key){
        case 1:
            consultaDeSaldo();
            
            if (opcion == 1 )
                 menu();
            else
                exit(-1);  

        break;
       
        case 2:

            retiro();

            if (opcion == 1 )
                menu();
            else
                exit(-1);  

        break;
        case 3:

           
            
        break;
        case 4:

             trasnferencia();

            if (opcion == 1 )
                menu();
            else
                exit(-1);
        break;
        case 5:

        break;
  
    }
    return 0;
}

int main(){

    login(); //Aqui llamo a la funcion que se encarga de verificar las credenciales del usuario

   if (aux == 0){
       std::cout<<"                             "<<'\n';
       std::cout<<"Numero de cuenta y/o password incorrectas"<<'\n';
       getch();
       exit(-1);
   }

    menu(); //llamo a la funcion menu, para que el usuario seleccione lo que desea hacer 
   
    getch();
    return 0 ;
}


#include<iostream>
#include<string>
#include<conio.h>
#include<windows.h>
  //empiezo declaración de variables goblaes
    std::string nombres[3] = {"Aldo Soto", "Gabriel Valdez", "Ruben Berrelleza"};
    int noCuenta[3] = {123, 456, 789};
    int passCuenta[3] = {123, 456 ,789}; 
    double fondoCuenta[3] = {100, 200, 300};
    int key{}, aux {0}, pivote {}, opcion{};
    int menu(),login(),trasnferencia(), retiro(), consultaDeSaldo(),changeNip();
            
  //Termino declaración de 1varaibles globales  

int otraOpcion(){
    std::cout << "                 " << '\n';
    std::cout << "desea realizar otra opcion ?" << '\n';
    std::cout << "1.- SI    2.- NO"<< '\n';
    std::cin >> opcion;

    if (opcion == 1){
        menu();
    }else if (opcion == 2){
        login();
    }else{
        std::cout << "Opcion no valida " << '\n';
        std::cout << "Vuelva a intentarlo " << '\n'; 
        otraOpcion();
    }
    return 0;
}


int changeNip(){
    int nipActual{}, nuevoNip1{}, nuevoNip2{}, flag{};

    std::cout << "Ingrese su nip actual: ";
    std::cin >> nipActual;
    
    if (nipActual == passCuenta[pivote]){
        while (flag == 0){
        std::cout << "Ingrese nuevo nip: " ;
        std::cin >> nuevoNip1;
        std::cout << "Confirme nuevo nip: ";
        std::cin >> nuevoNip2;
        if (nuevoNip1 == nuevoNip2){
            passCuenta[pivote] = nuevoNip1;
            std::cout << "El nip ha sido cambiado con exito!" << '\n';
            flag = 1;
        }else{
            std::cout << "El nuevo nip no coincide con la confirmación" << '\n';
            std::cout << "Intente de nuevo" << '\n';           
        }
      }    
    }else{
        std::cout << "No coincide su nip actual "<< '\n';
    }

   otraOpcion();
    return 0;
}  

int login (){
    //variables locales
    int numeroCuenta{}, nip {};
    aux = 0;
    std::cout<<"Ingrese su numero de cuenta"<<'\n';
    std::cin >> numeroCuenta;

    std::cout<<"Ingrese su nip"<<'\n';
    std::cin >> nip;
    for(int i=0; i <= 3; i+=1){

         if (numeroCuenta == noCuenta[i]){
             if(nip == passCuenta[i]){
                 pivote = i;
                 aux = 1;
                 i = 3;
             }
        }
    }

    if (aux == 0){
       std::cout<<"                             "<<'\n';
       std::cout<<"Numero de cuenta y/o password incorrectas"<<'\n';
       login();
   }

    menu();

    return 0;
}

int consultaDeSaldo(){

    std::cout <<"Hola estimado "  << nombres[pivote] << '\n';
    std::cout <<"su saldo actualmente es de: " << fondoCuenta[pivote] << '\n';

    otraOpcion();
   
    menu();
    return 0;
}

int retiro(){
    double montoRetirar {};

    std::cout <<" ingrese el monto a retirar: " << '\n';
    std::cin >> montoRetirar;

    if (montoRetirar<=0 ){
        std::cout << "No es posiblo retirar dicha cantidad" << '\n';
        system("cls");
        otraOpcion();
    }

    if (montoRetirar > fondoCuenta[pivote]){
        std::cout << "Fondos insufucientes" << '\n';
    }else{ 
        fondoCuenta[pivote] -= montoRetirar;
        std::cout << "Retiro realizado con exito! " << '\n';
    }

    otraOpcion();
        
    return 0;
}

int trasnferencia(){
    double montoTransferir{};
    int cuentaTransferir {}, pivote2{}, aux2{}, flag{0};

    std::cout << "Ingrese numero de cuenta a transferir " << '\n';
    std::cin >> cuentaTransferir;

    for(int i=0; i <= 3; i+=1){

         if (cuentaTransferir == noCuenta[i]){           
                 flag = 1;
        }
    }

    if(cuentaTransferir == noCuenta[pivote]){
        std::cout << "No se puede transferir a su misma cuenta" << '\n';
        menu();
    }else if(flag == 0){
        std::cout << "No se encontró cuenta para transferir" << '\n';
        menu();
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
    
    otraOpcion();
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
    std::cout<<"6.- cerrar sesión"<< '\n';
    std::cout<<"7.- SALIR" << '\n';

    std::cin >> key;
    
    //en el siguiente ciclo, valido que entre una opcion permitida
    //de lo contrario, que vuelva a ingresar una opción
    while((key <= 0) or (key >=8)){
        std::cout<<"Debe eligir una de las opciones validas"<<'\n';
        std::cin >> key;
    }
    
    switch (key){
        case 1:
            consultaDeSaldo();
            
            if (opcion == 1 )
                 menu();
            else
                login();  

        break;
       
        case 2:

            retiro();

            if (opcion == 1 )
                menu();
            else
                login();  

        break;
        case 3:
            trasnferencia();
           
            
        break;
        case 4:

             trasnferencia();

            if (opcion == 1 )
                menu();
            else
                login();
        break;
        case 5:
            changeNip();

            if (opcion == 1 )
                menu();
            else
                login();
        break;

        case 6:
            login();

        break;
        
        case 7:
            exit;
        break;
  
    }
    return 0;
}

int main(){

    login(); //Aqui llamo a la funcion que se encarga de verificar las credenciales del usuario

   
    getch();
    return 0 ;
}


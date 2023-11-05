#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//---------------------------------------------------------------------fechas-------------------------------------------
void valiteDate(char date[]){
    int day,month,year;
    if (sscanf(date, "%d/%d/%d", &day, &month, &year) == 3) {

        if ((day >= 1 && day <= 31) && (month >= 1 && month <= 12)) {

            if((month==2 &&day>29)||(month==4&&day>30)||(month==6&&day>30)||(month==9&&day>30)||(month==11&&day>30)){
                printf("fechas Inexistente");
                return;
            }
            printf("La fecha es: %d de ", day);
            switch (month) {
                case 1:
                    printf("enero");
                    break;
                case 2:
                    printf("febrero");
                    break;
                case 3:
                    printf("Marzo");
                    break;
                case 4:
                    printf("Abril");
                    break;
                case 5:
                    printf("Mayo");
                    break;
                case 6:
                    printf("Junio");
                    break;
                case 7:
                    printf("Julio");
                    break;
                case 8:
                    printf("Agosto");
                    break;
                case 9:
                    printf("Septiembre");
                    break;
                case 10:
                    printf("Octubre");
                    break;
                case 11:
                    printf("noviembre");
                    break;
                case 12:
                    printf("diciembre");
                    break;
            }
            printf(" de %d ",year);
        }

        else {
            printf("La fecha ingresada no es valida.\n");
        }
    } else {
        printf("Formato de fecha incorrecto. Use dd/mm/aaaa.\n");
    }
}
//------------------------------------------------------ROMANOS--------------------------------------------------------
char* calculateNumber(int number) {
    int miles, decenas, centenas, unidades;
    char *romano = (char *) malloc(100);;
// acá saco los valores que necesitamos para descomponer el numero
    miles = number / 1000;
    centenas = (number / 100) % 10;
    decenas = (number / 10) % 10;
    unidades = number % 10;

    romano[0] = '\0';
//miles(para los miles los recorro para contar cuantas "M" necesitamos)
    for (int i = 1; i <= miles; i++) {
        strcat(romano, "M");
    }
//busco centenas
    if (centenas == 9) {
        strcat(romano, "CM");
    } else if (centenas >= 5) {
        strcat(romano, "D");
        for (int i = 6; i <= centenas; i++) {
            strcat(romano, "C");
        }
    } else if (centenas == 4) {
        strcat(romano, "CD");
    } else {
        for (int i = 1; i <= centenas; i++) {
            strcat(romano, "C");
        }
    }
    //busco las decenas
    if (decenas == 9) {
        strcat(romano, "XC");
    } else if (decenas >= 5) {
        strcat(romano, "L");
        for (int i = 6; i <= decenas; i++) {
            strcat(romano, "X");
        }
    } else if (decenas == 4) {
        strcat(romano, "XL");
    } else {
        for (int i = 1; i <= decenas; i++) {
            strcat(romano, "X");
        }
    }
    //acá busco las unidades del number
    if (unidades == 9) {
        strcat(romano, "IX");
    } else if (unidades >= 5) {
        strcat(romano, "V");
        for (int i = 6; i <= unidades; i++) {
            strcat(romano, "I");
        }
    } else if (unidades == 4) {
        strcat(romano, "IV");
    } else {
        for (int i = 1; i <= unidades; i++) {
            strcat(romano, "I");
        }
    }
    return romano;
}

//Own Name�s Function

void ownName(char* str){


    //Eliminar los espacios

    for(int i  = 0, j = 0; i < strlen(str); i++){
        if(str[i] != ' '){
            str[j] = str[i];
            j++;
        }
    }

    str[0] = toupper(str[0]);

    printf("%s", str);
}

int main() {
    int option,number;
    char dateIn[10];
    char name[10];
    printf("------Bienvenido a su menu de funciones------\n"
           "1. Convierte de Numeros entero a numeros romano\n"
           "2. Factores Primos. \n"
           "3. Nombre Propio.\n"
           "4. Numeros Egolatras.\n"
           "5. Numeros Amigos.\n"
           "6. Fechas.\n"
           "7. Producto Punto\n"
           "8. Multiplicacion de Matrices.\n"
           "9. Matriz Magica.\n"
           "10. Salir\n");
    scanf("%d",&option);

    switch(option){
        case 1:
            printf("\nBienvenido  a la funcion para convertir de numeros enteros a numeros romanos por favor.\nDigite un numero entre 1 y 3000 \n");
            scanf("%i",&number);
            if((number>=1)&&(number<=3000)){
                char *result= calculateNumber(number);
                printf("El resultado de su numero es ...: %s",result);
                free(result);
            }else{
                printf("Digite un numero entre 1 y 3000");
            }
            break;
        case 2:
            break;
        case 3:
            printf("Ingrese el nombre que desea convertir a nombre propio: ");
            scanf("%s", name);
            ownName(name);

            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            printf("ingrese una fecha en el formato dd/mm/aaaa\n");
            scanf("%s",dateIn);
            valiteDate(dateIn);
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
    }
    return 0;
}

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//---------------------------------------------------------------------fechas-------------------------------------------
void valiteDate(char date[])
{
    int day, month, year;
    if (sscanf(date, "%d/%d/%d", &day, &month, &year) == 3)
    {

        if ((day >= 1 && day <= 31) && (month >= 1 && month <= 12))
        {

            if ((month == 2 && day > 29) || (month == 4 && day > 30) || (month == 6 && day > 30) || (month == 9 && day > 30) || (month == 11 && day > 30))
            {
                printf("Fecha Inexistente");
                return;
            }
            printf("La fecha es: %d de ", day);
            switch (month)
            {
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
                printf("Octubre ");
                break;
            case 11:
                printf("noviembre");
                break;
            case 12:
                printf("diciembre");
                break;
            }
            printf(" de %d ", year);
        }

        else
        {
            printf("La fecha ingresada no es valida.\n");
        }
    }
    else
    {
        printf("Formato de fecha incorrecto. Use dd/mm/aaaa.\n");
    }
}
//------------------------------------------------------ROMANOS--------------------------------------------------------
char *calculateNumber(int number)
{
    int miles, decenas, centenas, unidades;
    char *romano = (char *)malloc(100);
    ;
    // acá saco los valores que necesitamos para descomponer el numero
    miles = number / 1000;
    centenas = (number / 100) % 10;
    decenas = (number / 10) % 10;
    unidades = number % 10;

    romano[0] = '\0';
    // miles(para los miles los recorro para contar cuantas "M" necesitamos)
    for (int i = 1; i <= miles; i++)
    {
        strcat(romano, "M");
    }
    // busco centenas
    if (centenas == 9)
    {
        strcat(romano, "CM");
    }
    else if (centenas >= 5)
    {
        strcat(romano, "D");
        for (int i = 6; i <= centenas; i++)
        {
            strcat(romano, "C");
        }
    }
    else if (centenas == 4)
    {
        strcat(romano, "CD");
    }
    else
    {
        for (int i = 1; i <= centenas; i++)
        {
            strcat(romano, "C");
        }
    }
    // busco las decenas
    if (decenas == 9)
    {
        strcat(romano, "XC");
    }
    else if (decenas >= 5)
    {
        strcat(romano, "L");
        for (int i = 6; i <= decenas; i++)
        {
            strcat(romano, "X");
        }
    }
    else if (decenas == 4)
    {
        strcat(romano, "XL");
    }
    else
    {
        for (int i = 1; i <= decenas; i++)
        {
            strcat(romano, "X");
        }
    }
    // acá busco las unidades del number
    if (unidades == 9)
    {
        strcat(romano, "IX");
    }
    else if (unidades >= 5)
    {
        strcat(romano, "V");
        for (int i = 6; i <= unidades; i++)
        {
            strcat(romano, "I");
        }
    }
    else if (unidades == 4)
    {
        strcat(romano, "IV");
    }
    else
    {
        for (int i = 1; i <= unidades; i++)
        {
            strcat(romano, "I");
        }
    }
    return romano;
}

//Factores Primos

void factoresPrimos(int numero) {
    int i;
    int potencia;
    int factores[100];  // Array para almacenar los factores primos
    int exponentes[100];  // Array para almacenar los exponentes de los factores primos
    int num_factors = 0;  // Número de factores primos encontrados hasta ahora

    // For para buscar el numero de factores primos del numero ingresado
    for (i = 2; i <= sqrt(numero); i++) {
        potencia = 0;
        while (numero % i == 0) {
            potencia++;
            numero /= i;
        }
        if (potencia > 0) {
            factores[num_factors] = i;
            exponentes[num_factors] = potencia;
            num_factors++;
        }
    }

    // If n is a prime number greater than 2
    if (numero > 2) {
        factores[num_factors] = numero;
        exponentes[num_factors] = 1;
        num_factors++;
    }

    // Ordena los factores primos de mayor a menor
    for (i = 0; i < num_factors - 1; i++) {
        for (int j = i + 1; j < num_factors; j++) {
            if (factores[i] < factores[j]) {
                int temp = factores[i];
                factores[i] = factores[j];
                factores[j] = temp;
                temp = exponentes[i];
                exponentes[i] = exponentes[j];
                exponentes[j] = temp;
            }
        }
    }

    // Imprime la factorización de primos en formato potencia
    for (i = 0; i < num_factors; i++) {
        printf("%d^%d ", factores[i], exponentes[i]);
    }
    printf("\n");
}

//Auxiliar de los factores primos

int aux_factoresPrimos() {

    int n;
    //Le pedimos al usuario que ingrese un numero
    printf("Ingrese un numero... : ");
    //capturamos el numero ingresado
    scanf("%d", &n);
    printf("la descomposicion del numero en potencias de sus factores primos %d es: ", n);
    factoresPrimos(n);

    return 0;

}

// Own Names Function

void ownName(char *str)
{
    for (int i = 0; str[i]; i++) {

            str[i] = tolower(str[i]);
        
        
    }

    char *split;
    char *aux[50];
    int i = 0;
    split = strtok(str, " ");
    while (split != NULL)
    {
        aux[i] = split;
        i++;
        split = strtok(NULL, " ");
    }
    for (int j = 0; j < i; j++)
    {
        if (strlen(aux[j]) > 1)

        
        {
            aux[j][0] = toupper(aux[j][0]);
        }
        printf("%s ", aux[j]);
    }
    printf("\n");
}

int sumDivisors(int number)
{

    int suma = 1;
    for (int i = 2; i <= number / 2; i++)
    {

        if (number % i == 0)
        {
            suma += i;
        }
    }

    return suma;
}

//Numeros Egolatras

int Numeros_Egolatras(int n){
    int numeroDigitos =floor(log10(n)+1);
    char cadena [numeroDigitos + 1];;

    sprintf (cadena,"%d",n);

    int suma=0;
    for(int i=0;i<numeroDigitos; i++){
        int cont = cadena[i] - '0';

        int elevado = pow(cont, numeroDigitos);
        suma=suma +elevado;
    }
    if(suma==n){
        return 1;
    }else{
        return 0;
    }
}


void friendsNumbers(int num1, int num2)
{

    // SUMA DE LOS DIVISORES DEL PRIMER NUMERO

    if (sumDivisors(num1) == num2 && sumDivisors(num2) == num1)
    {
        printf("True: (%i y %i son numeros amigos)\n", num1, num2);
    }
    else
    {
        printf("False: (%i y %i NO son numeros amigos)\n", num1, num2);
    }
}

int scalarProduct(int array1[], int array2[], int size)
{

    int scalar = 0;
    for (int i = 0; i < size; i++)
    {
        scalar += array1[i] * array2[i];
    }

    return scalar;
}

// Multiplicación Matriz

int multiplicacionMatriz() {
    int a[15][15], b[15][15], c[15][15];
    int f1, f2, c1, c2;

    int cont, aux;

    printf("\n Agregue el numero de filas de la matriz 1 \n");
    scanf("%d", &f1);

    printf("Agregue el numero de columnas de la matriz 1 \n");
    scanf("%d", &c1);

    printf("Agregue el numero de filas de la matriz 2 \n ");
    scanf("%d", &f2);

    printf("Agregue el numero de columnas de la matriz 2 \n");
    scanf("%d", &c2);


    if (f1 == c2) {


        for (int i = 0; i < f1; ++i) {
            for (int j = 0; j < c1; ++j) {
                a[i][j] = rand() % 9 + 1;
            }
        }

        for (int i = 0; i < f2; ++i) {
            for (int j = 0; j < c2; ++j) {
                b[i][j] = rand() % 9 + 1;
            }
        }

        for (int i = 0; i < f1; ++i) {
            for (int j = 0; j < c1; ++j) {
                for (cont = 0, aux = 0; cont < c1; ++cont) {
                    aux = aux + a[i][cont] * b[cont][j];
                }
                c[i][j] = aux;
            }
        }

        printf("\nPrimer matriz8");
        for (int i = 0; i < f1; ++i) {
            printf("\n");
            for (int j = 0; j < c1; ++j) {
                printf("\t%d", a[i][j]);
            }
        }

        printf("\n Segunda matriz");
        for (int i = 0; i < f2; ++i) {
            printf("\n");
            for (int j = 0; j < c2; ++j) {
                printf("%d", b[i][j]);
            }
        }

        printf("\n Multiplicacion de matriz\n");
        for (int i = 0; i < f1; ++i) {
            printf("\n");
            for (int j = 0; j < c2; ++j) {
                printf("%d", c[i][j]);
            }
        }
    } else {
        printf("Null\n");
        return 0;

    }

    return 0;
}
//----------------------------matriz magica----------------------------------

void generarMatrizMagica(int orden, int matriz[][orden]) {
    int i, j;

    // Inicializar la matriz con ceros
    for(i = 0; i < orden; i++) {
        for(j = 0; j < orden; j++) {
            matriz[i][j] = 0;
        }
    }

    // Inicializar las posiciones iniciales
    i = 0;
    j = orden / 2;

    // Llenar la matriz con valores
    for(int num = 1; num <= orden * orden; num++) {
        matriz[i][j] = num;
        i--;
        j++;

        // Si i se vuelve negativo, regresar al último renglón
        if(i < 0) {
            i = orden - 1;
        }

        // Si j se va más allá de la última columna, regresar a la primera columna
        if(j == orden) {
            j = 0;
        }

        // Si la celda ya está ocupada, retroceder una fila y avanzar una columna
        if(matriz[i][j] != 0) {
            i += 2;
            j--;
        }
    }
}

void imprimirMatriz(int orden, int matriz[][orden]) {
    for(int i = 0; i < orden; i++) {
        for(int j = 0; j < orden; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}



void split(char arr1[], char arr2[])
{
    char *split = strtok(arr1, ",");
    int numbers1[50];
    int numbers2[50];
    int i = 0, j = 0;
    while (split != NULL)
    {
        numbers1[i] = atoi(split);
        i++;
        split = strtok(NULL, ",");
    }
    split = strtok(arr2, ",");
    while (split != NULL)
    {
        numbers2[j] = atoi(split);
        j++;
        split = strtok(NULL, ",");
    }

    if (i != j)
    {
        printf("Los dos arreglos deben tener la misma cantidad de datos\n");
    }
    else
    {
        int scalar = scalarProduct(numbers1, numbers2, i);
        printf("El producto PUNTO de los 2 arreglos es: %d\n", scalar);
    }
}

int main()
{
    int option, number, num1, num2, orden;
    int matriz [orden][orden];
    char dateIn[10];
    char name[80];
    char arrayAux1[50];
    char arrayAux2[50];
    do
    {
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
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nBienvenido  a la funcion para convertir de numeros enteros a numeros romanos.\nDigite un numero entre 1 y 3000 \n");
            scanf("%i", &number);
            if ((number >= 1) && (number <= 3000))
            {
                char *result = calculateNumber(number);
                printf("El resultado de su numero es ...: %s\n", result);
                free(result);
            }
            else
            {
                printf("Digite un numero entre 1 y 3000\n");
            }
            break;
        case 2:
            printf("--Factores Primos--\n");
                aux_factoresPrimos();
                break;
        case 3:
            printf("Ingrese el nombre que desea convertir a nombre propio: \n");
            fgets(name, 40, stdin);
            fgets(name, 40, stdin);
            ownName(name);

            break;
                int num;
            case 4:

                num = 0;
                printf("-------Numeros Egolatras-----\n");
                printf("Ingrese el numero \n ");
                scanf("%d",&num);
                printf("El numero %d %s",num, Numeros_Egolatras( num)?"es egolatra":"No es egolatra\n");


                break;
            break;

        case 5:

            printf("Digite dos valores numericos para comprobar si son numeros amigos:\n");
            scanf("%i", &num1);
            scanf("%i", &num2);
            friendsNumbers(num1, num2);
            break;
        case 6:
            printf("Ingrese una fecha en el formato dd/mm/aaaa\n");
            scanf("%s", dateIn);
            valiteDate(dateIn);
            break;
        case 7:
            printf("Digite los datos de la primer matriz, separelos por comas (Ej: 2,3,5,6)\n");
            fgets(arrayAux1, 50, stdin);
            fgets(arrayAux1, 50, stdin);
            printf("Digite los datos de la segunda matriz, separelos por comas (Ej: 2,3,5,6)\n");
            fgets(arrayAux2, 50, stdin);

            split(arrayAux1, arrayAux2);
            break;
        case 8:
            printf("---Multiplicacion de Matrices--");
                multiplicacionMatriz();
                printf("\n");
            break;
        case 9:
            printf("Ingrese el orden de la matriz (debe ser un número impar):");
                scanf("%d",&orden);
                if(orden%2==0){
                    printf("el orden debe ser un numero impar");
                    return 1;
                }
                //genero la matriz magica
                generarMatrizMagica(orden, matriz);
                // mostrar la matriz mágica
                printf("Matriz mágica de orden %d:\n", orden);
                imprimirMatriz(orden, matriz);
            break;
        case 10:
            printf("gracias por utlilizar nuestras Funciones");
            break;
        default:
            printf("Opcion Invalida!\n");
            break;
        }
    } while (option != 10);

    return 0;
}

#include <iostream>
#include <cctype>
#include <string>

int main() {
    int estado = 1; // Inicializamos el estado en 1
    std::string cadena;

    std::cout << "Ingrese el nombre de su variable: ";
    std::cin >> cadena;

    for (char simbolo : cadena) {
        switch (estado) {
            case 1:
                if (isalpha(simbolo)) { // Si simbolo es una letra
                    estado = 2;
                } else if (isdigit(simbolo)) { // Si simbolo es un dígito del 0 al 9
                    estado = 3;
                } else {
                    std::cout << "La cadena murió en Estado 1." << std::endl;
                    std::cerr << "Error del sistema" << std::endl;
                    return 1; // Salir del programa con error
                }
                break;
            case 2:
                if (isalpha(simbolo)) { // Si simbolo es una letra
                    estado = 2;
                } else if (isdigit(simbolo)) { // Si simbolo es un dígito del 0 al 9
                    estado = 2;
                } else {
                    std::cout << "La cadena murió en Estado 2." << std::endl;
                    std::cerr << "Error del sistema" << std::endl;
                    return 1; // Salir del programa con error
                }
                break;
            case 3:
                std::cout << "La cadena murió en Estado 3." << std::endl;
                std::cerr << "Error del sistema" << std::endl;
                return 1; // Salir del programa con error
                break;
        }
    }

    if (estado != 2) {
        std::cerr << "Error del sistema" << std::endl;
        return 1; // Salir del programa con error
    }

    std::cout << "La cadena es válida." << std::endl;
    return 0; // Salir del programa con éxito
}
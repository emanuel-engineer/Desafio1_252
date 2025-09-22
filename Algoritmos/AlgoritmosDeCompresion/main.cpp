#include <iostream>

using namespace std;


char* RLE (const char* input){

    if (input == nullptr || input[0] == '\0') {
        char* resultado = new char[1];
        resultado[0] = '\0';
        return resultado;
    }

    // Primera pasada: calcular el tamaño necesario
    int longi_input = 0;
    while (input[longi_input] != '\0') longi_input++;

    int maxim_output = longi_input * 2 + 1; // Máximo posible
    char* output = new char[maxim_output];
    int index_output = 0;

    int i = 0;
    while (i < longi_input) {
        char char_actual = input[i];
        int count = 1;

        // Contar caracteres consecutivos iguales
        while (i + count < longi_input && input[i + count] == char_actual && count < 9) {
            count++;
        }

        // Codificar: carácter + contador (como dígito)
        output[index_output++] = char_actual;
        output[index_output++] = '0' + count; // Convertir número a carácter

        i += count;
    }

    output[index_output] = '\0'; // Terminar la cadena

    return output;

}

int main()
{

    // Ejemplos de prueba
    const char* test1 = "AAABBBCCD";
    const char* test2 = "ABCDE";
    const char* test3 = "A";
    const char* test4 = "AAAAAFFFFKK";
    const char* test5 = "HOLA QUE HACES";

    char* encoded1 = RLE(test1);
    char* encoded2 = RLE(test2);
    char* encoded3 = RLE(test3);
    char* encoded4 = RLE(test4);
    char* encoded5 = RLE(test5);

    std::cout << "Original: " << test1 << " -> RLE: " << encoded1 << std::endl;
    std::cout << "Original: " << test2 << " -> RLE: " << encoded2 << std::endl;
    std::cout << "Original: " << test3 << " -> RLE: " << encoded3 << std::endl;
    std::cout << "Original: " << test4 << " -> RLE: " << encoded4 << std::endl;
    std::cout << "Original: " << test5 << " -> RLE: " << encoded5 << std::endl;

    // Liberar memoria
    delete[] encoded1;
    delete[] encoded2;
    delete[] encoded3;
    delete[] encoded4;




    return 0;
}

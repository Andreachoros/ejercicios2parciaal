#include <iostream>
#include <filesystem>
#include <windows.h>
#include <fstream>

namespace fs = std::filesystem;

void agregueleTextoALosArchivos() {
    for (int i = 1; i <= 5; ++i) {
        std::string nombreArchivo = "file" + std::to_string(i) + ".txt";
        std::ofstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            for (int j = 0; j < i; ++j) {
                archivo << "Texto para el archivo " << i << ", línea " << j + 1 << "\n";
            }
            archivo.close();
            std::cout << "Se ha creado y llenado el archivo: " << nombreArchivo << std::endl;
        } else {
            std::cerr << "Error al crear el archivo: " << nombreArchivo << std::endl;
        }
    }
}

int main() {
    agregueleTextoALosArchivos();

}

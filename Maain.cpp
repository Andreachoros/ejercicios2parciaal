#include <iostream>
#include <filesystem>
#include <windows.h>
#include <fstream>

namespace fs = std::filesystem;

void crearArchivos(int cantidad) {
    std::string desktopPath = getenv("USERPROFILE");
    desktopPath += "\\Desktop\\";

    std::string directoryName;
    if (cantidad % 2 == 0) {
        directoryName = "par";
    } else {
        directoryName = "impar";
    }

    fs::path directoryPath = desktopPath + "\\" + directoryName;

    if (!fs::exists(directoryPath)) {
        fs::create_directory(directoryPath);
    }

    for (int i = 1; i <= cantidad; ++i) {
        std::string fileName = "file" + std::to_string(i) + ".txt";
        fs::path filePath = directoryPath / fileName;

        std::ofstream file(filePath);
        if (file.is_open()) {
            file << "Contenido del archivo " << fileName << std::endl;
            file.close();
            std::cout << "Archivo creado: " << filePath << std::endl;
        } else {
            std::cerr << "Error al crear el archivo: " << filePath << std::endl;
        }
    }
}

int main() {
    int cantidadArchivos;
    std::cout << "Ingrese la cantidad de archivos a crear: ";
    std::cin >> cantidadArchivos;

    crearArchivos(cantidadArchivos);

    return 0;
}
#pragma once

#include <iostream>
#include <cstdarg> // Para manejar argumentos variádicos
#include <cstdio>  // Para sprintf
#include <string>

#define DEBUG_LOG(message, ...) Debug::Log(__FILE__, message, __VA_ARGS__)

class Debug {
public:
    static void Log(const std::string& fileName, const char* format, ...) {
        // Extraer solo el nombre del archivo (sin ruta)
        size_t pos = fileName.find_last_of("/\\");
        std::string className = (pos == std::string::npos) ? fileName : fileName.substr(pos + 1);

        // Buffer para el mensaje formateado
        char buffer[1024];

        // Manejo de argumentos variádicos
        va_list args;
        va_start(args, format);
        vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);

        // Imprimir el mensaje
        std::cout << "[Log : " << className << "] " << buffer << std::endl;
    }
};
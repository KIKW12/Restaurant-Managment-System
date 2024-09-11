#ifndef MESERO_H
#define MESERO_H

#include <string>

class Mesero {
private:
    std::string nombre;
    std::string password;

public:
    Mesero(const std::string& nombre, const std::string& password);

    bool verificarCredenciales(const std::string& inputPassword) const;
    const std::string& getNombre() const;
};

#endif // MESERO_H

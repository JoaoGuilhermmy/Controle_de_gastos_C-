#ifndef DESPESAS_H
#define DESPESAS_H

#include <string>
#include <vector>

class Despesa
{
private:
    std::string descricao;
    double valor;
    std::string data;
    std::string categoria;

public:
    Despesa();
    Despesa(std::string descricao, double valor, std::string data, std::string categoria);

    std::string getDescricao() const;
    double getValor() const;
    std::string getData() const;
    std::string getCategoria() const;
};

#endif
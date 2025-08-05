#include "Despesa.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Despesa::Despesa(std::string descricao, double valor, std::string data, std::string categoria)
{
    this->descricao = descricao;
    this->valor = valor;
    this->data = data;
    this->categoria = categoria;
}

std::string Despesa::getDescricao() const
{
    return this->descricao;
}

double Despesa::getValor() const
{
    return this->valor;
}

std::string Despesa::getData() const
{
    return this->data;
}

std::string Despesa::getCategoria() const
{
    return this->categoria;
}

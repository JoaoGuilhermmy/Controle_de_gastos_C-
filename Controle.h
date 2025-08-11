#ifndef CONTROLEFINANCEIRO_H
#define CONTROLEFINANCEIRO_H

#include "Despesa.h"
#include <vector>
#include <string>

class ControleFinanceiro
{
private:
    std::vector<std::string> categorias;
    std::vector<Despesa> despesas;

public:
    ControleFinanceiro();

    void salvarcontrole() const;
    void carregarcontrole();
    void listardespesas() const;
    void adicionardespesa();
    void limpatela() const;
    void calcular() const;
    void removerdespesa();
    void filtrardespesas() const;
    void filtrar_mes() const;
};

#endif
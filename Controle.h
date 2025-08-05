#ifndef CONTROLEFINANCEIRO_H
#define CONTROLEFINANCEIRO_H

#include "Despesa.h"
#include <vector>

class ControleFinanceiro
{
private:
    std::vector<Despesa> despesas;

public:
    ControleFinanceiro();

    void salvarcontrole() const;
    void carregarcontrole();
    void listardespesas() const;
    void adicionardespesa();
};

#endif
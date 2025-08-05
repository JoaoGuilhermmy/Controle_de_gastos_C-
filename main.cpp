#include "Controle.h"
#include <iostream>

int main()
{
    ControleFinanceiro despesa;

    while (true)
    {
        int opcao;
        std::cout << "Escolha uma opcao:" << std::endl;
        std::cout << "1 - Adicionar despesa" << std::endl;
        std::cout << "2 - Listar despesas" << std::endl;
        std::cout << "3 - Sair" << std::endl;
        std::cout << "Opcao: ";
        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
            despesa.adicionardespesa();
            break;
        case 2:
            despesa.listardespesas();
            break;
        case 3:
            despesa.salvarcontrole();
            return 0;
        default:
            std::cout << "Opcao invalida" << std::endl;
        }
    }

    return 0;
}
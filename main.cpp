#include "Controle.h"
#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    ControleFinanceiro despesa;

    while (true)
    {
        int opcao;
        std::cout << "\t -------------- Controle Financeiro --------------" << std::endl;
        std::cout << "Escolha uma opcao:" << std::endl;
        std::cout << "1 - Adicionar despesa" << std::endl;
        std::cout << "2 - Listar despesas" << std::endl;
        std::cout << "3 - Sair" << std::endl;
        std::cout << "Digite sua opção: ";
        std::cin >> opcao;
        despesa.limpatela();

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
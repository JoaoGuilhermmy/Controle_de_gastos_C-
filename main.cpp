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
        std::cout << "3 - Calcular total de despesas" << std::endl;
        std::cout << "4 - Remover despesa" << std::endl;
        std::cout << "5 - Mostrar depesas com filtro" << std::endl;
        std::cout << "6 - Filtrar por mês" << std::endl;
        std::cout << "7 - Sair" << std::endl;
        std::cout << "Digite sua opção: ";
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
            despesa.calcular();
            break;
        case 4:
            despesa.removerdespesa();
            break;
        case 5:
            despesa.filtrardespesas();
            break;
        case 6:
            despesa.filtrar_mes();
            break;
        case 7:
            despesa.salvarcontrole();
            return 0;
        default:
            std::cout << "Opcao invalida, digite uma opção que esta no menu" << std::endl;
            Sleep(3000);
            despesa.limpatela();
        }
    }

    std::cout << "Despesas salvas com sucesso!" << std::endl;
    Sleep(3000);
    return 0;
}
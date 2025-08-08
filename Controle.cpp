#include "Controle.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <windows.h>
#include <iomanip>

ControleFinanceiro::ControleFinanceiro()
{
    carregarcontrole();
}

void ControleFinanceiro::carregarcontrole()
{
    std::ifstream arquivo_entrada("despesas.txt");
    std::string linha;

    if (arquivo_entrada.is_open())
    {
        while (getline(arquivo_entrada, linha))
        {
            std::string descricao, data, categoria, valor_str;
            std::stringstream ss(linha);

            std::getline(ss, descricao, ';');
            std::getline(ss, valor_str, ';');
            std::getline(ss, data, ';');
            std::getline(ss, categoria, ';');
            double valor = std::stod(valor_str);

            this->despesas.push_back(Despesa(descricao, valor, data, categoria));
        }
        arquivo_entrada.close();
        std::cout << "Despesas carregadas com sucesso!" << std::endl;

        Sleep(3000);
        limpatela();
    }
    else
    {
        std::cout << "Arquivo de despesas nao encontrado. Um novo sera criado ao sair." << std::endl;
        Sleep(3000);
        limpatela();
    }
}

void ControleFinanceiro::salvarcontrole() const
{
    std::ofstream arquivo_saida("despesas.txt");
    if (arquivo_saida.is_open())
    {
        for (const auto &despesas : despesas)
        {
            arquivo_saida << despesas.getDescricao() << ";" << despesas.getValor() << ";" << despesas.getData() << ";" << despesas.getCategoria() << std::endl;
        }
        arquivo_saida.close();
    }
    else
    {
        std::cout << "Erro ao abrir o arquivo de despesas." << std::endl;
    }
    limpatela();
}

void ControleFinanceiro::listardespesas() const
{

    const int largura = 15;
    if (despesas.empty())
    {
        std::cout << "Nenhuma despesa cadastrada." << std::endl;
        return;
    }
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "\t ***Lista de Despesas*** " << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "  " << std::left << std::setw(largura) << "----------------------------" << std::endl;
    std::cout << std::fixed << std::setprecision(2);

    for (const auto &despesa : despesas)
    {
        std::cout << "  " << std::left << std::setw(19) << "Descrição: " << despesa.getDescricao() << std::endl;
        std::cout << "  " << std::left << std::setw(largura) << "Valor: " << "R$" << despesa.getValor() << std::endl;
        std::cout << "  " << std::left << std::setw(largura) << "Data: " << despesa.getData() << std::endl;
        std::cout << "  " << std::left << std::setw(largura) << "Categoria:" << despesa.getCategoria() << std::endl;
        std::cout << "  " << std::left << std::setw(largura) << "----------------------------" << std::endl;
    }
    Sleep(5000);
    limpatela();
}

void ControleFinanceiro::adicionardespesa()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string descricao, data, categoria;
    double valor;

    std::cout << "\t -------------- Cadastro da Despesa --------------" << std::endl;

    std::cout << "Digite a descrição da despesa: ";
    std::getline(std::cin, descricao);

    std::cout << "Digite o valor da despesa: ";
    std::cin >> valor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Digite a data da despesa: (dd/mm/aaaa): ";
    std::getline(std::cin, data);

    std::cout << "Digite a categoria da despesa: ";
    std::getline(std::cin, categoria);

    Despesa despesa(descricao, valor, data, categoria);
    despesas.push_back(despesa);

    salvarcontrole();
    std::cout << "Despesa salva com sucesso!" << std::endl;
    Sleep(3000);
    limpatela();
}

void ControleFinanceiro::limpatela() const
{
    system("cls");
}

void ControleFinanceiro::calcular() const
{
    double soma = 0.0;
    for (const auto &despesas : despesas)
    {
        soma += despesas.getValor();
    }
    std::cout << "Total de despesas: R$" << soma << std::endl;
    Sleep(3000);
    limpatela();
}

void ControleFinanceiro::removerdespesa()
{
    if (despesas.empty())
    {
        std::cout << "Nenhuma despesa cadastrada." << std::endl;
        return;
    }

    int indice;

    const int largura = 15;
    int contador = 0;

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "\t ***Lista de Despesas*** " << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "  " << std::left << std::setw(largura) << "----------------------------" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    for (auto &despesas : despesas)
    {
        std::cout << "  " << std::left << std::setw(2) << "Despesa" << "#" << contador + 1 << std::endl;
        std::cout << "  " << std::left << std::setw(19) << "Descrição: " << despesas.getDescricao() << std::endl;
        std::cout << "  " << std::left << std::setw(largura) << "Valor: " << "R$" << despesas.getValor() << std::endl;
        std::cout << "  " << std::left << std::setw(largura) << "Data: " << despesas.getData() << std::endl;
        std::cout << "  " << std::left << std::setw(largura) << "Categoria:" << despesas.getCategoria() << std::endl;
        std::cout << "  " << std::left << std::setw(largura) << "----------------------------" << std::endl;
        contador++;
    }
    std::cout << "Digite o número da despesa que deseja remover (digite 0 para cancelar a opeação): ";
    std::cin >> indice;

    if (indice == 0)
    {
        std::cout << "Operação cancelada." << std::endl;
        Sleep(3000);
        limpatela();
        return;
    }

    despesas.erase(despesas.begin() + indice - 1);
    salvarcontrole();

    std::cout << "Despesa removida com sucesso!" << std::endl;
    Sleep(3000);
    limpatela();
}

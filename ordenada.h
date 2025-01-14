//
// Created by IFPE on 19/12/2024.
//

#ifndef PRATICA_06_ORDENADA_H
#define PRATICA_06_ORDENADA_H

#include <iostream>

using namespace std;

class ListaOrdenada {
private:
    int * itens;
    int tamanho, capacidade;

public:
    explicit ListaOrdenada(int cap) {
        this->capacidade = cap;
        this->tamanho = 0;
        itens = new int[cap];
    }

    ~ListaOrdenada() {
        delete [] itens;
    }

    void insere(int valor) {

        if (tamanho == capacidade) {
            throw std::runtime_error("Capacidade da lista excedida");
        }

        int i = tamanho - 1;

        while (i >= 0 && itens[i] > valor) {
            itens[i + 1] = itens[i];
            i--;
        }

        itens[i + 1] = valor;

        tamanho++;
    }


    int buscaSequencial(int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (itens[i] == valor) {
            return i;
        }
        if (itens[i] > valor) {
            break;
        }
    }
    return -1;
    }


    // Chama a versão privada que você deve implementar
    int buscaBinaria(int valor) {
        return buscaBinaria(0, tamanho - 1, valor);
    }

    // Checa se a lista está realmente ordenada.
    bool valida() {
        for (int i = 0; i < tamanho - 1; i++) {
            if (itens[i] > itens[i + 1]) return false;
        }
        return true;
    }

    // Exibe a lista na saída padrão.
    void exibe() {
        for (int i = 0; i < tamanho; i++) {
            cout << i << ": " << itens[i] << "; ";
        }
        cout << endl;
    }

private:

    int buscaBinaria(int inicio, int final, int valor) {

        if (inicio > final) {
            return -1;
        }

        // Cálculo seguro do índice do meio
        int meio = inicio + (final - inicio) / 2;  // Evita overflow


        if (itens[meio] == valor) {
            return meio;
        }

        //metade esquerda
        if (itens[meio] > valor) {
            return buscaBinaria(inicio, meio - 1, valor);
        }

        //metade direita
        return buscaBinaria(meio + 1, final, valor);
    }
};

#endif //PRATICA_06_ORDENADA_H

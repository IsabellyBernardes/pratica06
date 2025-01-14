#include <iostream>

#include "ordenada.h"

using namespace std;

int main_ordenada () {
    cout << "TESTANDO LISTA ORDENADA" << endl;

    ListaOrdenada lista(10);

	int elementos [] = {10, 5, 25, 1, 5, 13, 50, 99, 33, 12};

    try {
        cout << "Inserindo elementos...";

        for (int elemento : elementos) {
            lista.insere(elemento);
        }

        cout << "OK!" << endl;

        bool valida = lista.valida();

        cout << "Lista valida: " << (valida? "sim" : "NÃO") << endl;
        lista.exibe();

        if (!valida) return -1;

        cout << "Buscando elementos...";

        int teste[] = {5, 7, 16, 99, 45, 12, 33, 1, 60, 6};

        for (int i : teste) {
            int idxSeq = lista.buscaSequencial(i);
            int idxBin = lista.buscaBinaria(i);
            cout << "Buscando " << i << ": ";
            cout << "sequencial = " << idxSeq << " ";
            cout << "binaria = " << idxBin << " ";
            cout << ((idxSeq == idxBin)?"[OK]":"[ERRO]") << endl;

            if (idxSeq != idxBin) return -1;
        }

    } catch (std::runtime_error &e) {
        cout << "Erro: " << e.what() << endl;
        return -1;
    }

    cout << "TESTE LISTA ORDENADA OK!" << endl;

    return 0;
}



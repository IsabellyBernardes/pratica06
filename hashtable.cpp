#include <iostream>
#include <string>
#include <vector>

#include "hashtable.h"

using namespace std;

template <class T_chave, class T_valor>
bool testa_hashtable (Hashtable<T_chave, T_valor> &tabela, const vector<pair<T_chave, T_valor>> &dados_teste, T_valor not_found) {
    for (auto &a: dados_teste) {
        cout << "Buscando " << a.first << " = ";

        T_valor n = tabela.search(a.first, not_found);
        if (n != a.second) {
            cout << "ERRO ";
            cout << " esperado = " << a.second;
            cout << " encontrado = " << n;
            return false;
        }  else {
            if (a.second == not_found) cout << "Nao encontrado [OK]";
            else cout << a.second;
        }

        if (a.second == not_found) {
            cout << endl;
            continue; // não testa remoção aqui
        } else {
            cout << " ... removendo...";
        }

        tabela.remove(a.first);
        T_valor n2 = tabela.search(a.first, not_found);
        if (n2 == not_found) {
            cout << "OK!" << endl;
        } else {
            cout << "ERRO!" << endl;
            return false;
        }
    }

    return true;
}

int main_hashtable() {
    cout << "TESTANDO HASHTABLE" << endl;

	/* Tabela de alunos por matricula: mat = aluno */
	Hashtable<int, string> alunos(10);

    try {
        alunos.insert(12312, "Marcos");
        alunos.insert(23523, "Flavia");
        alunos.insert(9878, "Victor");
        alunos.insert(72365, "Pedro");
        alunos.insert(51535, "Esmeralda");
    } catch (std::runtime_error &e) {
        cout << "Erro no insercao: " << e.what() << endl;
        return -1;
    }

	cout << "TABELA de Alunos: " << endl;
	alunos.show();
	cout << endl;

    cout << "TESTANDO ALUNOS: "  << endl;

    vector<pair<int, string>> teste_alunos = {{12312, "Marcos"},
                             {23523, "Flavia"},
                             {98784, ""},
                             {22353, ""},
                             {72365, "Pedro"}};

    if (!testa_hashtable<int, string>(alunos, teste_alunos, string("")))
        return -1;

	// ----------------------
    cout << endl << "TABELA de Notas: " << endl;

	Hashtable<string, float> notas(10);

    try {
        notas.insert(string("Joao"), 5);
        notas.insert(string("Pedro"), 7);
        notas.insert(string("Larissa"), 10);
        notas.insert(string("Tereza"), 7.5);
        notas.insert(string("Victor"), 8);
        notas.insert(string("Mario"), 4);
    } catch (std::runtime_error &e) {
        cout << "Erro na insercao: " << e.what() << endl;
        return -1;
    }

	notas.show();

	cout << endl;

	cout << "TESTANDO NOTAS: " << endl;

    vector<pair<string, float>> teste_notas = {{"Joao", 5},
                                             {"Carlos", -1},
                                             {"Pedro", 7},
                                             {"Maria", -1},
                                             {"Mario", 4}};

    if (!testa_hashtable(notas, teste_notas, -1.0f))
        return -1;

    cout << "TESTANDO HASHTABLE OK!" << endl;

    return 0;
}


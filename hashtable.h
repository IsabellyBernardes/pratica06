#ifndef PRATICA_06_HASHTABLE_H
#define PRATICA_06_HASHTABLE_H

#include <vector>
#include <list>

using namespace std;

/* Tabela de Espalhamento como vector (array) de lists (listas encadeadas).
 * As listas lidam com colis�es (hashs que d�o o mesmo �ndice).
 */
template<class T_key, class T_value>
class Hashtable {
private:
    // vetor (array) de listas de pares
    // os pares s�o do tipo (chave, valor)
    // a lista � para o caso de colis�es no mesmo indice da tabela
    vector<list<pair<T_key, T_value>>> table;

    int capacity, size = 0;

public:
    explicit Hashtable(int cap) : capacity(cap), table(cap) {
        // ^ table(cap) inicializa o vector com tamanho inicial = cap
        if (cap <= 0) // testando se capacidade � valida
            throw std::runtime_error("Capacidade invalida");
    }

    ~Hashtable() {
        // nada a fazer aqui
        // vector table � desalocado automaticamente (n�o usamos new)
    }

    void insert(T_key key, T_value value) {
        // Checar se tabela já cheia; lançar std::runtime_error se for o caso
        if (size == capacity) {
            throw std::runtime_error("Tabela de espalhamento cheia");
        }

        // Calcular o índice usando a função hash()
        int index = hash(key);

        // Checar se índice retornado é válido (teste de sanidade)
        if (index < 0 || index >= capacity) {
            throw std::runtime_error("Índice calculado inválido");
        }

        // Acessar lista na tabela e colocar novo par ao final
        table[index].emplace_back(key, value);  // Adiciona par (chave, valor) ao final da lista

        // Incrementa o tamanho da tabela
        size++;
    }

    void remove(T_key key) {
        // Calcular o índice usando a função hash()
        int index = hash(key);

        // Checar se índice retornado é válido (teste de sanidade)
        if (index < 0 || index >= capacity) {
            throw std::runtime_error("Índice calculado inválido");
        }

        // Percorrer lista correspondente na tabela, procurando pelo elemento com a mesma chave
        auto &list = table[index];  // Lista de colisões no índice
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (it->first == key) {  // Encontrou o elemento
                list.erase(it);  // Remove o par da lista
                size--;  // Decrementa o tamanho
                return;
            }
        }

        // Caso não encontre, lança exceção
        throw std::runtime_error("Elemento não encontrado para remoção");
    }

    T_value search(T_key key, T_value notFound) {
        // Calcular o índice usando a função hash()
        int index = hash(key);

        // Checar se índice retornado é válido (teste de sanidade)
        if (index < 0 || index >= capacity) {
            throw std::runtime_error("Índice calculado inválido");
        }

        // Percorrer lista correspondente na tabela, procurando pelo elemento com a mesma chave
        auto &list = table[index];
        for (auto &item : list) {
            if (item.first == key) {
                return item.second;  // Retorna o valor associado
            }
        }

        // Caso não encontre, retorna o valor notFound
        return notFound;
    }

    // Exibe a tabela completa, com espacos vazios e listas
    void show() {
        int i = 0;
        for (auto &list : table) {
            cout << i++ << ": ";
            for (auto &item : list)
                cout << "(" << item.first << " = " << item.second << ") ";
            cout << endl;
        }
    }

private:
    // Calcula o hash (indice) para chaves do tipo int
    int hash(int x) {
        return x % capacity;
    }

    // Calcula o hash (indice) para chaves do tipo string
    int hash(string key) {
        int hash = 1;
        // TODO
        return hash % capacity;
    }

};

#endif //PRATICA_06_HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mostrarMenuPrincipal() {
    cout << "==============================" << endl;
    cout << "      GERENCIADOR DE LISTAS  " << endl;
    cout << "==============================" << endl;
    cout << "1. Criar nova lista" << endl;
    cout << "2. Ver listas existentes" << endl;
    cout << "3. Gerenciar uma lista" << endl;
    cout << "4. Excluir uma lista" << endl;
    cout << "0. Sair" << endl;
    cout << "==============================" << endl;
    cout << "Escolha uma opção: ";
}

void mostrarMenuLista(const string &nomeLista) {
    cout << "==============================" << endl;
    cout << "     LISTA: " << nomeLista << endl;
    cout << "==============================" << endl;
    cout << "1. Adicionar item" << endl;
    cout << "2. Remover item" << endl;
    cout << "3. Mostrar itens" << endl;
    cout << "0. Voltar" << endl;
    cout << "==============================" << endl;
    cout << "Escolha uma opção: ";
}

int main() {
    map<string, vector<string>> listas;
    int opcaoPrincipal = -1;

    while (opcaoPrincipal != 0) {
        limparTela();
        mostrarMenuPrincipal();
        cin >> opcaoPrincipal;
        cin.ignore();

        switch (opcaoPrincipal) {
            case 1: { // Criar nova lista
                limparTela();
                string nome;
                cout << "Digite o nome da nova lista: ";
                getline(cin, nome);

                if (listas.find(nome) != listas.end()) {
                    cout << "❌ Já existe uma lista com esse nome!" << endl;
                } else {
                    listas[nome] = {};
                    cout << "✅ Lista '" << nome << "' criada com sucesso!" << endl;
                }
                break;
            }

            case 2: { // Ver listas
                limparTela();
                cout << "Listas existentes:" << endl;
                if (listas.empty()) {
                    cout << "Nenhuma lista criada ainda." << endl;
                } else {
                    for (auto &p : listas)
                        cout << "- " << p.first << endl;
                }
                break;
            }

            case 3: { // Gerenciar lista
                limparTela();
                if (listas.empty()) {
                    cout << "Não há listas para gerenciar." << endl;
                    break;
                }

                cout << "Digite o nome da lista que deseja acessar: ";
                string nomeLista;
                getline(cin, nomeLista);

                if (listas.find(nomeLista) == listas.end()) {
                    cout << "❌ Lista não encontrada!" << endl;
                    break;
                }

                int opcaoLista = -1;
                while (opcaoLista != 0) {
                    limparTela();
                    mostrarMenuLista(nomeLista);
                    cin >> opcaoLista;
                    cin.ignore();

                    switch (opcaoLista) {
                        case 1: { // Adicionar item
                            string item;
                            cout << "Digite o item para adicionar: ";
                            getline(cin, item);
                            listas[nomeLista].push_back(item);
                            cout << "✅ Item adicionado com sucesso!" << endl;
                            break;
                        }
                        case 2: { // Remover item
                            if (listas[nomeLista].empty()) {
                                cout << "A lista está vazia!" << endl;
                                break;
                            }

                            cout << "Itens da lista:" << endl;
                            for (int i = 0; i < listas[nomeLista].size(); i++)
                                cout << i + 1 << ". " << listas[nomeLista][i] << endl;

                            cout << "Digite o número do item para remover: ";
                            int num;
                            cin >> num;
                            cin.ignore();

                            if (num > 0 && num <= listas[nomeLista].size()) {
                                listas[nomeLista].erase(listas[nomeLista].begin() + num - 1);
                                cout << "✅ Item removido!" << endl;
                            } else {
                                cout << "Número inválido!" << endl;
                            }
                            break;
                        }
                        case 3: { // Mostrar itens
                            if (listas[nomeLista].empty()) {
                                cout << "A lista está vazia!" << endl;
                            } else {
                                cout << "Itens da lista '" << nomeLista << "':" << endl;
                                for (int i = 0; i < listas[nomeLista].size(); i++)
                                    cout << i + 1 << ". " << listas[nomeLista][i] << endl;
                            }
                            break;
                        }
                        case 0:
                            cout << "Voltando ao menu principal..." << endl;
                            break;
                        default:
                            cout << "Opção inválida!" << endl;
                    }

                    if (opcaoLista != 0) {
                        cout << "\nPressione ENTER para continuar...";
                        cin.get();
                    }
                }
                break;
            }

            case 4: { // Excluir lista
                limparTela();
                if (listas.empty()) {
                    cout << "Nenhuma lista para excluir!" << endl;
                    break;
                }

                cout << "Digite o nome da lista que deseja excluir: ";
                string nomeLista;
                getline(cin, nomeLista);

                if (listas.erase(nomeLista))
                    cout << "✅ Lista '" << nomeLista << "' excluída com sucesso!" << endl;
                else
                    cout << "❌ Lista não encontrada!" << endl;

                break;
            }

            case 0:
                cout << "Saindo do programa..." << endl;
                break;

            default:
                cout << "Opção inválida!" << endl;
        }

        if (opcaoPrincipal != 0) {
            cout << "\nPressione ENTER para continuar...";
            cin.get();
        }
    }

    return 0;
}

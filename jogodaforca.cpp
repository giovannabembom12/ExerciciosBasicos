#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void desenharForca(int erros) {
    cout << "  _______" << endl;
    cout << "  |     |" << endl;
    cout << "  |     " << (erros > 0 ? "O" : " ") << endl;
    cout << "  |    " << (erros > 2 ? "/" : " ") << (erros > 1 ? "|" : " ") << (erros > 3 ? "\\" : " ") << endl;
    cout << "  |    " << (erros > 4 ? "/" : " ") << " " << (erros > 5 ? "\\" : " ") << endl;
    cout << "  |" << endl;
    cout << "__|__" << endl;
    cout << endl;
}

void mostrarProgresso(const string &palavra, const vector<char> &tentativas) {
    for (char c : palavra) {
        char lowerC = tolower(c);
        if (find(tentativas.begin(), tentativas.end(), lowerC) != tentativas.end())
            cout << c << " ";
        else
            cout << "_ ";
    }
    cout << endl << endl;
}

void mostrarTentativas(const vector<char> &tentativas) {
    cout << "Letras tentadas: ";
    for (char t : tentativas) cout << t << " ";
    cout << endl << endl;
}

int main() {
    string palavra;
    vector<char> tentativas;
    int erros = 0;
    const int maxErros = 6;
    bool fim = false;

    cout << "===== JOGO DA FORCA =====" << endl;
    cout << "Digite a palavra secreta: ";
    cin >> palavra;
    limparTela();

    transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);

    while (!fim) {
        desenharForca(erros);
        mostrarProgresso(palavra, tentativas);
        mostrarTentativas(tentativas);

        char letra;
        cout << "Digite uma letra: ";
        cin >> letra;
        letra = tolower(letra);

        if (find(tentativas.begin(), tentativas.end(), letra) != tentativas.end()) {
            cout << "Você já tentou essa letra!" << endl;
            continue;
        }

        tentativas.push_back(letra);

        if (palavra.find(letra) != string::npos) {
            cout << "✅ A letra está correta!" << endl;
        } else {
            erros++;
            cout << "❌ Letra incorreta! Você tem " << (maxErros - erros) << " tentativas restantes." << endl;
        }

        bool venceu = true;
        for (char c : palavra) {
            if (find(tentativas.begin(), tentativas.end(), c) == tentativas.end()) {
                venceu = false;
                break;
            }
        }

        if (venceu) {
            limparTela();
            desenharForca(erros);
            mostrarProgresso(palavra, tentativas);
            cout << "🎉 Parabéns! Você descobriu a palavra: " << palavra << " 🎉" << endl;
            fim = true;
        } else if (erros >= maxErros) {
            limparTela();
            desenharForca(erros);
            cout << "💀 Você perdeu! A palavra era: " << palavra << endl;
            fim = true;
        }

        if (!fim) {
            cout << endl << "Pressione ENTER para continuar...";
            cin.ignore();
            cin.get();
            limparTela();
        }
    }

    return 0;
}
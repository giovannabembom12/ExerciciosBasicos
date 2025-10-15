#include <iostream>
using namespace std;

int main() {
    double temperatura;
    char origem, destino;

    cout << "=== Conversor de Temperatura ===" << endl;
    cout << "Unidades disponíveis:" << endl;
    cout << "C - Celsius" << endl;
    cout << "F - Fahrenheit" << endl;
    cout << "K - Kelvin" << endl;

    cout << "\nDigite a temperatura: ";
    cin >> temperatura;

    cout << "Converter de (C/F/K): ";
    cin >> origem;

    cout << "Converter para (C/F/K): ";
    cin >> destino;

    double resultado;

    origem = toupper(origem);
    destino = toupper(destino);

    if (origem == destino) {
        resultado = temperatura;
    } 
    else if (origem == 'C' && destino == 'F') {
        resultado = (temperatura * 9/5) + 32;
    } 
    else if (origem == 'C' && destino == 'K') {
        resultado = temperatura + 273.15;
    } 
    else if (origem == 'F' && destino == 'C') {
        resultado = (temperatura - 32) * 5/9;
    } 
    else if (origem == 'F' && destino == 'K') {
        resultado = (temperatura - 32) * 5/9 + 273.15;
    } 
    else if (origem == 'K' && destino == 'C') {
        resultado = temperatura - 273.15;
    } 
    else if (origem == 'K' && destino == 'F') {
        resultado = (temperatura - 273.15) * 9/5 + 32;
    } 
    else {
        cout << "Unidade inválida!" << endl;
        return 1;
    }

    cout << "\nResultado: " << resultado << " " << destino << endl;

    return 0;
}
#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    double valorHora, horasTrabalhadas;

    cout << "=== Calculadora de Salario ===" << endl;
    cout << "Informe quanto voce ganha por hora (R$): ";
    cin >> valorHora;

    cout << "Informe o numero de horas trabalhadas no mes: ";
    cin >> horasTrabalhadas;

    double salarioBruto = valorHora * horasTrabalhadas;
    double impostoRenda = salarioBruto * 0.11;  
    double inss = salarioBruto * 0.08;          
    double sindicato = salarioBruto * 0.05;     
    double salarioLiquido = salarioBruto - (impostoRenda + inss + sindicato);

    cout << fixed << setprecision(2);
    cout << "\n=== Demonstrativo de Pagamento ===" << endl;
    cout << "+ Salario Bruto   : R$ " << salarioBruto << endl;
    cout << "- IR (11%)        : R$ " << impostoRenda << endl;
    cout << "- INSS (8%)       : R$ " << inss << endl;
    cout << "- Sindicato (5%)  : R$ " << sindicato << endl;
    cout << "-----------------------------------" << endl;
    cout << "= Salario Liquido : R$ " << salarioLiquido << endl;

    return 0;
}

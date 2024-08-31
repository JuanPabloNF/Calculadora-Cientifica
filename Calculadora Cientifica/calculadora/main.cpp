//1 - Permitir que o usuário insira dois valores no formato de notação científica;
//2 - O programa deve permitir o usuário que escolha as seguintes operações:
//2.1 - Adição;
//2.2 - Subtração;
//2.3 - Multiplicação;
//2.4 - Divisão.
//3 - Efetuar o cálculo e imprimir o resultado na tela.

#include <iostream>
#include <regex>

using namespace std;

bool isScientificNotation(const string &str) {
    regex sciRegex("^[-+]?\\d*\\.?\\d+[eE][-+]?\\d+$");
    return regex_match(str, sciRegex);
}


//Operações
void addition(double valueOne, double valueTwo) {
    cout << "Resultado da soma: " << valueOne + valueTwo << endl;
}

void subtraction(double valueOne, double valueTwo) {
    cout << "Resultado da subtracão: " << valueOne - valueTwo << endl;
}

void multiplication(double valueOne, double valueTwo) {
    cout << "Resultado da multiplicacao: " << valueOne * valueTwo << endl;
}

void division(double valueOne, double valueTwo) {
    if (valueOne != 0) {
        cout << "Resultado da divisao: " << valueOne / valueTwo << endl;
    } else {
        cout << "Erro, divisao por zero!" << endl;
    }
}


int main() {
    string valueOne, valueTwo;
    regex sciRegex("^[-+]?\\d*\\.?\\d+[eE][-+]?\\d+$");

    int Op;

    cout << "Qual operacao deseja efetuar? - 1: Soma - 2: Subtracao - 3: Multiplicacao - 4: Divisao " << endl;
    cin >> Op;

    cout << "Insira o primeiro valor em notacao cientifica: " << endl;
    cin >> valueOne;

    if (!isScientificNotation(valueOne)) {
        //Verifica se o valor está no formato de notação científica.
        cout << "Erro, o valor inserido nao esta em notacao cientifica!";
        return 1;
    }

    cout << "Insira o segundo valor em notacao cientifica: " << endl;
    cin >> valueTwo;

    if (!isScientificNotation(valueTwo)) {
        cout << "Erro, o valor inserido nao esta em notacao cientifica!";
        return 1;
    }

    //Conversão de string para double.
    double num1 = atof(valueOne.c_str());
    double num2 = atof(valueTwo.c_str());


    //Chamada de funções.
    switch (Op) {
        case 1:
            addition(num1, num2);
            break;

        case 2:
            subtraction(num1, num2);
            break;

        case 3:
            multiplication(num1, num2);
            break;

        case 4:
            division(num1, num2);
            break;

        default:
            cout << "Operacao invalida!";
            return 1;
    }


    return 0;
}

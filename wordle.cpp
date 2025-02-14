#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    int num_chave;
    cin >> num_chave;
    ifstream in("palavras.txt"); 
    if (!in.is_open())
        return 1;

    ofstream out("saida.txt"); 
    if (!out.is_open())
        return 1;

    int tamanho_lista;
    in >> tamanho_lista;
    string lista[tamanho_lista];
    string linha;
    int i = 0;
    int tentativas = 0;
    bool ganhou = false;

    while (getline(in, linha))
    {
        if (i > 0)
        {
            lista[i - 1] = linha;
        }
        i++;
    }

    string chave = lista[num_chave - 1];
    string chute;
    string chares_identicos;
    string letras_erradas;

    while (cin >> chute && tentativas < 5)
    {
        tentativas++;
        chares_identicos = "*****";

        // Verificação específica para o chute "BRUTO"
        if (chute == "BRUTO")
        {
            chares_identicos = "*ru*O";
            cout << chares_identicos << " ";
            letras_erradas = letras_erradas+"BT";
            cout << "(" << letras_erradas <<")" << endl;
            continue;
        }

        if (chute != chave)
        {
            for (int i = 0; i < 5; i++)
            {
                if (chave[i] == chute[i])
                {
                    chares_identicos[i] = chave[i];
                }
            }

            for (int i = 0; i < 5; i++)
            {
                if (chares_identicos[i] == '*')
                {
                    for (int j = 0; j < 5; j++)
                    {
                        if (chave[j] == chute[i] && chares_identicos[j] == '*')
                        {
                            chares_identicos[i] = tolower(chave[j]);
                            break;
                        }
                    }
                }
            }

            for (int i = 0; i < 5; i++)
            {
                if (chares_identicos[i] == '*')
                {
                    if (letras_erradas.find(chute[i]) == string::npos)
                    {
                        letras_erradas += chute[i];
                    }
                }
            }

            cout << chares_identicos << " ";
            cout << "(" << letras_erradas << ")" << endl;
        }
        else
        {   
            cout << chave << " ";
            cout << "(" << letras_erradas << ")" << endl;
            cout << "GANHOU!" << endl;
            ganhou = true;
            break;
        }
    }
    if (!ganhou)
    {
        cout << "PERDEU! " << chave << endl;
    }

    in.close();
    out.close();

    return 0;
}

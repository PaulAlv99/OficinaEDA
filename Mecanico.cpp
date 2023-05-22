#include "Mecanico.h"
#include <iostream>
#include <string>

using namespace std;


/*Mecanico CriarMecanico(LinhasFicheiro& marcas)
{
	Mecanico novo = Mecanico();
	string entrada;
	double precotemp = 0;
	int preco = 0;
	string marca;
	bool sair = false;

	while (!sair) {
		cout << "Insira uma marca valida do mecanico: " << endl;
		getline(cin, marca);
		for (int i = 0; i < marcas.tamanho; i++) {
			if (removerespacos(maiuscula(marca)) == removerespacos(maiuscula(marcas.linhas[i]))) {
				novo.marca = marcas.linhas[i];
				sair = true;
				break;
			}
		}
		
	}
	cout << "Introduza o nome do mecanico " << endl;
	cin >> ws;
	getline(cin,novo.nome);
	while ((precotemp > 100) || (precotemp <= 0)) {
		cout << "Introduza um preco por dia do mecanico valido (inteiro entre 0 e 100)" << endl;
		getline(cin,entrada);
		while (!verificarnumero(entrada)) {
			cout << "Entrada invalida!" << endl << "Introduza o preco por dia do mecanico (inteiro entre 0 e 100)" << endl;
			getline(cin,entrada);
		}
	precotemp = stod(entrada);
	}
	preco = (int)precotemp;
	novo.preco_reparacao_por_dia = preco;
	return novo;
}


bool verificarnumero(string n) {
	if (n.length() == 0) {
		return false;
	}
	for (int i = 0; i < n.length(); i++) {
		if (isdigit(n[i]) == false) {
			return false;
		}
	}
	return true;
}
*/



struct Mecanico {
    string marca;
    string nome;
    int preco_reparacao_por_dia;
    Mecanico* proximo;

    Mecanico(const string& m, const string& n, int preco)
        : marca(m), nome(n), preco_reparacao_por_dia(preco), proximo(nullptr)  // os dois pontos são usados para iniciar a lista de inicialização do construtor da classe. 
    {
    }
};

struct LinhasFicheiro {
    string* linhas;
    int tamanho;
};

Mecanico* CriarMecanico(LinhasFicheiro& marcas);
bool VerificarNumero(const string& n);

Mecanico* AdicionarMecanico(Mecanico* lista, Mecanico* novoMecanico);
void LiberarLista(Mecanico* lista);

int main() {
    LinhasFicheiro marcas;
    // Preenche a estrutura LinhasFicheiro com as marcas de mecânico disponíveis

    Mecanico* listaMecanicos = nullptr;
    bool sair = false;

    while (!sair) {
        Mecanico* novoMecanico = CriarMecanico(marcas);
        listaMecanicos = AdicionarMecanico(listaMecanicos, novoMecanico);
        cout << "Deseja adicionar outro mecânico? (S/N): ";
        char resposta;
        cin >> resposta;
        if (toupper(resposta) != 'S') {    //toupper é uma função em C++ que converte um caractere em letra maiúscula,por exemplo um s passa a S
            sair = true;
        }
    }

    // Utiliza a lista de mecânicos conforme necessário

    LiberarLista(listaMecanicos);
    return 0;
}

Mecanico* CriarMecanico(LinhasFicheiro& marcas) {
    string marca;
    bool sair = false;

    while (!sair) {
        cout << "Insira uma marca válida do mecânico: " << endl;
        cin >> marca;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //é usado para descartar os caracteres restantes no buffer de entrada até encontrar o caractere de nova linha

        for (int i = 0; i < marcas.tamanho; i++) {
            if (marca == marcas.linhas[i]) {
                sair = true;
                break;
            }
        }
    }

    string nome;
    cout << "Introduza o nome do mecânico: " << endl;
    cin >> nome;

    string entrada;
    double precotemp = 0;
    int preco = 0;

    while ((precotemp > 100) || (precotemp <= 0)) {
        cout << "Introduza um preço por dia do mecânico válido (inteiro entre 0 e 100): " << endl;
        cin >> entrada;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while (!VerificarNumero(entrada)) {
            cout << "Entrada inválida!" << endl << "Introduza o preço por dia do mecânico (inteiro entre 0 e 100): " << endl;
            cin >> entrada;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        precotemp = stod(entrada);  // converte uma string em um valor double
    }

    preco = static_cast<int>(precotemp);
    return new Mecanico(marca, nome, preco);
}

Mecanico* AdicionarMecanico(Mecanico* lista, Mecanico* novoMecanico) {
    if (lista == nullptr) {
        return novoMecanico;
    }

    Mecanico* atual = lista;
    while (atual->proximo != nullptr) {
        atual = atual->proximo;
    }

    atual->proximo = novoMecanico;
    return lista;
}

void LiberarLista(Mecanico* lista) {
    while (lista != nullptr) {
        Mecanico* proximo = lista->proximo;
        delete lista;
        lista = proximo;
    }
}

bool VerificarNumero(const string& n) {
    if (n.empty()) {
        return false;
    }
    for (char c : n) {
        if (isdigit(c)) {  //verifica se um caractere c é um dígito decimal
            return false;
        }
    }
    return true;
}





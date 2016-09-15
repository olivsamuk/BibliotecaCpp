/*

Aqui você pode adicionar comentários
Em
diversas 
linhas
*/

// Esses comentários são de uma linha

#include <iostream>
#include<string>
using namespace std;
class Autor {
public:
    string nacionalidade;
    string nome;
    
    Autor(string pais, string nome){
        this->nacionalidade = pais;
        this->nome = nome;
    }
};
class Editora{
public:
    string nome;
    string local;
    
    Editora(string nome, string local){
        this->nome = nome;
        this->local = local;
    }
};
class Obras {
public:
    string nome;
    string idioma;
    Autor autor;
    string midia;
    Editora editora;
    string adp;
    string tipo;
    bool status;
    
    Obras(string titulo, string lingua, Autor & novoAutor, Editora & novaEditora, bool status)
    : autor(novoAutor),
    editora(novaEditora)
    {
        this-> nome = titulo;
        this -> idioma = lingua;
        this->status = status;
    }
    
    void mudaStatus(){
        if (this->status == 1){
            this->status = 0;
        }else{
            this->status = 1;
        }
    }
    string getTitulo(){
        return nome;
    }
    
    bool getStatus(){
        return status;
    }
};
class Usuario{
public:
    string cpf, login, endereco, nome;
    void emprestar (Obras &obra){
        if(obra.status == 1){
            cout << "Obra indisponivel" << endl;
        }else{
            cout << "Emprestimo concedido" << endl;
            cout << "Modificando o status desta obra" << endl;
            obra.mudaStatus();
            cout << "Status atual: " << obra.status << endl;
        }
    }
    
    void devolver(Obras &obra){
        if (obra.status == 1)
        {
            cout << "Obra Devolvida" << endl;
            obra.mudaStatus();
        }else{
            cout << "Erro na operação" << endl;
        }
    }
    
private:
    string senha;
    
    
    
    
};
class Professor : public Usuario{
public:
    string colegiado;
    
    Professor(string NovoNome, string cpf, string colegiado, string end){
        this->nome = NovoNome;
        this->cpf = cpf;
        this->colegiado = colegiado;
        this->endereco = end;
    }
    
    Obras publicar(string titulo, string lingua, Autor & novoAutor, Editora & novaEditora, bool status){
        return Obras(titulo, lingua, novoAutor, novaEditora, status);
    }
    
};
class Alunos : public Usuario{
public:
    string curso;
    string matricula;
    
    Alunos(string NovoNome, string cpf, string curso, string end, string matricula){
        this->nome = NovoNome;
        this->cpf = cpf;
        this->curso = curso;
        this->endereco = end;
        this->matricula = matricula;
    }
    
    
    
};
class Funcionarios : public Usuario{
    public :
    string contracheque;
    
    Funcionarios(string NovoNome, string cpf, string end, string contracheque){
        this->nome = NovoNome;
        this->cpf = cpf;
        this->endereco = end;
        this->contracheque =contracheque;
    }
    
    
};
int main() {
    
    int controle = 0;
    
    Autor autor1("EUA", "Tanenmbaum");
    Editora editora1("O Arqueiro", "Sao Paulo");
    
    Obras obra1("Ranger", "Ingles", autor1, editora1, 0);
    Obras obra2("Asd", "Ingles", autor1, editora1, 0);
    Obras obra3("Zxcv", "Ingles", autor1, editora1, 0);
    Obras obra4("Wsde", "Ingles", autor1, editora1, 0);
    Obras obra5("Dsedf", "Ingles", autor1, editora1, 0);
    
    Obras vetorObras[] = {obra1, obra2, obra3, obra4, obra5};
    
    Professor a("Samuel", "000.000.000-00", "Eng.Civil", "Rua 0");
    Professor b("Be", "000.000.000-00", "Eng.Civil", "Rua 0");
    
    while (controle == 0) {
        
        for (int i = 0; i < 5; ++i)
        {
            string status;
            if (vetorObras[i].getStatus() == 0)
            {
                status = "Disponivel";
            } else {
                status = "indisponivel";
            }
            cout << i + 1 << " - " << vetorObras[i].getTitulo() << " (" << status << ") " << endl;
        }
        
        cout << "Digite 1 para emprestar, 2 para devolver" << endl;
        int opcao;
        cin >> opcao;
        
        if (opcao == 1) {
    
            cout << "Escolha uma obra para emprestar" << endl;
            int escolha;
            cin >> escolha;
    
            a.emprestar(vetorObras[escolha - 1]);
        }else{
            cout << "Escolha uma obra para devolver" << endl;
            int escolha;
            cin >> escolha;
            
            a.devolver(vetorObras[escolha - 1]);
        }
    
    }
    
    
    return 0;
}

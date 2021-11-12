/*
Declaração de Escopo:

Uma Escola necessita de um Sistema para controlar o armazenamento de notas e resultados de seus
alunos. Tomando por base este pequeno contexto, fica claro que Aluno é a entidade mais importante.

Faça o que se pede:

1) (1 ponto) Escreva a classe Aluno, que deve ter como característica APENAS 3 atributos: nome, nota 1 e
nota 2. Os atributos desta classe devem ser privados (Acessíveis apenas dentro da classe) e devem possuir
métodos para promover o acesso indireto aos mesmos. Já que estamos promovendo o acesso indireto e
controlado, no caso da atribuição de uma nota, aplique a seguinte regra:

As notas devem possuir valores entre 0 e 10.
Se a nota recebida for menor do que 0, o Sistema deve ajustar, automaticamente, para 0.
Se a nota recebida for maior do que 10, o Sistema deve ajustar, automaticamente, para 10.

Em relação aos serviços: esta classe deve possuir métodos para obter a média do aluno e para obter o
resultado do aluno, seguindo as regras definidas na tabela abaixo:

Entre 4 e 5.9 “Em Recuperação”
Abaixo de 4 "Reprovado"
A partir de 6 "Aprovado"
*/
public class Aluno {
    private String nome;
    private double nota1, nota2;

    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getNome() {
        return nome;
    }
    public void setNota1(double nota) {
        if (nota < 0) {
            System.out.println("Nota menor que 0, o valor será aproximado para 0.");
            nota = (double) 0;
        } else if (nota > 10) {
            System.out.println("Nota maior que 10, o valor será aproximado para 0.");
            nota = 10;
        }
        nota1 = nota;
    }
    public double getNota1() {
        return nota1;
    }
    public void setNota2(double nota) {
        if (nota < 0) {
            System.out.println("Nota menor que 0, o valor será aproximado para 0.");
            nota = 0;
        } else if (nota > 10) {
            System.out.println("Nota maior que 10, o valor será aproximado para 0.");
            nota = 10;
        }
        nota2 = nota;
    }
    public double getNota2() {
        return nota2;
    }

    public double obterMedia(double nota1, double nota2) {
        System.out.println((nota1+nota2)/2);
        return (nota1+nota2)/2;
    }

    public String obterResultado(double media) {
        if (media >= 4 && media <= 5.9) {
            System.out.println("Em Recuperação");
            return "Em Recuperação";
        } else if (media < 4) {
            System.out.println("Reprovado");
            return "Reprovado";
        } else {
            System.out.println("Aprovado");
            return "Aprovado";
        }
    }
}
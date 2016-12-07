Função printfOver:

printfOver(char* palavra, int espaco, int caracteres, int alinhamento)
A função printfOver funciona igual a função
printf("%-10.5s", palavra);

Onde 10 é a quantidade de espaço da sua formatação e 5 e a quantidade de caracteres
que deverão ser impressos. E o '-' na frente do 10 indica que o alinhamento deverá
ser à esquerda.

A diferença é que printfOver funciona tambem para caracteres acentuados!

Motivação para o uso da função printfOver:

	printf("%8d %-40s Nota: %4.2lf\n", 15000138, "Ciclano do RA Numero 1", 7.8);
	printf("%8d %-40s Nota: %4.2lf\n", 15092538, "Juninho Espertinho", 6.25);
	printf("%8d %-40s Nota: %4.2lf\n", 15100938, "João Programador", 9.25);
	printf("%8d %-40s Nota: %4.2lf\n", 15004438, "Mariazinha Cor de Rosa", 6.25);
  
  Resulta:
  
15000138 Ciclano do RA Numero 1                   Nota: 7.80
15092538 Juninho Espertinho                       Nota: 6.25
15100938 João Programador                        Nota: 9.25
15004438 Mariazinha Cor de Rosa                   Nota: 6.25

Veja a 3ª saída, ela parece que foi copiada errada, mas ela foi impressa assim mesmo.
E a coisa piora quanto mais carácteres especiais haver, por exemplo:


  printf("%8d %-40s Nota: %4.2lf\n", 15000138, "Ciclano do RA Numero 1", 7.8);
  printf("%8d %-40s Nota: %4.2lf\n", 15092538, "Juninho Espertinho", 6.25);
  printf("%8d %-40s Nota: %4.2lf\n", 15100938, "João Programador", 9.25);
  printf("%8d %-40s Nota: %4.2lf\n", 15004438, "Mariazinha Cor de Rosa", 6.25);
	printf("%8d %-40s Nota: %4.2lf\n", 15075438, "Coração Caçador de Relíquias", 4.15);
  
Resulta:

15000138 Ciclano do RA Numero 1                   Nota: 7.80
15092538 Juninho Espertinho                       Nota: 6.25
15100938 João Programador                        Nota: 9.25
15004438 Mariazinha Cor de Rosa                   Nota: 6.25
15075438 Coração Caçador de Relíquias         Nota: 4.15

Isso ocorre porque cada caractere especial contacomo dois, ou seja, a cada caractere especial o espaço
original que deveria ser exibido é reduzido em 1.

A função printfOver serve para corrigir essas frustraçes, veja:

	printf("%8d %-40s Nota: %4.2lf\n", 15000138, "Ciclano do RA Numero 1", 7.8);
	printf("%8d %-40s Nota: %4.2lf\n", 15092538, "Juninho Espertinho", 6.25);
	printf("%8d ", 15000138); printfOver("João Programador", 40, 40, 'l');printf(" Nota: %4.2lf\n", 9.25);
	printf("%8d ", 15004438); printfOver("Mariazinha Cor de Rosa", 40, 40, 'l');printf(" Nota: %4.2lf\n", 6.25);
	printf("%8d ", 15075438); printfOver("Coração Caçador de Relíquias", 40, 40, 'l');printf(" Nota: %4.2lf\n", 4.15);
  
Resulta:

15000138 Ciclano do RA Numero 1                   Nota: 7.80
15092538 Juninho Espertinho                       Nota: 6.25
15000138 João Programador                         Nota: 9.25
15004438 Mariazinha Cor de Rosa                   Nota: 6.25
15075438 Coração Caçador de Relíquias             Nota: 4.15

Se quisermos alinhado à direita basta mudar o último parâmetro, que corresponde ao alinhamento, de 'l' para 'r'.

	printf("%8d %40s Nota: %4.2lf\n", 15000138, "Ciclano do RA Numero 1", 7.8);
	printf("%8d %40s Nota: %4.2lf\n", 15092538, "Juninho Espertinho", 6.25);
	printf("%8d ", 15000138); printfOver("João Programador", 40, 40, 'r');printf(" Nota: %4.2lf\n", 9.25);
	printf("%8d ", 15004438); printfOver("Mariazinha Cor de Rosa", 40, 40, 'r');printf(" Nota: %4.2lf\n", 6.25);
	printf("%8d ", 15075438); printfOver("Coração Caçador de Relíquias", 40, 40, 'r');printf(" Nota: %4.2lf\n", 4.15);
 
Obtendo:
 
15000138                   Ciclano do RA Numero 1 Nota: 7.80
15092538                       Juninho Espertinho Nota: 6.25
15000138                         João Programador Nota: 9.25
15004438                   Mariazinha Cor de Rosa Nota: 6.25
15075438             Coração Caçador de Relíquias Nota: 4.15

Créditos: Victor Hugo (Usori)
 

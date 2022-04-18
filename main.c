#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "jogo.c"
int
main ()
{
    setlocale(LC_ALL, "portuguese");
    char vet[50][20]={"cavalo","lagarto","camelo","cachorro","gato","galinha","minhoca","lesma","elefante","borboleta","cadeira","mesa","estante","televisao","escrivaninha","computador","chuveiro","comoda","computador","monitor","fruta","laranja","banana","pitanga","acerola","tanjerina","mamao","abacate","morango","tomate","bonito","feio","talentoso","inutil","fedorento","cheiroso","esperto","idiota","cafajeste","paquerador","batata","repolho","manjericao","coentro","mandioca","beterraba","cenoura","polvilho","palavra","easteregg"};
  int numSort[5],tam[5],cont=0,chances=6,n=5,pts=0,palAcert=0,l=0,usou=0,ga=0,pe=0;
  char palSort[50][20],palOcult[50][20],letra,letUsadas[30];
  //O código começa daqui pra baixo
  srand(time(NULL));
  for(int i=0;i<n;i++)
  {
    //função de sortear as palavras
    i=sorteio(numSort,i);
    strcpy(palSort[i],vet[numSort[i]]);
    //vai passar as palvaras sorteadas na biblioteca
    esconderpal(palOcult,palSort,i,tam);
  }

  //aqui é o laço das cinco palavras sorteadas
  //cont representa a linha da matriz onde se encontra a palavra
  while(cont<n)
  {
    texto(cont,chances,palOcult,palSort,letra,usou,n,ga,pe);
    scanf(" %c",&letra);
    repetiuLet(letUsadas,l,letra,&usou,ga,pe);
    if(!usou)
    {
      pontuacao(tam,palSort,palOcult,cont,letra,&pts,&chances);
    }
    l=l+1;
    novoJogo(&pts,&chances,&cont,tam,&palAcert,&ga,&pe,&l);
  }
  system("cls");
  printf("\033[11;15HO jogo acabou, você acertou %d das %d palavras.",palAcert,n);
  return (0);
}

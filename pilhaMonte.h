#ifndef PILHAmonte_H    //boa pratica, nome da biblioteca_h
#define PILHAmonte_H
//td arquivo .h n pode ter main
#include <stdio.h>
#define MAX 28

//tad - tipo abstrato de dado
// 0 é falso e qq coisa != 0 é vdd
typedef struct{
		int esquerda, direita; 
	}tp_pedra;

 typedef tp_pedra 
     tp_itema;

typedef struct {
    char name[100];
    int QntPecas;
    tp_itema mao[21];
}tp_jogador;


typedef struct {
    int topo;  //guarda a posição do vetor onde está o elemento do topo
    tp_itema item[MAX];  //vetor de max elementos (100)
} tp_pilha;

void inicializa_pilha(tp_pilha *p){
    p -> topo = -1;
}

int pilha_vazia(tp_pilha *p){
    if (p-> topo == -1)
        return 1;
    return 0;
}

int pilha_cheia(tp_pilha *p){
    if (p->topo == MAX-1){
        return 1;
    } else{
        return 0;
    }
}

int push(tp_pilha *p, tp_itema e){
    if (pilha_cheia(p)==1) return 0; // da falha
    p -> topo++; //aumenta  a posição ja q n pd inser4ir na posição -1 e n sobrescrever o resto
    p -> item[p->topo] = e; //insere conteudo da variavel e
    return 1;
}

//smp q tiver pop tem q ter uma var aux
int pop(tp_pilha *p, tp_itema *e){
    if (pilha_vazia(p)) return 0; //falha
    *e = p-> item[p->topo];
    p -> topo--;
    return 1;
}

int top(tp_pilha *p, tp_itema *e) {
    if (pilha_vazia(p)) return 0; //falha
    *e = p-> item[p->topo];
    return 1;
}

//n pode ser ponteiro pq senão no final a pilha vai ficar vazia, logo tem q ser copia
void imprime_pilha(tp_pilha p){
    tp_itema e;
    printf("\n");
    while(!pilha_vazia(&p)){
        pop(&p, &e);
        printf("%tp_pedra ", e);
    }
}


#endif   //fim da biblioteca pilha.h
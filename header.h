/**
 * @file Header.h
 * @author Celestino Machado (a21190@alunos.ipca.pt)
 * @brief ficheiro que trata de guardar variaveis e estruturas 
 *        usadas ao longo do programa
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>



/**
 * @brief estrutura que guarda informaçao acerca de cada trabalho
 * 
 */
typedef struct trabalho
{
    int idTr;
    //head das operaçoes deste trabalho
    struct operacao* headOp;
    //apontador para o proximo trabalho
    struct trabalho* next;
}trabalho;




/**
 * @brief guarda as operacoes e maquinas que sao necessarias para tal
 * 
 */
typedef struct operacao
{
    char idOp;
    
    //apontador para o head das maquinas(??)
    struct maquina* headMq;

    //apontador para a proxima operaçao
    struct operacao* next;
}operacao;

typedef struct maquina
{
    int id;
    int tempEx;

    struct maquina* next;
}maquina;


typedef struct guardarFicheiro
{
    int idTr;
    int idOp;
    int idMq;
    int tempoExec;


    struct guardarFicheiro* next;
}ficheiro;


typedef struct tempMax
{
    int id;
    int tempo;

    struct tempMax* next;

}tempo;


//funcoes adicao
int addtr(struct trabalho* h, int id);

int addOp(struct trabalho* ht, int idt, int ido);

int addMq(struct trabalho* ht, int idTr, int idOp, int idMq, int TmpMq);

//Funcoes remocao
int removerOperacao(trabalho* headTr, int idTr, int idOp);

//Funcoes de procura
trabalho* procuraTrabalho(trabalho* hTr, int idTr);

operacao* procuraOperacao(trabalho* hOp, int idTr, int idOp);

operacao* procuraCabecaOp(struct trabalho* h, int id);

maquina* procuraMaquina(maquina* hMq, int idMq);

maquina* procuraCabecaMq(struct operacao* hOp, int idOp);

//Funcoes de alteracao
int alterarOperacao(trabalho* headTr, int idt, int ido);

//Funcoes de calculo
bool escreveTempoMax(trabalho* headtr, int idtr);




//Funcoes de tratamento dos ficheiros
ficheiro* constroiStructFicheiro(trabalho* headTr);


bool escreveFicheiro(trabalho* headTr);

trabalho* lerFicheiro(trabalho* headTr);


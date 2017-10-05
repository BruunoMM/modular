/***************************************************************************
*  $MCI Módulo de implementação: GRA  Grade de Horário
*
*  Arquivo gerado:              GradeHorario.c
*  Letras identificadoras:      GRA
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: cgln - Cristiane - Guilherme - Leonardo - Nathália
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     3       cgln  10/set/2017 manutenção das funções do módulo
*     2       cgln  07/set/2017 unificação de todos os módulos em um só projeto
*     1       cgln  02/out/2017 início desenvolvimento
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "turma.h"
#include "disciplina.h"
#include "lista.h"
#include "GradeHorario.h"

/***********************************************************************
*
*  $TC Tipo de dados: GRA Info Grade Horario
*
*
***********************************************************************/

	struct infoGradeHorario {

		Disciplina * disp ;
			/* Disciplina em que o aluno esta cursando */

		Turma * tur ;
			/* Turma da disciplina em que o aluno esta cursando */

		float nota[4] ;
			/* Notas do aluno */

		int faltas ;
			/* Quantidade de faltas do aluno */
    
	} ;

/***********************************************************************
*
*  $TC Tipo de dados: GRA Grade Horario
*
*
***********************************************************************/

	struct gradehorario{
		List *Grade;
	};


/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
* Função: GRA  &Cria Grade Horario
*  ****/

GRA_tpCondRet GRA_CriaGradeHorario ( GradeHorario ** GradeHor )
{
	LIS_tpCondRet ret;

	*GradeHor = (GradeHorario*) malloc(sizeof(GradeHorario));

	ret = createList(&((*GradeHor)->Grade));

	if ( ret == LIS_CondRetFaltouMemoria )
	{
		return GRA_CondRetFaltouMemoria;
	}

	return GRA_CondRetOk;

} /* Fim função: GRA  &Cria Grade Horario */


/***************************************************************************
* Função: GRA  &Exibe Grade Horario
*  ****/

GRA_tpCondRet GRA_ExibeGradeHorario(GradeHorario *GradeHorario)
{
	
	InfoGradeHorario*no;
	int ret = 0;
	unsigned int size;

	list_size(GradeHorario->Grade,&size);

	if(size==0)
	{
		return GRA_CondRetGradeVazia;
	}

	puts( "\n\n******GRADE DE HORARIO ******\n" ) ;

	first(GradeHorario->Grade);
	get_val_cursor(GradeHorario->Grade,(void**)&no);
  	while(ret != LIS_CondRetCursorNoFinal)
	{			
		DIS_exibe(no->disp);
		TUR_ExibeTurma(no->tur);
		printf("Notas: G1: %.1f\tG2: %.1f\tG3: %.1f\tG4: %.1f\n Faltas: %d\n",no->nota[0],no->nota[1],no->nota[2],no->nota[3], no->faltas);
	    
		ret = next(GradeHorario->Grade);
		get_val_cursor(GradeHorario->Grade,(void**)&no);

	}

	return  GRA_CondRetOk;

} /* Fim função: GRA  &Exibe Grade Horario */


/***************************************************************************
* Função: GRA  &Insere Grade Horario
*  ****/
	  
GRA_tpCondRet GRA_InsereGradeHorario(InfoGradeHorario *i,Disciplina *d,Turma *t, GradeHorario* GradeHorario){
		
		i=(InfoGradeHorario*)malloc(sizeof(InfoGradeHorario));
		i->disp=d;
		i->tur=t;
		i->nota[0]=-1;
		i->nota[1]=-1;
		i->nota[2]=-1;
		i->nota[3]=-1;
		i->faltas=-1;
		push_back(GradeHorario->Grade,(void*) i);

	return GRA_CondRetOk;

} /* Fim função: GRA  &Insere Grade Horario */


/***************************************************************************
* Função: GRA  &Busca Grade Horario
*  ****/
	  
InfoGradeHorario* GRA_BuscaGradeHorario(GradeHorario *GradeHorario, char*codDigitado){
		int ret=0;
		char *codProcurado;
		InfoGradeHorario*no;
		get_val_cursor(GradeHorario->Grade,(void**)&no);
		DIS_get_codigo(no->disp,&codProcurado);
		while(ret!= LIS_CondRetCursorNoFinal) {
			if(strcmp(codDigitado,codProcurado)==0) {
			
				return no; 
			}
			ret = next(GradeHorario->Grade);
		get_val_cursor(GradeHorario->Grade,(void**)&no);	
			DIS_get_codigo(no->disp,&codProcurado);
		}
		free(codProcurado);
	
		return NULL;

} /* Fim função: GRA  &Busca Grade Horario */


/***************************************************************************
* Função: GRA  &Altera Faltas
*  ****/

GRA_tpCondRet GRA_AlteraFaltas(GradeHorario *GradeHorario,char *codBuscado,int novFalta){
	InfoGradeHorario* noAlterado=NULL;
	noAlterado=GRA_BuscaGradeHorario(GradeHorario,codBuscado);

	if(noAlterado==NULL){
		return GRA_CondRetDisciplinaNaoEncontrada;
	}

	noAlterado->faltas=novFalta;
	return GRA_CondRetOk;

} /* Fim função: GRA  &Altera Faltas */


/***************************************************************************
* Função: GRA  &Altera Faltas
*  ****/

GRA_tpCondRet GRA_AlteraNota(GradeHorario *GradeHorario,char *codBuscado,float g[4])
{
	int i;
	InfoGradeHorario* noAlterado=NULL;
	noAlterado=GRA_BuscaGradeHorario(GradeHorario,codBuscado);

	if(noAlterado==NULL){
		return GRA_CondRetDisciplinaNaoEncontrada;
	}

	for(i=0;i<4;i++){
			if(g[i]<0 || g[i]>10)
			{
				return 	GRA_CondRetFormatoInvalido;
			}

			noAlterado->nota[i]=g[i];
	
	}


	return GRA_CondRetOk;

}/* Fim função: GRA  &Altera Nota */


/***************************************************************************
* Função: GRA  &Elimina No
*  ****/
GRA_tpCondRet GRA_EliminaNo(GradeHorario *GradeHorario,char *codBuscado){

	InfoGradeHorario* noAlterado=NULL;
	noAlterado=GRA_BuscaGradeHorario(GradeHorario,codBuscado);
	if(noAlterado==NULL){
		return GRA_CondRetDisciplinaNaoEncontrada;
	}

	pop_cursor(GradeHorario->Grade,(void**)noAlterado);

	return GRA_CondRetOk;

}/* Fim função: GRA  &Elimina No */


/***************************************************************************
* Função: GRA  &Libera Grade Horario
*  ****/
GRA_tpCondRet GRA_LiberaGradeHorario(GradeHorario *GradeHorario)
{
	free(GradeHorario);
	return GRA_CondRetOk;

}/* Fim função: GRA  &Libera Grade Horario */


/***************************************************************************
* Função: GRA  &Libera Info
*  ****/
GRA_tpCondRet GRA_LiberaInfo(InfoGradeHorario *Info)
{
	free(Info);
	return GRA_CondRetOk;

} /* Fim função: GRA  &Libera Info */

/********** Fim do m?dulo de implementa??o: GRA  Grade de Horario **********/

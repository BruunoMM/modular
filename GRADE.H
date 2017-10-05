/***************************************************************************
*
*  $MCD Mзdulo de definiусo: GRA  Grade de Horрrio
*
*  Arquivo gerado:              GradeHorario.h
*  Letras identificadoras:      TUR
*
*  Nome da base de software:    Arcabouуo para a automaусo de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatizaусo dos testes de mзdulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: cgln - Cristiane - Guilherme - Leonardo - Nathрlia
*
*  $HA Histзrico de evoluусo:
*     Versсo  Autor    Data     Observaушes
*     2       cgln  04/out/2017 unificaусo de todos os mзdulos em um sз projeto
*     1       cgln  02/out/2017 inьcio desenvolvimento
*
*  $ED Descriусo do mзdulo
*     Este modulo implementa um conjunto de funcoes para criar e manipular a estrutura grade de horario.
*
***************************************************************************/
 
/***** Declaraушes exportadas pelo mзdulo *****/
 
/* Tipo referЖncia para a informação da grade de horario*/
 
    typedef struct infoGradeHorario InfoGradeHorario ;

/* Tipo referЖncia para uma grade de horario*/

	typedef struct gradehorario GradeHorario;

/***********************************************************************
*
*  $TC Tipo de dados: GRA Condiушes de retorno
*
*
*  $ED Descriусo do tipo
*     Condiушes de retorno das funушes da grade de horario
*
***********************************************************************/
 
    typedef enum {
 
        GRA_CondRetOk ,
            /* Concluiu corretamente */

		GRA_CondRetGradeVazia ,
            /* Grade Vazia*/
                     
        GRA_CondRetFaltouMemoria ,
            /* Faltou memзria ao tentar criar grade*/

	    GRA_CondRetDisciplinaNaoEncontrada ,
		   /*A discipina nao foi encontrada*/
    
		GRA_CondRetFormatoInvalido ,
		  /* Parâmetro com formato inválido */

                 
 } GRA_tpCondRet ;
 
/***********************************************************************
 *
 *  $FC Funcao: GRA &Cria Grade Horario
 *
 *  $ED Descricao da funcao:
 *     Cria uma lista de grades de horario.
 *     Alocando o espaço da mesma na memoria.
 *    
 *  $EP Parametros
 *     $P GradeHor - nome do ponteiro do ponteiro para a estrutura GradeHorario.
 *
 *  $FV Valor retornado
 *     GRA_CondRetOk
 *     GRA_CondRetFaltouMemoria
 *
***********************************************************************/
GRA_tpCondRet GRA_CriaGradeHorario ( GradeHorario ** GradeHorario );

/***********************************************************************
 *
 *  $FC Funcao: GRA &Exibe Grade Horario
 *
 *  $ED Descricao da funcao:
 *     Exibe os dados pertencentes a uma grade de horario.
 *    
 *  $EP Parametros
 *     $P GradeHorario - ponteiro para a estrutura GradeHorario a ser exibida.
 *
 *  $FV Valor retornado
 *     GRA_CondRetOk
 *     GRA_CondRetGradeVazia
 *
***********************************************************************/

GRA_tpCondRet GRA_ExibeGradeHorario(GradeHorario *GradeHorario);

/***********************************************************************
 *
 *  $FC Funcao: GRA &Insere Grade Horario
 *
 *  $ED Descricao da funcao:
 *    Insere os dados na estrutura Info Grade Horario.
 *    Alocando seu espaço na memoria.
 *    Insere uma estrutura Info Grade Horario no final da lista de grades de horario.
 *    
 *  $EP Parametros
 *     $P GradeHorario - ponteiro para a lista GradeHorario.
 *	   $P  i - ponteiro para a estrutura Info Grade de horario a ser inserida na lista.
 *     $P  d - ponteiro para a estrutura Disciplina a ser inserida na Info Grade de Horario.
 *	   $P  t- ponteiro para a estrutura Turma a ser inserida na Info Grade de Horario.
 *
 *  $FV Valor retornado
 *     GRA_CondRetOk
 *    
***********************************************************************/

GRA_tpCondRet GRA_InsereGradeHorario(InfoGradeHorario *i,Disciplina *d,Turma *t, GradeHorario* GradeHorario);

/***********************************************************************
 *
 *  $FC Funcao: GRA &Busca Grade Horario
 *
 *  $ED Descricao da funcao:
 *    Percorre a lista procurando pelo codigo da dsiciplina desejada e retorna uma Info Grade de Horario correspondente aquela disciplina.
 *    
 *  $EP Parametros
 *     $P GradeHorario - ponteiro para a lista GradeHorario.
 *	   $P codDigitado - ponteiro para o codigo da disciplina desejada.
 *
 *  $FV Valor retornado
 *     no
 *     NULL
 *    
***********************************************************************/

InfoGradeHorario* GRA_BuscaGradeHorario(GradeHorario *GradeHorario, char*codDigitado);

/***********************************************************************
 *
 *  $FC Funcao: GRA &Altera Faltas
 *
 *  $ED Descricao da funcao:
 *    Altera a quantidade de faltas da Info Grade de Horario de uma disciplina desejada que esteja na lista de Grade de Horario.
 *    Utiliza da função BuscaGradeHorario para alterar a quanticade de faltas da disciplina desejada.
 *    
 *  $EP Parametros
 *     $P GradeHorario - ponteiro para a lista GradeHorario.
 *	   $P codBuscado - ponteiro para o codigo da disciplina buscada desejada.
 *	   $P novFalta - nova quantidade de faltas.
 *
 *  $FV Valor retornado
 *     GRA_CondRetOk
 *     GRA_CondRetDisciplinaNaoEncontrada
 *
***********************************************************************/

GRA_tpCondRet GRA_AlteraFaltas(GradeHorario *GradeHorario,char *codBuscado,int novFalta);

/***********************************************************************
 *
 *  $FC Funcao: GRA &Altera Nota
 *
 *  $ED Descricao da funcao:
 *    Altera as notas da Info Grade de Horario de uma disciplina desejada que esteja na lista de Grade de Horario.
 *    Utiliza da função BuscaGradeHorario para alterar as notas da disciplina desejada.
 *    Caso as notas nao estejam no limite maior que 0 e menor que 10, as notas nao sao alteradas.
 *    
 *  $EP Parametros
 *     $P GradeHorario - ponteiro para a lista GradeHorario.
 *	   $P codBuscado - ponteiro para o codigo da disciplina buscada desejada.
 *	   $P g[4] - vetor com as novas notas.
 *
 *  $FV Valor retornado
 *     GRA_CondRetFormatoInvalido
 *     GRA_CondRetOk
 *     GRA_CondRetDisciplinaNaoEncontrada
 *
***********************************************************************/

GRA_tpCondRet GRA_AlteraNota(GradeHorario *GradeHorario,char *codBuscado,float g[4]);

/***********************************************************************
 *
 *  $FC Funcao: GRA &Elimina No
 *
 *  $ED Descricao da funcao:
 *    Elimina um no da lista de Grade de Horario.
 *    Utiliza da função BuscaGradeHorario para eliminar o no da disciplina desejada.
 *        
 *  $EP Parametros
 *     $P GradeHorario - ponteiro para a lista GradeHorario.
 *	   $P codBuscado - ponteiro para o codigo da disciplina buscada desejada.
 *
 *  $FV Valor retornado
 *     GRA_CondRetDisciplinaNaoEncontrada
 *     GRA_CondRetOk
 *
***********************************************************************/

GRA_tpCondRet GRA_EliminaNo(GradeHorario *GradeHorario,char *codBuscado);

/***********************************************************************
 *
 *  $FC Funcao: GRA &Libera Grade Horario
 *
 *  $ED Descricao da funcao:
 *    Libera o espaço alocado de uma Grade de Horario.
 *        
 *  $EP Parametros
 *     $P GradeHorario - ponteiro para a lista GradeHorario.
 *	  
 *  $FV Valor retornado
 *    GRA_CondRetOk
 *
***********************************************************************/
GRA_tpCondRet GRA_LiberaGradeHorario(GradeHorario *GradeHorario);

/***********************************************************************
 *
 *  $FC Funcao: GRA &Libera Info
 *
 *  $ED Descricao da funcao:
 *    Libera o espaço alocado de uma Info Grade de Horario.
 *        
 *  $EP Parametros
 *     $P Info - ponteiro para a estrutura Info Grade de Horario.
 *	  
 *  $FV Valor retornado
 *    GRA_CondRetOk
 *
***********************************************************************/
GRA_tpCondRet GRA_LiberaInfo(InfoGradeHorario *Info);

/********** Fim do mзdulo de definiусo: Mзdulo Grade de Horario **********/

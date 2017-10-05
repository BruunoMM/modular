/***************************************************************************
*  $MCI M?dulo de implementa??o: M?dulo de teste espec?fico
*
*  Arquivo gerado:              TESTEGRADE.C
*  Letras identificadoras:      GGRAD
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: cgln - Cristiane - Guilherme - Leonardo - Nath?lia
*
*  $HA Hist?rico de evolu??o:
*     Vers?o  Autor    Data     Observa??es
*       2.00   cgln  09/09/2017 Elimina??o de c?digo duplicado, reestrutura??o,
*                               inicio da implementa??o dos scripts e testes.
*       1.00   cgln  02/10/2017 In?cio do desenvolvimento
*
*  $ED Descri??o do m?dulo
*     Este m?odulo cont?m as fun??es espec?ficas para o teste do
*     m?dulo grade de horario. Ilustra como redigir um interpretador de comandos
*     de teste espec?ficos utilizando o arcabou?o de teste para C.
*
*  $EIU Interface com o usu?rio pessoa
*     Comandos de teste espec?ficos para testar o m?dulo turma:
*
*     "=criarGrade"           - chama a fun??o GRA_CriaGradeHorario()
*     "=exibirGrade"          - chama a fun??o GRA_ExibeGradeHorario()
*     "=excluirGrade"         - chama a fun??o GRA_ExcluiGradeHorario()
*     "=inserirInfoGrade"     - chama a função GRA_InsereGradeHorario()
*     "=alterarFaltasGrade"   - chama a função GRA_AlteraFaltas()
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include	"TST_ESPC.h"

#include    "generico.h"
#include    "lerparm.h"

#include    "GradeHorario.h"
#include    "disciplina.h"
#include    "turma.h"

/* Tabela dos nomes dos comandos de teste espec?ficos */

#define     CRIAR_GRA_CMD             "=criarGrade"
#define     EXIBIR_GRA_CMD            "=exibirGrade"
#define     EXCLUIR_GRA_CMD           "=excluirGrade"
#define     INSERIR_GRA_CMD           "=inserirInfoGrade"
#define     ALTERARFALTAS_GRA_CMD     "=alterarFaltasGrade"






/*****  C?digo das fun??es exportadas pelo m?dulo  *****/


/***********************************************************************
*
*  $FC Fun??o: GGRA Efetuar opera??es de teste espec?ficas para o m?dulo turma
*
*  $ED Descri??o da fun??o
*     Efetua os diversos comandos de teste espec?ficos para o m?dulo
*     grade de horario sendo testado.
*
*  $EP Par?metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

#define MAX_GRA 5

GradeHorario *grade[MAX_GRA] = { NULL, NULL, NULL, NULL, NULL };

TST_tpCondRet TST_EfetuarComando(char * ComandoTeste)
{

	GRA_tpCondRet CondRetObtido;
	GRA_tpCondRet CondRetEsperada;

	//Parametros GRADE
	float nota[4];

	int faltas;

	//Parametros TURMA
	int index = 0;
	int indexTur, indexDisp;
	char CodTurma[4];
	int HorarioInicio;
	int HorarioTermino;
	char DiaSemana[28];
	int QtdVaga;
	Disciplina **vtDisp;
	Turma **vtTur;
	InfoGradeHorario* info;
	int codBuscado;
	int novFalta;


	int ValorEsperado;
	int ValorObtido;

	// Criando disciplinas e turmas só para testar. Elas já precisam existir.
	DIS_gera_param(&vtDisp[0],"Programacao","INF1007",4,"Livro 1","Ponteiros");
	DIS_gera_param(&vtDisp[1], "Software", "INF1018", 4, "Livro 3", "Assembly");
	DIS_gera_param(&vtDisp[2], "BD1", "INF1383", 4, "Livro BD1", "Dados");

	TUR_CriaTurma(&vtTur[0],"3WA",13,15,"Segunda-feira",25);
	TUR_CriaTurma(&vtTur[1], "3WB", 11, 13, "Segunda-feira", 30);
	TUR_CriaTurma(&vtTur[2], "33L", 15, 17, "Terça-Feira", 35);

	/*
	int ValorObtidoHorIni ;
	int ValorObtidoHorFin ;
	int ValorObtidoQtd ;
	char ValorStringObtido[80] ;
	char ValorStringObtidoCod[4] ;
	char ValorStringObtidoSem[28] ;
	char ValorStringEsperado[80] ;
	*/

	int  NumLidos = -1;

	TST_tpCondRet Ret;

	/* Testar GRA Criar Grade de Horario  */

	if (strcmp(ComandoTeste, CRIAR_GRA_CMD) == 0)
	{

		NumLidos = LER_LerParametros("ii",
			&index, &CondRetEsperada);
		if (NumLidos != 2)
		{
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = GRA_CriaGradeHorario(grade[index]);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao criar turma.");

	} /* fim ativa: Testar GRA Criar Grade de Horario */


	  /* Testar GRA Exibe Grade de Horário */

	else if (strcmp(ComandoTeste, EXIBIR_GRA_CMD) == 0)
	{

		NumLidos = LER_LerParametros("ii",
			&index, &CondRetEsperada);
		if (NumLidos != 2)
		{
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = GRA_ExibeGradeHorario(grade[index]);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao alterar hor?rio de inicio.");

	} /* fim ativa: Testar GRA Exibe Grade de Horário */


	  /* Testar GRA Inserir Grade de Horário */

	else if (strcmp(ComandoTeste, INSERIR_GRA_CMD) == 0)
	{

		NumLidos = LER_LerParametros("iiii",
			&indexDisp, &indexTur, &index, &CondRetEsperada);
		if (NumLidos != 5)
		{
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = GRA_InsereGradeHorario(info, vtDisp[indexDisp], vtTur[indexTur], grade[index]);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao alterar horario final.");

	} /* fim ativa: Testar GRA Inserir Grade de Horário */


	  /* Testar GRA Alterar Faltas */

	else if (strcmp(ComandoTeste, ALTERARFALTAS_GRA_CMD) == 0)
	{

		NumLidos = LER_LerParametros("isii",
			&index, &codBuscado, &novFalta, &CondRetEsperada);
		if (NumLidos != 3)
		{
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = GRA_AlteraFaltas(grade[index], codBuscado, novFalta);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao alterar o dia da semana.");

	} /* fim ativa: Testar  GRA Alterar Faltas */


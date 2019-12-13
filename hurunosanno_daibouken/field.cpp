#define CONIOEX
#include "conioex.h"
#include "main.h"
#include "field.h"
#include"player.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************



//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************;

//*****************************************************************************
// グローバル変数
//*****************************************************************************
FIELD g_aField[MAX_FIELD];		// 地面の情報

//=============================================================================
// 地面の初期化処理
//=============================================================================

void InitField1(void)//メイン
{ 
	clrscr();
	
	int nCntField;
	
	

	// 地面の情報初期化
	for (nCntField = 0; nCntField < MAX_FIELD; nCntField++)
	{
		g_aField[nCntField].fPosX = 0.0f;
		g_aField[nCntField].fPosY = 0.0f;
		g_aField[nCntField].fWidth = 0.0f;
		g_aField[nCntField].bUse = false;
	}

	// 背景の設定
	
	// (X座標,Y座標,表示数)
	SetField(80.0f, 20.0f, 79.0f);
	//左側
	SetField(80.0f, 15.0f, 20.0f);
	SetField(80.0f, 10.0f, 20.0f);
	SetField(80.0f, 5.0f, 20.0f);
	//真ん中
	SetField(29.0f, 16.0f, 22.0f);
	SetField(29.0f, 11.0f, 22.0f);
	SetField(29.0f, 6.0f, 22.0f);
	//右側
	SetField(59.0f, 16.0f, 20.0f);
	SetField(59.0f, 11.0f, 21.0f);
	SetField(59.0f, 6.0f, 21.0f);
	
	
}
void InitField2()//リザルト
{
	clrscr();
	int nCntField;

	// 地面の情報初期化
	for (nCntField = 0; nCntField < MAX_FIELD; nCntField++)
	{
		g_aField[nCntField].fPosX = 0.0f;
		g_aField[nCntField].fPosY = 0.0f;
		g_aField[nCntField].fWidth = 0.0f;
		g_aField[nCntField].bUse = false;
	}
	SetField(80.0f, 20.0f, 79.0f);

	
		


			gotoxy(2, 2);
			printf("■■■■　■■■■■　　■　　　■■■■　■■■■　■■■\n");


			gotoxy(2, 3);
			printf("■　　　　　　■　　　■　■　　■　　　　■　　　　　　　■\n");


			gotoxy(2, 4);
			printf("■■■■　　　■　　■　　　■　■　■■　■■■■　　■■\n");

			gotoxy(8, 5);
			printf("■　　　■　　■■■■■　■　　■　■　　　　■\n");

			gotoxy(2, 6);
			printf("■■■■　　　■　　■　　　■　■■■■　■■■■　■■■■\n");

			gotoxy(2, 8);
			printf("■■■■　■　　　　■■■■　　　■　　　■■■■　　　■");


			gotoxy(2, 9);
			printf("■　　　　■　　　　■　　　　　■　■　　■　　　■　　■");

			gotoxy(2, 10);
			printf("■　　　　■　　　　■■■■　■　　　■　■■■■　　　■");

			gotoxy(2, 11);
			printf("■　　　　■　　　　■　　　　■■■■■　■　　 ■");

			gotoxy(2, 12);
			printf("■■■■　■■■■　■■■■　■　　　■　■　　  ■　　■");
		

		

		gotoxy(2, 22);
		printf("←タイトルへ\n");
		gotoxy(69, 22);
		printf("タイトルへ→\n");
	
}
void InitField0(void)//タイトル
{
	
	//textattr(28);
	int nCntField;
	clrscr();

	// 地面の情報初期化
	for (nCntField = 0; nCntField < MAX_FIELD; nCntField++)
	{
		g_aField[nCntField].fPosX = 0.0f;
		g_aField[nCntField].fPosY = 0.0f;
		g_aField[nCntField].fWidth = 0.0f;
		g_aField[nCntField].bUse = false;
	}

	SetField(80.0f, 20.0f, 79.0f);
	textcolor(12);
	gotoxy(13, 4);
	printf(" ふる  の　ただ　ひ　 こ");
	gotoxy(15,5);
	textcolor(14);
	printf("古 　野 　忠　 比　 古　　の　　迷　　路　　冒　　険\n");
	gotoxy(19, 11);
	printf("←,Aキー:左に移動");
	gotoxy(46, 11);
	printf("→,Dキー:右に移動");
	gotoxy(32, 12);
	printf("spaceキー:ジャンプ");

	textcolor(11);
	gotoxy(1, 22);
	printf("１．左右にある上下4つの道を進むとそれぞれ反対側の道にランダムにワープするゾ！");
	textcolor(15);
	gotoxy(1, 23);
	printf("２．出てきた道に応じてポイントがもらえるゾ！");
	textcolor(12);
	gotoxy(1, 24);
	printf("３．目標ポイント数に達するとステージクリアだゾ！");
	textcolor(10);
	gotoxy(1, 25);
	printf("４．ポイントはこの欄に表示されるゾ！");
	gotoxy(46, 25);
	textcolor(13);
	printf("右側に行くとゲームスタートだゾ！→");
	
}
void InitField3(void)
{
	clrscr();

	int nCntField;



	// 地面の情報初期化
	for (nCntField = 0; nCntField < MAX_FIELD; nCntField++)
	{
		g_aField[nCntField].fPosX = 0.0f;
		g_aField[nCntField].fPosY = 0.0f;
		g_aField[nCntField].fWidth = 0.0f;
		g_aField[nCntField].bUse = false;
	}

	// 背景の設定

	// (X座標,Y座標,表示数)
	SetField(80.0f, 20.0f, 79.0f);
	//左側
	SetField(80.0f, 15.0f, 20.0f);
	SetField(80.0f, 10.0f, 20.0f);
	SetField(80.0f, 5.0f, 20.0f);
	//真ん中
	SetField(29.0f, 16.0f, 22.0f);
	SetField(29.0f, 11.0f, 22.0f);
	SetField(29.0f, 6.0f, 22.0f);
	//右側
	SetField(59.0f, 16.0f, 20.0f);
	SetField(59.0f, 11.0f, 21.0f);
	SetField(59.0f, 6.0f, 21.0f);
}

void InitField4()//中間地点
{
	int nCntField;
	clrscr();

	// 地面の情報初期化
	for (nCntField = 0; nCntField < MAX_FIELD; nCntField++)
	{
		g_aField[nCntField].fPosX = 0.0f;
		g_aField[nCntField].fPosY = 0.0f;
		g_aField[nCntField].fWidth = 0.0f;
		g_aField[nCntField].bUse = false;
	}

	SetField(80.0f, 20.0f, 79.0f);
	
	//gotoxy(19, 8);
	//printf("ステージ1クリア");
	gotoxy(2, 2);
	printf("■■■■　■■■■■　　■　　　■■■■　■■■■　■■\n");
	gotoxy(2, 3);
	printf("■　　　　　　■　　　■　■　　■　　　　■　　　　　■\n");
	gotoxy(2, 4);
	printf("■■■■　　　■　　■　　　■　■　■■　■■■■　　■\n");
	gotoxy(8, 5);
	printf("■　　　■　　■■■■■　■　　■　■　　　　　■\n");
	gotoxy(2, 6);
	printf("■■■■　　　■　　■　　　■　■■■■　■■■■　■■■\n");
	gotoxy(2, 8);
	printf("■■■■　■　　　　■■■■　　　■　　　■■■■　　　■");
	gotoxy(2, 9);
	printf("■　　　　■　　　　■　　　　　■　■　　■　　　■　　■");
	gotoxy(2, 10);
	printf("■　　　　■　　　　■■■■　■　　　■　■■■■　　　■");
	gotoxy(2, 11);
	printf("■　　　　■　　　　■　　　　■■■■■　■　　 ■");
	gotoxy(2, 12);
	printf("■■■■　■■■■　■■■■　■　　　■　■　　  ■　　■");
	


	gotoxy(2,22);
	printf("←ステージ2へ");
	gotoxy(69,22);
	printf("タイトルへ→");
}


//=============================================================================
// 地面の終了処理
//=============================================================================
void UninitField(void)
{
}

//=============================================================================
// 地面の更新処理
//=============================================================================
void UpdateField(void)
{
	
}

//=============================================================================
// 地面の描画処理
//=============================================================================
void DrawField(void)
{

	int nCntField;

	// 色の設定
	textcolor(WHITE);
	
	// 地面の表示
	for (nCntField = 0; nCntField < MAX_FIELD; nCntField++)
	{
		if (g_aField[nCntField].bUse == true)
		{
			char aBuf[80];

			strcpy(&aBuf[0], "\0");
			gotoxy((int)g_aField[nCntField].fPosX, (int)g_aField[nCntField].fPosY);

			for (int nCntBlock = 0; nCntBlock < (int)g_aField[nCntField].fWidth / 2; nCntBlock++)
			{
				// 表示する図形
				strcat(&aBuf[0], "□");
			}
			printf("%s", &aBuf[0]);
		}
	}
	
}

//=============================================================================
// 地面の設定
//=============================================================================
void SetField(float fPosX, float fPosY, float fWidth)
{
	int nCntField;

	for (nCntField = 0; nCntField < MAX_FIELD; nCntField++)
	{
		if (g_aField[nCntField].bUse == false)
		{
			g_aField[nCntField].fPosX = fPosX;
			g_aField[nCntField].fPosY = fPosY;
			g_aField[nCntField].fWidth = fWidth;
			g_aField[nCntField].bUse = true;
			break;
		}
	}
}

//=============================================================================
// 地面の取得
//=============================================================================
FIELD *GetField(void)
{
	return &g_aField[0];
}

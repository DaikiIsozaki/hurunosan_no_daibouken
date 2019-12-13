#include "main.h"
#include "player.h"
#include"conioex.h"
#include"field.h"

void Init(void);
void Uninit(void);
void Update(void);
void Draw(void);
void DispFPS(void);
int sound = opensound("FF5 ビッグブリッヂの死闘.mp3");

//#define DEBUG

int g_nCountFPS;				// FPSカウンタ


void main(void)
{
	playsound(sound, 1);


	// FPS計測するための変数
	DWORD dwExecLastTime;
	DWORD dwFPSLastTime;
	DWORD dwCurrentTime;
	int nCountFrame;
	
	
	
	setcursortype(NOCURSOR);
	
	

	// FPS計測の為の初期設定
	// 分解能を設定(何もしないとタイマの精度が悪くなるので設定)
	timeBeginPeriod(1);

	dwExecLastTime =
		dwFPSLastTime = timeGetTime();
	dwCurrentTime =
		nCountFrame = 0;

	Init();

	int so = 0;
	do
	{
		so = so + 1;

		dwCurrentTime = timeGetTime();
		if ((dwCurrentTime - dwFPSLastTime) >= 500)	// 0.5秒ごとに実行(毎回実行するとチカチカするので)
		{
			g_nCountFPS = nCountFrame * 1000 / (dwCurrentTime - dwFPSLastTime);
			dwFPSLastTime = dwCurrentTime;
			nCountFrame = 0;
		}

		if ((dwCurrentTime - dwExecLastTime) >= (1000 / 60))// FPSを60にするために設定
		{
			dwExecLastTime = dwCurrentTime;
			
				//更新処理
				Update();

				//描画処理
				Draw();

#ifdef DEBUG
				// FPS表示
				DispFPS();
#endif
				
				nCountFrame++;
				gotoxy(1, 1);
				//printf("%d", so / 60000);
			

		}
	} while (!inport(PK_ESC));

	Uninit();

	// 分解能を戻す
	timeEndPeriod(1);
	
	
	
	closesound(sound);
}

//=============================================================================
// 初期化処理
//=============================================================================
void Init(void)
{
	// プレイヤーの初期化処理
	InitPlayer();
	// 地面の初期化処理
	//InitField0();
	InitField0();
	
}

//=============================================================================
// 終了処理
//=============================================================================
void Uninit(void)
{
	// プレイヤーの終了処理
	UninitPlayer();
	// 地面の終了処理
	UninitField();
}

//=============================================================================
// 更新処理
//=============================================================================
void Update(void)
{
	// プレイヤーの更新処理
	UpdatePlayer();
	// 地面の更新処理
	UpdateField();
	Atari();
	
}

//=============================================================================
// 描画処理
//=============================================================================
void Draw(void)
{
	// プレイヤーの描画処理
	DrawPlayer();
	// 地面の描画処理
	DrawField();
	
}

#ifdef DEBUG
//=============================================================================
// FPS表示
//=============================================================================
void DispFPS(void)
{
	// 色設定

	textcolor(WHITE);

	gotoxy(1, 1);
	printf("FPS:%d", g_nCountFPS);
	gotoxy(1, 3);
	

	
}
#endif

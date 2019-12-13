#ifndef _PLAYER_H_	// ２重インクルード防止のマクロ定義
#define _PLAYER_H_

//プレイヤー構造体
typedef struct {
	float PosX;		//建材位置の座標(X座標)
	float PosY;		//現在位置の座標(Y座標)
	float MoveX;	//移動量(X方向)
	float MoveY;	//移動量(Y方向)
	bool bMove;		//移動したかどうか
	bool bJump;
	bool atari1;
	bool main;
	bool main2;
	bool main3;
	bool title;
	bool clear;
	bool tutorial;
	bool tyukan;
	float PosOldX;	//前回の位置X
	float PosOldY;	//前回の位置Y
	
}PLAYER;






void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);
void Atari(void);


#endif
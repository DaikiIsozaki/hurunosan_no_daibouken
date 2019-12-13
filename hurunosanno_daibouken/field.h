#ifndef _FIELD_H_
#define _FIELD_H_

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define	MAX_FIELD		(40)	// 地面の最大数

//*************************************
// 地面の構造体
//*************************************
typedef struct
{
	float fPosX;		// 地面の基準位置(Ｘ座標)
	float fPosY;		// 地面の基準位置(Ｙ座標)
	float fWidth;		// 地面の幅
	
	bool bUse;			// 地面を使用しているかどうか
	bool color;
} FIELD;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
void InitField0(void);
void InitField1(void);
void InitField2(void);
void InitField3(void);
void InitField4(void);
void UninitField(void);
void UpdateField(void);
void DrawField(void);


void SetField(float fPosX, float fPosY, float fWidth);
FIELD *GetField(void);

#endif
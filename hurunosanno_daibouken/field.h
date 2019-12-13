#ifndef _FIELD_H_
#define _FIELD_H_

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define	MAX_FIELD		(40)	// �n�ʂ̍ő吔

//*************************************
// �n�ʂ̍\����
//*************************************
typedef struct
{
	float fPosX;		// �n�ʂ̊�ʒu(�w���W)
	float fPosY;		// �n�ʂ̊�ʒu(�x���W)
	float fWidth;		// �n�ʂ̕�
	
	bool bUse;			// �n�ʂ��g�p���Ă��邩�ǂ���
	bool color;
} FIELD;

//*****************************************************************************
// �v���g�^�C�v�錾
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
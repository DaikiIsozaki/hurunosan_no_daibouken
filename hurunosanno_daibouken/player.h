#ifndef _PLAYER_H_	// �Q�d�C���N���[�h�h�~�̃}�N����`
#define _PLAYER_H_

//�v���C���[�\����
typedef struct {
	float PosX;		//���ވʒu�̍��W(X���W)
	float PosY;		//���݈ʒu�̍��W(Y���W)
	float MoveX;	//�ړ���(X����)
	float MoveY;	//�ړ���(Y����)
	bool bMove;		//�ړ��������ǂ���
	bool bJump;
	bool atari1;
	bool main;
	bool main2;
	bool main3;
	bool title;
	bool clear;
	bool tutorial;
	bool tyukan;
	float PosOldX;	//�O��̈ʒuX
	float PosOldY;	//�O��̈ʒuY
	
}PLAYER;






void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);
void Atari(void);


#endif
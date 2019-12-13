#define CONIOEX
#include "conioex.h"
#include"field.h"
#include "main.h"
#include "player.h"

//////////////////////////////////////////////////////////////////////////////
//�}�N����`
//////////////////////////////////////////////////////////////////////////////
#define VALUE_MOVE_X		(0.35f)	//X�����ړ���

#define VALUE_RESIST_X		(0.50f)	//�n��ł̖��C
#define VALUE_MOVE_X_AIR	(0.30f)
#define LIMIT_LEFT			(2.0f)	//�ړ��͈͍��[
#define LIMIT_RIGHT			(77.0f)	//�ړ��͈͉E�[
#define LIMIT_DOWN			(20.0f)
#define LIMIT_UP			(2.0f)

#define VALUE_GRAVITY		(0.08f)//�d��
#define VALUE_JUMP			(0.90f)


//////////////////////////////////////////////////////////////////////////////
//�O���[�o���ϐ�
//////////////////////////////////////////////////////////////////////////////
PLAYER g_player;
int menu=1;
int cNt[8] = { 0,0,0,0,0,0,0,0 };
int ScNt=0;
//int sound = opensound("FF5 �r�b�O�u���b�a�̎���.mp3");
int SP = 0;
int S2P = 0;
int wk = 0;

//////////////////////////////////////////////////////////////////////////////
//�֐���	:	InitPlayer
//�߂�l	:
//����		:	�ʒu������
//////////////////////////////////////////////////////////////////////////////
void InitPlayer(void)
{
	//playsound(sound, 1);

	g_player.PosX = 20.0f;
	g_player.PosY = 20.0f;
	g_player.PosOldX = 20.0f;
	g_player.PosOldY = 20.0f;
	g_player.MoveX = 0.0f;
	g_player.MoveY = 0.0f;

	g_player.bMove = false;
	g_player.bJump = false;
	g_player.atari1 = false;
	g_player.main= false;
	g_player.main2 = false;
	g_player.main3 = false;
	g_player.title = true;
	g_player.clear = false;
	g_player.tutorial = false;
	g_player.tyukan = false;
	
	

	//closesound(sound);
	
}

void UninitPlayer(void)
{
}

void UpdatePlayer(void)
{
	//playsound(sound, 1);
	srand((unsigned)time(NULL));
	int wpp = 0;
	int wpp2 = 0;
	int wpp3 = 0;
	int wpp4 = 0;
	int g = 0;
	int g2 = 0;
	//�ߋ��̈ʒu��ۑ�
	g_player.PosOldX = g_player.PosX;
	g_player.PosOldY = g_player.PosY;

	//���ړ�����
	if (inport(PK_LEFT))
	{
		if (g_player.bJump)
		{
			g_player.MoveX -= VALUE_MOVE_X_AIR;
		}
		else
		{
			g_player.MoveX -= VALUE_MOVE_X;
		}

		g_player.MoveX -= VALUE_MOVE_X;
		g_player.bMove = true;
	}
	//�E�ړ�����
	if (inport(PK_RIGHT))
	{

		if (g_player.bJump)
		{
			g_player.MoveX += VALUE_MOVE_X_AIR;
		}
		else
		{
			g_player.MoveX += VALUE_MOVE_X;
		}
		g_player.MoveX += VALUE_MOVE_X;
		g_player.bMove = true;

	}
	if (inport(PK_A))
	{
		if (g_player.bJump)
		{
			g_player.MoveX -= VALUE_MOVE_X_AIR;
		}
		else
		{
			g_player.MoveX -= VALUE_MOVE_X;
		}

		g_player.MoveX -= VALUE_MOVE_X;
		g_player.bMove = true;
	}
	//�E�ړ�����
	if (inport(PK_D))
	{

		if (g_player.bJump)
		{
			g_player.MoveX += VALUE_MOVE_X_AIR;
		}
		else
		{
			g_player.MoveX += VALUE_MOVE_X;
		}
		g_player.MoveX += VALUE_MOVE_X;
		g_player.bMove = true;

	}

	//�W�����v�ړ�����
	if (inport(PK_SP))
	{
		if (!g_player.bJump == true)
		{
			g_player.MoveY -= VALUE_JUMP;
			g_player.bMove = true;
			g_player.bJump = true;

		}

	}



	//��R��������
	g_player.MoveX += (0.0f - g_player.MoveX)*VALUE_RESIST_X;

	//�ʒu�̍X�V����
	g_player.PosX += g_player.MoveX;


	//�X�e�[�W����@ugoki1
	if (g_player.main == true)
	{
		
		//��ʒ[�΍�
		//���[
		if (g_player.PosX < LIMIT_LEFT)
		{
			g_player.PosX = LIMIT_RIGHT - 1;
			//g_player.PosY = rand() % 25;
			wpp = ((int)rand() % 7 + 1);
			//gotoxy(1, 1);
			//printf("%d",wpp);
			ScNt += 1;

			if (wpp == 1 || wpp == 5)
			{
				g_player.PosY = 20;
			}
			if (wpp == 2 || wpp == 6)
			{
				g_player.PosY = 15;
			}
			if (wpp == 3 || wpp == 7)
			{
				g_player.PosY = 10;
			}
			if (wpp == 4 || wpp == 8)
			{
				g_player.PosY = 5;
			}

			if (((g_player.PosY <= LIMIT_DOWN) && (g_player.PosY >= 17)) && ((g_player.PosX <= LIMIT_RIGHT) && (g_player.PosX >= (LIMIT_RIGHT - 20))))
			{
				cNt[0] = ((int)(rand() % 4 + 1));// +((int)(rand() % 1 + 1)));

			}

			if (((g_player.PosY <= 16) && (g_player.PosY >= 12)) && ((g_player.PosX <= LIMIT_RIGHT) && (g_player.PosX >= (LIMIT_RIGHT - 20))))
			{
				cNt[1] = ((int)(rand() % 4 + 1));//+((int)(rand() % 1 + 1)));

			}
			if (((g_player.PosY <= 11) && (g_player.PosY >= 7)) && ((g_player.PosX <= LIMIT_RIGHT) && (g_player.PosX >= (LIMIT_RIGHT - 20))))
			{
				cNt[2] = ((int)(rand() % 4 + 1));// +((int)(rand() % 1 + 1)));

			}
			if (((g_player.PosY <= 6) && (g_player.PosY >= LIMIT_UP)) && ((g_player.PosX <= LIMIT_RIGHT) && (g_player.PosX >= (LIMIT_RIGHT - 20))))
			{
				cNt[3] = ((int)(rand() % 4 + 1));// +((int)(rand() % 1 + 1)));

			}
			/*if (wpp == 1)
			{
				g_player.PosY = 20;
				g_player.PosX = LIMIT_RIGHT - 1;
				cNt[0] = ((int)(rand() % 4 + 1)) + ((int)(rand() % 1 + 1));
				ScNt[0] += 1;
			}
			if (wpp = 2)
			{
				g_player.PosY = 15;
				g_player.PosX = LIMIT_RIGHT - 1;
				cNt[1] = (int)(rand() % 4 + 1) + ((int)(rand() % 1 + 1));
				ScNt[1] += 1;
			}
			if (wpp == 3)
			{
				g_player.PosY = 10;
				g_player.PosX = LIMIT_RIGHT - 1;
				cNt[2] = (int)(rand() % 4 + 1) + ((int)(rand() % 1 + 1));
				ScNt[2] += 1;
			}
			if (wpp == 4)
			{
				g_player.PosY = 5;
				g_player.PosX = LIMIT_RIGHT - 1;
				cNt[3] = (int)(rand() % 4 + 1) + ((int)(rand() % 1 + 1));
				ScNt[3] += 1;
			}*/
		}


		//�E�[
		if (g_player.PosX > LIMIT_RIGHT)
		{
			g_player.PosX = LIMIT_LEFT + 1;
			//g_player.PosY = rand() % 25 + 1;
			wpp2 = ((int)rand() % 7 + 1);
			//gotoxy(1, 2);
			//printf("%d", wpp2);
			ScNt += 1;

			if (wpp2 == 4 || wpp2 == 6)
			{
				g_player.PosY = 20;
			}
			if (wpp2 == 3 || wpp2 == 5)
			{
				g_player.PosY = 15;
			}
			if (wpp2 == 2 || wpp2 == 8)
			{
				g_player.PosY = 10;
			}
			if (wpp2 == 1 || wpp2 == 7)
			{
				g_player.PosY = 5;
			}

			if (((g_player.PosY <= LIMIT_DOWN) && (g_player.PosY >= 17)) && ((g_player.PosX <= LIMIT_LEFT + 20) && (g_player.PosX >= LIMIT_LEFT)))
			{
				cNt[4] = ((int)(rand() % 4 + 1) + ((int)(rand() % 1 + 1)));

			}

			if (((g_player.PosY <= 16) && (g_player.PosY >= 12)) && ((g_player.PosX <= LIMIT_LEFT + 20) && (g_player.PosX >= LIMIT_LEFT)))
			{
				cNt[5] = ((int)(rand() % 4 + 1) + ((int)(rand() % 1 + 1)));

			}

			if (((g_player.PosY <= 11) && (g_player.PosY >= 7)) && ((g_player.PosX <= LIMIT_LEFT + 20) && (g_player.PosX >= LIMIT_LEFT)))
			{
				cNt[6] = ((int)(rand() % 4 + 1) + ((int)(rand() % 1 + 1)));

			}

			if (((g_player.PosY <= 6) && (g_player.PosY >= LIMIT_UP)) && ((g_player.PosX <= LIMIT_LEFT + 20) && (g_player.PosX >= LIMIT_LEFT)))
			{
				cNt[7] = ((int)(rand() % 4 + 1) + ((int)(rand() % 1 + 1)));

			}
		}
		
		//gotoxy(1, 22);
		//printf("%d(�E1�i),%d(�E2�i),%d(�E3�i),%d(�E4�i),%d(��1�i),%d(��2�i),%d(��3�i),%d(��4�i)", cNt[0], cNt[1], cNt[2], cNt[3], cNt[4], cNt[5], cNt[6], cNt[7]);
		gotoxy(1, 24);
		printf("�ڕW�|�C���g:25p�ȏ�	�q���g�F�V��ɒ���t���ď�ւ̈ړ����y��");
		g = (cNt[0] + cNt[1] + cNt[2] + cNt[3] + cNt[4] + cNt[5] + cNt[6] + cNt[7]);
		gotoxy(1, 23);
		printf("���v�|�C���g:%d", g);

		if (cNt[0] + cNt[1] + cNt[2] + cNt[3] + cNt[4] + cNt[5] + cNt[6] + cNt[7] >= 25)
		{

			InitField4();
			g_player.atari1 = false;
			g_player.main = false;
			g_player.title = false;
			g_player.tyukan = true;
			g_player.PosX = 40.0f;
			g_player.PosY = 20.0f;
			SP = cNt[0] + cNt[1] + cNt[2] + cNt[3] + cNt[4] + cNt[5] + cNt[6] + cNt[7];

			cNt[0] = 0;
			cNt[1] = 0;
			cNt[2] = 0;
			cNt[3] = 0;
			cNt[4] = 0;
			cNt[5] = 0;
			cNt[6] = 0;
			cNt[7] = 0;
		}
	}
	if (g_player.main2 == true)
	{

		//��ʒ[�΍�
		//���[
		if (g_player.PosX < LIMIT_LEFT)
		{
			g_player.PosX = LIMIT_RIGHT - 1;
			wpp3 = ((int)rand() % 7 + 1);
			//g_player.PosY = rand() % 24;
			ScNt += 1;

			if (wpp3 == 1 || wpp3 == 5)
			{
				g_player.PosY = 20;
			}
			if (wpp3 == 2 || wpp == 6)
			{
				g_player.PosY = 15;
			}
			if (wpp3 == 3 || wpp3 == 7)
			{
				g_player.PosY = 10;
			}
			if (wpp3 == 4 || wpp3 == 8)
			{
				g_player.PosY = 5;
			}

			if (((g_player.PosY <= LIMIT_DOWN) && (g_player.PosY > 17)) && ((g_player.PosX < LIMIT_RIGHT) && (g_player.PosX > (LIMIT_RIGHT - 20))))
			{
				cNt[0] = ((int)(rand() % 7 + 1)) + ((int)(rand() % 1));

			}
			if (((g_player.PosY <= 16) && (g_player.PosY > 12)) && ((g_player.PosX < LIMIT_RIGHT) && (g_player.PosX > (LIMIT_RIGHT - 20))))
			{
				cNt[1] = (int)(rand() % 7 + 1) + ((int)(rand() % 1));

			}
			if (((g_player.PosY <= 11) && (g_player.PosY > 7)) && ((g_player.PosX < LIMIT_RIGHT) && (g_player.PosX > (LIMIT_RIGHT - 20))))
			{
				cNt[2] = (int)(rand() % 7 + 1) + ((int)(rand() % 1));

			}
			if (((g_player.PosY <= 6) && (g_player.PosY >= LIMIT_UP)) && ((g_player.PosX < LIMIT_RIGHT) && (g_player.PosX > (LIMIT_RIGHT - 20))))
			{
				cNt[3] = (int)(rand() % 7 + 1) + ((int)(rand() % 1));

			}
		}



		//�E�[
		if (g_player.PosX > LIMIT_RIGHT)
		{
			g_player.PosX = LIMIT_LEFT + 1;
			//g_player.PosY = rand() % 25 + 1;
			wpp4 = ((int)rand() % 7 + 1);
			ScNt += 1;

			if (wpp4 == 4 || wpp4 == 6)
			{
				g_player.PosY = 20;
			}
			if (wpp4 == 3 || wpp4 == 5)
			{
				g_player.PosY = 15;
			}
			if (wpp4 == 2 || wpp4 == 8)
			{
				g_player.PosY = 10;
			}
			if (wpp4 == 1 || wpp4 == 7)
			{
				g_player.PosY = 5;
			}

			if (((g_player.PosY <= LIMIT_DOWN) && (g_player.PosY > 17)) && ((g_player.PosX <= 20) && (g_player.PosX >= LIMIT_LEFT)))
			{
				cNt[4] = (int)(rand() % 7 + 1) + ((int)(rand() % 1));

			}

			if (((g_player.PosY <= 16) && (g_player.PosY > 12)) && ((g_player.PosX <= 20) && (g_player.PosX >= LIMIT_LEFT)))
			{
				cNt[5] = (int)(rand() % 7 + 1) + ((int)(rand() % 1));

			}

			if (((g_player.PosY <= 11) && (g_player.PosY > 7)) && ((g_player.PosX <= 20) && (g_player.PosX >= LIMIT_LEFT)))
			{
				cNt[6] = (int)(rand() % 7 + 1) + ((int)(rand() % 1));

			}

			if (((g_player.PosY <= 6) && (g_player.PosY >= LIMIT_UP)) && ((g_player.PosX <= 20) && (g_player.PosX >= LIMIT_LEFT)))
			{
				cNt[7] = (int)(rand() % 7 + 1) + ((int)(rand() % 1));

			}


		}
		gotoxy(1, 22);
		//printf("%d,%d,%d,%d,%d,%d,%d,%d", cNt[0], cNt[1], cNt[2], cNt[3], cNt[4], cNt[5], cNt[6], cNt[7]);
		gotoxy(1, 24);
		printf("�ڕW�|�C���g:40p�ȏ�");
		g2 = (cNt[0] + cNt[1] + cNt[2] + cNt[3] + cNt[4] + cNt[5] + cNt[6] + cNt[7]);
		gotoxy(1, 23);
		printf("���v�|�C���g:%d", g2);
		if (cNt[0] + cNt[1] + cNt[2] + cNt[3] + cNt[4] + cNt[5] + cNt[6] + cNt[7] >= 40)
		{

			InitField2();
			g_player.atari1 = false;
			g_player.main2 = false;
			g_player.title = false;
			g_player.clear = true;
			g_player.PosX = 40.0f;
			g_player.PosY = 20.0f;
			S2P = cNt[0] + cNt[1] + cNt[2] + cNt[3] + cNt[4] + cNt[5] + cNt[6] + cNt[7];
			cNt[0] = 0;
			cNt[1] = 0;
			cNt[2] = 0;
			cNt[3] = 0;
			cNt[4] = 0;
			cNt[5] = 0;
			cNt[6] = 0;
			cNt[7] = 0;
		}
	}
	//�X�e�[�W�Ȃ��E�^�C�g���@ugoki2
	if (g_player.title == true)
	{


		if (g_player.PosX < LIMIT_LEFT)
		{
			g_player.PosX = LIMIT_LEFT;
		}
		if (g_player.PosX > LIMIT_RIGHT)
		{
			InitField3();
			g_player.PosX = 20;
			g_player.main3 = true;
			g_player.title = false;
			g_player.atari1 = true;

		}
	}

	if (g_player.main3 == true)
	{
		gotoxy(1, 22);
		printf("�P�D���E�ɂ���㉺4�̓���i�ނƂ��ꂼ�ꔽ�Α��̓��Ƀ����_���Ƀ��[�v����]�I");
		gotoxy(1, 23);
		printf("�Q�D�o�Ă������ɉ����ă|�C���g�����炦��]�I");
		gotoxy(1, 24);
		printf("�R�D�ڕW�|�C���g���ɒB����ƃX�e�[�W�N���A���]�I");
		gotoxy(1, 25);
		printf("%d(�E1�i),%d(�E2�i),%d(�E3�i),%d(�E4�i),%d(��1�i),%d(��2�i),%d(��3�i),%d(��4�i)", cNt[0], cNt[1], cNt[2], cNt[3], cNt[4], cNt[5], cNt[6], cNt[7]);
		
		/*gotoxy(1, 22);
		printf("%d,%d,%d,%d,%d,%d,%d,%d", cNt[0], cNt[1], cNt[2], cNt[3], cNt[4], cNt[5], cNt[6], cNt[7]);
		gotoxy(1, 24);
		printf("�ڕW�|�C���g:15p�ȏ�");
		g2 = (cNt[0] + cNt[1] + cNt[2] + cNt[3] + cNt[4] + cNt[5] + cNt[6] + cNt[7]);
		gotoxy(1, 23);
		printf("���v�|�C���g:%d", g2);
		gotoxy(1, 25);
		printf("�`���[�g���A��");*/
		//��ʒ[�΍�
		//���[
		if (g_player.PosX < LIMIT_LEFT)
		{
			g_player.PosX = LIMIT_RIGHT - 1;
			wpp3 = ((int)rand() % 7 + 1);
			//g_player.PosY = rand() % 24;
			ScNt += 1;

			if (wpp3 == 1 || wpp3 == 5)
			{
				g_player.PosY = 20;
			}
			if (wpp3 == 2 || wpp == 6)
			{
				g_player.PosY = 15;
			}
			if (wpp3 == 3 || wpp3 == 7)
			{
				g_player.PosY = 10;
			}
			if (wpp3 == 4 || wpp3 == 8)
			{
				g_player.PosY = 5;
			}

			if (((g_player.PosY <= LIMIT_DOWN) && (g_player.PosY > 17)) && ((g_player.PosX < LIMIT_RIGHT) && (g_player.PosX > (LIMIT_RIGHT - 20))))
			{
				cNt[0] += 1;

			}
			if (((g_player.PosY <= 16) && (g_player.PosY > 12)) && ((g_player.PosX < LIMIT_RIGHT) && (g_player.PosX > (LIMIT_RIGHT - 20))))
			{
				cNt[1] += 1;

			}
			if (((g_player.PosY <= 11) && (g_player.PosY > 7)) && ((g_player.PosX < LIMIT_RIGHT) && (g_player.PosX > (LIMIT_RIGHT - 20))))
			{
				cNt[2] += 1;

			}
			if (((g_player.PosY <= 6) && (g_player.PosY >= LIMIT_UP)) && ((g_player.PosX < LIMIT_RIGHT) && (g_player.PosX > (LIMIT_RIGHT - 20))))
			{
				cNt[3] += 1;

			}
		}



		//�E�[
		if (g_player.PosX > LIMIT_RIGHT)
		{
			g_player.PosX = LIMIT_LEFT + 1;
			//g_player.PosY = rand() % 25 + 1;
			wpp4 = ((int)rand() % 7 + 1);
			ScNt += 1;

			if (wpp4 == 4 || wpp4 == 6)
			{
				g_player.PosY = 20;
			}
			if (wpp4 == 3 || wpp4 == 5)
			{
				g_player.PosY = 15;
			}
			if (wpp4 == 2 || wpp4 == 8)
			{
				g_player.PosY = 10;
			}
			if (wpp4 == 1 || wpp4 == 7)
			{
				g_player.PosY = 5;
			}

			if (((g_player.PosY <= LIMIT_DOWN) && (g_player.PosY > 17)) && ((g_player.PosX <= 20) && (g_player.PosX >= LIMIT_LEFT)))
			{
				cNt[4] += 1;

			}

			if (((g_player.PosY <= 16) && (g_player.PosY > 12)) && ((g_player.PosX <= 20) && (g_player.PosX >= LIMIT_LEFT)))
			{
				cNt[5] += 1;

			}

			if (((g_player.PosY <= 11) && (g_player.PosY > 7)) && ((g_player.PosX <= 20) && (g_player.PosX >= LIMIT_LEFT)))
			{
				cNt[6] += 1;

			}

			if (((g_player.PosY <= 6) && (g_player.PosY >= LIMIT_UP)) && ((g_player.PosX <= 20) && (g_player.PosX >= LIMIT_LEFT)))
			{
				cNt[7] += 1;

			}


			
			if (cNt[0] + cNt[1] + cNt[2] + cNt[3] + cNt[4] + cNt[5] + cNt[6] + cNt[7] >= 15)
			{

				InitField3();
				g_player.main = true;
				g_player.main3 = false;
				g_player.title = false;
				//g_player.clear = true;
				g_player.PosX = 40.0f;
				g_player.PosY = 20.0f;
				S2P = cNt[0] + cNt[1] + cNt[2] + cNt[3] + cNt[4] + cNt[5] + cNt[6] + cNt[7];
				cNt[0] = 0;
				cNt[1] = 0;
				cNt[2] = 0;
				cNt[3] = 0;
				cNt[4] = 0;
				cNt[5] = 0;
				cNt[6] = 0;
				cNt[7] = 0;
			}
		}
	}
		//�N���A��@ugoki3

		if (g_player.clear == true)
		{
			gotoxy(20, 23);
			printf("���ړ���:%d", ScNt);

			if (g_player.PosX < LIMIT_LEFT)
			{
				InitField0();//�^�C�g���X�e�[�W
				g_player.PosX = 20;
				g_player.main = false;
				g_player.title = true;
				g_player.atari1 = false;
				g_player.clear = false;
			}
			if (g_player.PosX > LIMIT_RIGHT)
			{
				InitField0();//�^�C�g���X�e�[�W
				g_player.PosX = 20;
				g_player.main = false;
				g_player.title = true;
				g_player.atari1 = false;
				g_player.clear = false;

			}
		}


		//���Ԓn�_�@ugoki5
		if (g_player.tyukan == true)
		{
			//gotoxy(20,9);
			//printf("�擾�|�C���g:%d",SP);



			if (g_player.PosX < LIMIT_LEFT)
			{
				InitField1();
				g_player.PosX = 40;
				g_player.tyukan = false;
				g_player.main2 = true;
				g_player.atari1 = true;
			}
			if (g_player.PosX > LIMIT_RIGHT)
			{
				InitField0();//�^�C�g���X�e�[�W
				g_player.PosX = 20;
				g_player.main = false;
				g_player.title = true;
				g_player.atari1 = false;
				g_player.tyukan = false;
			}
		}




		//�d�͏���
		g_player.MoveY += VALUE_GRAVITY;

		//�X�V����
		g_player.PosY += g_player.MoveY;



		//���ɂ߂荞�񂾎��̏���
		if (g_player.PosY > LIMIT_DOWN)
		{
			g_player.PosY = LIMIT_DOWN;
			g_player.MoveY = 0.0f;
			g_player.bJump = false;
		}
		if (g_player.PosY < LIMIT_UP)
		{
			g_player.PosY = LIMIT_UP;
		}


	


	//closesound(sound);
}

void Atari()
{
	if (g_player.atari1 == true)
	{
		//�X�e�[�W�����蔻��
		for (int pp = 0;pp < 4;pp++)
		{
			//�X�e�[�W���[�@�����蔻��
			if ((int)g_player.PosX + pp == 0 || (int)g_player.PosX + pp == 1 || (int)g_player.PosX + pp == 2 || (int)g_player.PosX + pp == 3 || (int)g_player.PosX + pp == 4 || (int)g_player.PosX + pp == 5 || (int)g_player.PosX + pp == 6 || (int)g_player.PosX + pp == 7 || (int)g_player.PosX + pp == 8 || (int)g_player.PosX + pp == 9 || (int)g_player.PosX + pp == 10 || (int)g_player.PosX + pp == 11 || (int)g_player.PosX + pp == 12 || (int)g_player.PosX + pp == 13 || (int)g_player.PosX + pp == 14 || (int)g_player.PosX + pp == 15 || (int)g_player.PosX + pp == 16 || (int)g_player.PosX + pp == 17 || (int)g_player.PosX + pp == 18 || (int)g_player.PosX + pp == 19 || (int)g_player.PosX + pp == 20)
			{

				if ((int)g_player.PosY == 16 || (int)g_player.PosY == 11 || (int)g_player.PosY == 6)
				{
					g_player.PosY = g_player.PosOldY;
					g_player.MoveY = 0.0f;
					g_player.bJump = false;

				}
			}

			if ((int)g_player.PosY == 16 && (int)g_player.PosX + pp == 20)
			{
				g_player.PosX = g_player.PosOldX;
				g_player.MoveY = 0.0f;
				g_player.bJump = false;



			}
			if ((int)g_player.PosY == 11 && (int)g_player.PosX + pp == 20)
			{
				g_player.PosX = g_player.PosOldX;
				g_player.MoveY = 0.0f;
				g_player.bJump = false;

			}
			if ((int)g_player.PosY == 6 && (int)g_player.PosX + pp == 20)
			{
				g_player.PosX = g_player.PosOldX;
				g_player.MoveY = 0.0f;
				g_player.bJump = false;

			}

			//���@�I��


			//�X�e�[�W�����@�����蔻��
			if ((int)g_player.PosX + pp == 29 || (int)g_player.PosX + pp == 30 || (int)g_player.PosX + pp == 31 || (int)g_player.PosX + pp == 32 || (int)g_player.PosX + pp == 33 || (int)g_player.PosX + pp == 34 || (int)g_player.PosX + pp == 35 || (int)g_player.PosX + pp == 36 || (int)g_player.PosX + pp == 37 || (int)g_player.PosX + pp == 38 || (int)g_player.PosX + pp == 39 || (int)g_player.PosX + pp == 40 || (int)g_player.PosX + pp == 41 || (int)g_player.PosX + pp == 42 || (int)g_player.PosX + pp == 43 || (int)g_player.PosX + pp == 44 || (int)g_player.PosX + pp == 45 || (int)g_player.PosX + pp == 46 || (int)g_player.PosX + pp == 47 || (int)g_player.PosX + pp == 48 || (int)g_player.PosX + pp == 49 || (int)g_player.PosX + pp == 50)
			{
				if ((int)g_player.PosY == 16 || (int)g_player.PosY == 11 || (int)g_player.PosY == 6)
				{
					g_player.PosY = g_player.PosOldY;
					g_player.MoveY = 0.0f;
					g_player.bJump = false;
				}
			}
			if ((int)g_player.PosY == 16 && (int)g_player.PosX + pp == 29)
			{
				g_player.PosX = g_player.PosOldX;
				g_player.MoveY = 0.0f;
				g_player.bJump = false;

			}
			if ((int)g_player.PosY == 11 && (int)g_player.PosX + pp == 29)
			{
				g_player.PosX = g_player.PosOldX;
				g_player.MoveY = 0.0f;
				g_player.bJump = false;
			}
			if ((int)g_player.PosY == 6 && (int)g_player.PosX + pp == 29)
			{
				g_player.PosX = g_player.PosOldX;
				g_player.MoveY = 0.0f;
				g_player.bJump = false;
			}


			if ((int)g_player.PosY == 16 && (int)g_player.PosX + pp == 50)
			{
				g_player.PosX = g_player.PosOldX;
				g_player.MoveY = 0.0f;
				g_player.bJump = false;

			}
			if ((int)g_player.PosY == 11 && (int)g_player.PosX + pp == 50)
			{
				g_player.PosX = g_player.PosOldX;
				g_player.MoveY = 0.0f;
				g_player.bJump = false;
			}
			if ((int)g_player.PosY == 6 && (int)g_player.PosX + pp == 50)
			{
				g_player.PosX = g_player.PosOldX;
				g_player.MoveY = 0.0f;
				g_player.bJump = false;
			}


			//���@�I��

			//�X�e�[�W�E�@�����蔻��
			if ((int)g_player.PosX + pp == 58 || (int)g_player.PosX + pp == 59 || (int)g_player.PosX + pp == 60 || (int)g_player.PosX + pp == 61 || (int)g_player.PosX + pp == 62 || (int)g_player.PosX + pp == 63 || (int)g_player.PosX + pp == 64 || (int)g_player.PosX + pp == 65 || (int)g_player.PosX + pp == 66 || (int)g_player.PosX + pp == 67 || (int)g_player.PosX + pp == 68 || (int)g_player.PosX + pp == 69 || (int)g_player.PosX + pp == 70 || (int)g_player.PosX + pp == 71 || (int)g_player.PosX + pp == 72 || (int)g_player.PosX + pp == 73 || (int)g_player.PosX + pp == 74 || (int)g_player.PosX + pp == 75 || (int)g_player.PosX + pp == 76 || (int)g_player.PosX + pp == 77 || (int)g_player.PosX + pp == 78)
			{
				if ((int)g_player.PosY == 16 || (int)g_player.PosY == 11 || (int)g_player.PosY == 6)
				{
					g_player.PosY = g_player.PosOldY;
					g_player.MoveY = 0.0f;
					g_player.bJump = false;
				}
			}

			if ((int)g_player.PosY == 16 && (int)g_player.PosX + pp == 59)
			{
				g_player.PosX = g_player.PosOldX;
				g_player.MoveY = 0.0f;
				g_player.bJump = false;


			}
			if ((int)g_player.PosY == 11 && (int)g_player.PosX + pp == 59)
			{
				g_player.PosX = g_player.PosOldX;
				g_player.MoveY = 0.0f;
				g_player.bJump = false;
			}
			if ((int)g_player.PosY == 6 && (int)g_player.PosX + pp == 59)
			{
				g_player.PosX = g_player.PosOldX;
				g_player.MoveY = 0.0f;
				g_player.bJump = false;
			}

			//�E�@�I��

		}
	}

}




//////////////////////////////////////////////////////////////////////////////
//�֐���	:
//����		:
//�߂�l	:	
//����		:	�`��
//////////////////////////////////////////////////////////////////////////////
void DrawPlayer(void)
{
	//�ߋ��̃v���C���[�̈ʒu������
	if (g_player.bMove == true)
	{
		gotoxy((int)(g_player.PosOldX), (int)(g_player.PosOldY));
		printf(" ");
		gotoxy((int)(g_player.PosOldX+1.0f), (int)(g_player.PosOldY));
		printf(" ");
		
		gotoxy((int)(g_player.PosOldX+2.0f), (int)(g_player.PosOldY));
		printf(" ");
		gotoxy((int)(g_player.PosOldX + 3.0f), (int)(g_player.PosOldY));
		printf(" ");
		
		gotoxy((int)(g_player.PosOldX + 4.0f), (int)(g_player.PosOldY));
		printf(" ");
		
		
	}
	
	textcolor(12);
	gotoxy((int)(g_player.PosX), (int)(g_player.PosY));
	printf("{");
	gotoxy((int)(g_player.PosX + 1.0f), (int)(g_player.PosY));
	printf("^");
	
	gotoxy((int)(g_player.PosX + 2.0f), (int)(g_player.PosY));
	printf("o");
	gotoxy((int)(g_player.PosX + 3.0f), (int)(g_player.PosY));
	printf("^");
	
	gotoxy((int)(g_player.PosX + 4.0f), (int)(g_player.PosY));
	printf("}");
	
	
}


	








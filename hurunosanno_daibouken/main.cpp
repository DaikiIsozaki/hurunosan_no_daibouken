#include "main.h"
#include "player.h"
#include"conioex.h"
#include"field.h"

void Init(void);
void Uninit(void);
void Update(void);
void Draw(void);
void DispFPS(void);
int sound = opensound("FF5 �r�b�O�u���b�a�̎���.mp3");

//#define DEBUG

int g_nCountFPS;				// FPS�J�E���^


void main(void)
{
	playsound(sound, 1);


	// FPS�v�����邽�߂̕ϐ�
	DWORD dwExecLastTime;
	DWORD dwFPSLastTime;
	DWORD dwCurrentTime;
	int nCountFrame;
	
	
	
	setcursortype(NOCURSOR);
	
	

	// FPS�v���ׂ̈̏����ݒ�
	// ����\��ݒ�(�������Ȃ��ƃ^�C�}�̐��x�������Ȃ�̂Őݒ�)
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
		if ((dwCurrentTime - dwFPSLastTime) >= 500)	// 0.5�b���ƂɎ��s(������s����ƃ`�J�`�J����̂�)
		{
			g_nCountFPS = nCountFrame * 1000 / (dwCurrentTime - dwFPSLastTime);
			dwFPSLastTime = dwCurrentTime;
			nCountFrame = 0;
		}

		if ((dwCurrentTime - dwExecLastTime) >= (1000 / 60))// FPS��60�ɂ��邽�߂ɐݒ�
		{
			dwExecLastTime = dwCurrentTime;
			
				//�X�V����
				Update();

				//�`�揈��
				Draw();

#ifdef DEBUG
				// FPS�\��
				DispFPS();
#endif
				
				nCountFrame++;
				gotoxy(1, 1);
				//printf("%d", so / 60000);
			

		}
	} while (!inport(PK_ESC));

	Uninit();

	// ����\��߂�
	timeEndPeriod(1);
	
	
	
	closesound(sound);
}

//=============================================================================
// ����������
//=============================================================================
void Init(void)
{
	// �v���C���[�̏���������
	InitPlayer();
	// �n�ʂ̏���������
	//InitField0();
	InitField0();
	
}

//=============================================================================
// �I������
//=============================================================================
void Uninit(void)
{
	// �v���C���[�̏I������
	UninitPlayer();
	// �n�ʂ̏I������
	UninitField();
}

//=============================================================================
// �X�V����
//=============================================================================
void Update(void)
{
	// �v���C���[�̍X�V����
	UpdatePlayer();
	// �n�ʂ̍X�V����
	UpdateField();
	Atari();
	
}

//=============================================================================
// �`�揈��
//=============================================================================
void Draw(void)
{
	// �v���C���[�̕`�揈��
	DrawPlayer();
	// �n�ʂ̕`�揈��
	DrawField();
	
}

#ifdef DEBUG
//=============================================================================
// FPS�\��
//=============================================================================
void DispFPS(void)
{
	// �F�ݒ�

	textcolor(WHITE);

	gotoxy(1, 1);
	printf("FPS:%d", g_nCountFPS);
	gotoxy(1, 3);
	

	
}
#endif

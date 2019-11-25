#include "DxLib.h"
#include "Core.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	
	LONGLONG Time=0;
	Core core(Time) ;
	ChangeWindowMode(1);
	SetBackgroundColor(0, 128, 128);
	// ��ʃ��[�h�̐ݒ�
	SetGraphMode(640, 480, 16);
	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		// �G���[���N�����璼���ɏI��
		return -1;
	}

	// �`���𗠉�ʂɃZ�b�g
    SetDrawScreen(DX_SCREEN_BACK);
	core.Initialize();
	ScreenFlip();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		core.Run();
	}
}

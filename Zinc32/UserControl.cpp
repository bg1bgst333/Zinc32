// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "UserControl.h"	// CUserControl

// �R���X�g���N�^CUserControl
CUserControl::CUserControl() : CWindow(){

}

// �f�X�g���N�^~CUserControl
CUserControl::~CUserControl(){

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.
BOOL CUserControl::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName){

	// �E�B���h�E�N���X�̓o�^.
	return CWindow::RegisterClass(hInstance, lpctszClassName);	// CWindow::RegisterClass�œo�^.

}

// �E�B���h�E�쐬�֐�Create.
BOOL CUserControl::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�̍쐬.
	return CWindow::Create(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ō쐬.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CUserControl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ��ɃE�B���h�E�쐬�ɐ���������̂Ƃ���.
	return 0;	// 0��Ԃ���, �E�B���h�E�쐬�ɐ��������Ƃ������ƂɂȂ�.

}

// �E�B���h�E���j�����ꂽ��.
void CUserControl::OnDestroy(){

	// �e�N���X��OnDestroy���Ă�.
	CWindow::OnDestroy();	// CWindow::OnDestroy���Ă�.

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
void CUserControl::OnSize(UINT nType, int cx, int cy){

}
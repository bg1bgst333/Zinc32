// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "WebBrowser.h"	// CWebBrowser

// �R���X�g���N�^CWebBrowser
CWebBrowser::CWebBrowser() : CUserControl(){

}

// �f�X�g���N�^~CWebBrowser
CWebBrowser::~CWebBrowser(){

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.
BOOL CWebBrowser::RegisterClass(HINSTANCE hInstance){

	// �E�B���h�E�N���X�̓o�^.
	return CUserControl::RegisterClass(hInstance, _T("CWebBrowser"));	// CUserControl::RegisterClass�œo�^.

}

// �E�B���h�E�쐬�֐�Create.
BOOL CWebBrowser::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�̍쐬.
	return CUserControl::Create(_T("CWebBrowser"), lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ō쐬.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CWebBrowser::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ��ɃE�B���h�E�쐬�ɐ���������̂Ƃ���.
	return 0;	// 0��Ԃ���, �E�B���h�E�쐬�ɐ��������Ƃ������ƂɂȂ�.

}

// �E�B���h�E���j�����ꂽ��.
void CWebBrowser::OnDestroy(){

	// �e�N���X��OnDestroy���Ă�.
	CUserControl::OnDestroy();	// CUserControl::OnDestroy���Ă�.

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
void CWebBrowser::OnSize(UINT nType, int cx, int cy){

}
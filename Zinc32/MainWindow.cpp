// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainWindow.h"	// CMainWindow
#include "resource.h"		// ���\�[�X

// �R���X�g���N�^CMainWindow()
CMainWindow::CMainWindow() : CWindow(){

	// �����o�̏�����.
	m_pEdit = NULL;	// m_pEdit��NULL�ŏ�����.
	m_pButton = NULL;	// m_pButton��NULL�ŏ�����.

}

// �f�X�g���N�^~CMainWindow()
CMainWindow::~CMainWindow(){

	// �����o�̏I������.
	if (m_pEdit != NULL){	// m_pEdit��NULL�łȂ����.
		DestroyWindow(m_pEdit->m_hWnd);	// DestroyWindow��m_pEdit->m_hWnd��j��.
		delete m_pEdit;	// delete��m_pEdit�����.
		m_pEdit = NULL;	// m_pStatic��NULL���Z�b�g.
	}
	if (m_pButton != NULL){	// m_pButton��NULL�łȂ����.
		DestroyWindow(m_pButton->m_hWnd);	// DestroyWindow��m_pStatic->m_hWnd��j��.
		delete m_pButton;	// delete��m_pButton�����.
		m_pButton = NULL;	// m_pButton��NULL���Z�b�g.
	}

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance){

	// �E�B���h�E�v���V�[�W���ɂ�CWindow::StaticWndowProc, ���j���[�͂Ȃ�(NULL)�Ƃ���.((LPCTSTR)�ŃL���X�g���Ȃ��ƃI�[�o�[���[�h���B���ɂȂ�.)
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"), (LPCTSTR)NULL);	// CWindow::RegisterClass�œo�^.

}

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)

	// �E�B���h�E�N���X����"CMainWindow".
	return CWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ɃE�B���h�E�N���X��"CMainWindow"���w��.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// �G�f�B�b�g�R���g���[���I�u�W�F�N�g�̍쐬
	m_pEdit = new CEdit();	// CEdit�I�u�W�F�N�g�̍쐬.

	// �G�f�B�b�g�R���g���[���̃E�B���h�E�쐬.
	m_pEdit->Create(_T(""), WS_BORDER | ES_WANTRETURN, 0, 0, 640, 24, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// m_pEdit->Create�ō쐬.

	// �{�^���R���g���[���I�u�W�F�N�g�̍쐬
	m_pButton = new CButton();	// CButton�I�u�W�F�N�g�̍쐬.

	// �{�^���R���g���[���̃E�B���h�E�쐬.
	m_pButton->Create(_T("���[�h"), BS_PUSHBUTTON, 640, 0, 80, 24, hwnd, (HMENU)(WM_APP + 2), lpCreateStruct->hInstance);	// m_pButton->Create�ō쐬.

	// ��ɃE�B���h�E�쐬�ɐ���������̂Ƃ���.
	return 0;	// 0��Ԃ���, �E�B���h�E�쐬�ɐ��������Ƃ������ƂɂȂ�.

}

// �E�B���h�E���j�����ꂽ��.
void CMainWindow::OnDestroy(){

	// �q�E�B���h�E�I�u�W�F�N�g�̔j��.
	if (m_pEdit != NULL){	// m_pEdit��NULL�łȂ����.
		DestroyWindow(m_pEdit->m_hWnd);	// DestroyWindow��m_pEdit->m_hWnd��j��.
		delete m_pEdit;	// delete��m_pEdit�����.
		m_pEdit = NULL;	// m_pEdit��NULL���Z�b�g.
	}
	if (m_pButton != NULL){	// m_pButton��NULL�łȂ����.
		DestroyWindow(m_pButton->m_hWnd);	// DestroyWindow��m_pStatic->m_hWnd��j��.
		delete m_pButton;	// delete��m_pButton�����.
		m_pButton = NULL;	// m_pButton��NULL���Z�b�g.
	}
	// �e�E�B���h�E��OnDestroy���Ă�.
	CWindow::OnDestroy();	// CWindow::OnDestroy���Ă�.

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
void CMainWindow::OnSize(UINT nType, int cx, int cy){

	// �E�B���h�E�̃T�C�Y�ύX.
	if (m_pEdit != NULL){
		MoveWindow(m_pEdit->m_hWnd, 0, 0, cx - 80, 24, TRUE);	// MoveWindow��m_pEdit->m_hWnd�̃T�C�Y��ύX.
	}
	if (m_pButton != NULL){
		MoveWindow(m_pButton->m_hWnd, cx - 80, 0, 80, 24, TRUE);	// MoveWindow��m_pButton->m_hWnd�̃T�C�Y��ύX.
	}

}

// �R�}���h������������.
BOOL CMainWindow::OnCommand(WPARAM wParam, LPARAM lParam){

	// �������Ă��Ȃ��̂�FALSE.
	return FALSE;	// return��FALSE��Ԃ�.

}
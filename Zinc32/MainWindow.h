// ��d�C���N���[�h�h�~
#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <string>	// std::string
// �Ǝ��̃w�b�_
#include "Edit.h"	// CEdit
#include "Button.h"	// CButton
#include "Window.h"	// CWindow

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// ���C���E�B���h�E�N���XCMainWindow
class CMainWindow : public CWindow{

	// public�����o
	public:

		// public�����o�ϐ�
		CEdit *m_pEdit;	// CEdit�I�u�W�F�N�g�|�C���^m_pEdit.
		CButton *m_pButton;	// CButton�I�u�W�F�N�g�|�C���^m_pButton.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMainWindow();	// �R���X�g���N�^CMainWindow()
		virtual ~CMainWindow();	// �f�X�g���N�^~CMainWindow()
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�̍쐬���J�n���ꂽ��.
		virtual void OnDestroy();	// �E�B���h�E���j�����ꂽ��.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
		virtual int OnLoad(WPARAM wParam, LPARAM lParam);	// "���[�h"�{�^���������ꂽ���̃n���h��.

};

#endif
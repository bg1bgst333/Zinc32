// ��d�C���N���[�h�h�~
#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <string>	// std::string
// �Ǝ��̃w�b�_
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
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// �R�}���h������������.

};

#endif
// ��d�C���N���[�h�h�~
#ifndef __WINDOW_H__
#define __WINDOW_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI
#include <map>	// std::map

// �E�B���h�E�N���XCWindow
class CWindow{

	// public�����o
	public:

		// public�����o�ϐ�
		HWND m_hWnd;	// HWND�^�E�B���h�E�n���h��m_hWnd.
		// static�����o�ϐ�
		static std::map<HWND, CWindow *>m_mapWindowMap;	// �E�B���h�E�n���h�����L�[, CWindow�I�u�W�F�N�g�|�C���^��l�Ƃ���}�b�vm_mapWindowMap.

		// public�����o�֐�
		// �R���X�g���N�^
		CWindow();	// �R���X�g���N�^CWindow()
		~CWindow();	// �f�X�g���N�^~CWindow()

		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�N���X���ȗ��o�[�W����.)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, WNDPROC lpfnWndProc);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�v���V�[�W���w��o�[�W����.)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, LPCTSTR lpszMenuName);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�v���V�[�W���ȗ�, ���j���[���w��o�[�W����.)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, WNDPROC lpfnWndProc, LPCTSTR lpszMenuName);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.(���j���[���w��o�[�W����.)
		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �X�^�e�B�b�N�E�B���h�E�v���V�[�W��StaticWindowProc.
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.
		virtual BOOL ShowWindow(int nCmdShow);	// �E�B���h�E�\���֐�ShowWindow.
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �_�C�i�~�b�N�E�B���h�E�v���V�[�W��DynamicWindowProc.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�̍쐬���J�n���ꂽ��.
		virtual void OnDestroy();	// �E�B���h�E���j�����ꂽ��.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// �R�}���h������������.

};

#endif
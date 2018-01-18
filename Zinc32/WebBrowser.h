// ��d�C���N���[�h�h�~
#ifndef __WEB_BROWSER_H__
#define __WEB_BROWSER_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "UserControl.h"	// CUserControl
#include "WebBrowserHost.h"	// CWebBrowserHost

// �E�F�u�u���E�U�N���XCWebBrowser
class CWebBrowser : public CUserControl{

	// private�����o
	public:

		// private�����o�ϐ�
		CWebBrowserHost *m_pWebBrowserHost;	// CWebBrowserHost�I�u�W�F�N�g�|�C���^m_pWebBrowserHost.

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CWebBrowser();	// �R���X�g���N�^CWebBrowser
		virtual ~CWebBrowser();	// �f�X�g���N�^~CWebBrowser
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.
		void Attach(CWebBrowserHost *pWebBrowserHost);	// WebBrowserHost�̃Z�b�g�ƃA�^�b�`.
		void Navigate(LPCTSTR lpctszUrl);	// URL�̃��[�h.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�̍쐬���J�n���ꂽ��.
		virtual void OnDestroy();	// �E�B���h�E���j�����ꂽ��.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.

};

#endif
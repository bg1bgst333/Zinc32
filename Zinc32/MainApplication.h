// ��d�C���N���[�h�h�~
#ifndef __MAIN_APPLICATION_H__
#define __MAIN_APPLICATION_H_

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Application.h"	// CApplication
#include "WebBrowserHost.h"	// CWebBrowserHost

// ���C���A�v���P�[�V�����N���XCMainApplication
class CMainApplication : public CApplication{

	// public�����o
	public:

		// public�����o�ϐ�
		CWebBrowserHost *m_pWebBrowserHost;	// CWebBrowserHost�I�u�W�F�N�g�|�C���^m_pWebBrowserHost.

		// public�����o�֐�
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// �C���X�^���X�������֐�InitInstance.
		virtual int ExitInstance();	// �I�������֐�ExitInstance.

};

#endif
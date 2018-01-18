// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"	// CMainWindow

// �C���X�^���X�������֐�InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// OLE�̏�����.
	OleInitialize(NULL);	// OleInitialize��OLE�̏�����.

	// CWebBrowserHost�̐���.
	m_pWebBrowserHost = new CWebBrowserHost();	// CWebBrowserHost�I�u�W�F�N�g�|�C���^��m_pWebBrowserHost�Ɋi�[.

	// �E�B���h�E�N���X�̓o�^.
	CMainWindow::RegisterClass(hInstance);	// CMainWindow::RegisterClass�ŃE�B���h�E�N���X"CMainWindow"��o�^.
	CWebBrowser::RegisterClass(hInstance);	// CWebBrowser::RegisterCkass�ŃE�B���h�E�N���X"CWebBrowser"��o�^.

	// CMainWindow�I�u�W�F�N�g�̍쐬.
	m_pMainWnd = new CMainWindow();	// CMainWindow�I�u�W�F�N�g���쐬��, m_pMainWnd�Ɋi�[.

	// m_pMainWnd��m_pWebBrowserHost���Z�b�g.
	((CMainWindow *)m_pMainWnd)->SetWebBrowserHost(m_pWebBrowserHost);	// m_pMainWnd->SetWebBrowserHost��m_pWebBrowserHost���Z�b�g.

	// �E�B���h�E�̍쐬.
	if (!m_pMainWnd->Create(_T("Zinc"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_pMainWnd->Create�ŃE�B���h�E�쐬��, ���s�����ꍇ.

		// �G���[����
		return FALSE;	// return��FALSE��Ԃ��Ĉُ�I��.

	}

	// �E�B���h�E�̕\��.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindow�ŕ\��.

	// TRUE��Ԃ�.
	return TRUE;	// return��TRUE��Ԃ�.

}

// �I�������֐�ExitInstance.
int CMainApplication::ExitInstance(){

	// ���C���E�B���h�E�̔j��
	if (m_pMainWnd != NULL){	// m_pMainWnd��NULL�łȂ���.

		// �j������.
		delete m_pMainWnd;	// delete��m_pMainWnd��j��.
		m_pMainWnd = NULL;	// m_pMainWnd��NULL���Z�b�g.

	}

	// CWebBrowserHost�̔j��
	if (m_pWebBrowserHost != NULL){	// m_pWebBrowserHost��NULL�łȂ���.
		
		// �j������.
		delete m_pWebBrowserHost;	// delete��m_pWebBrowserHost��j��.
		m_pWebBrowserHost = NULL;	// m_pWebBrowserHost��NULL���Z�b�g.

	}

	// OLE�̏I������.
	OleUninitialize();	// OleUninitialize��OLE�̏I������.

	// ����͏��0��Ԃ�.
	return 0;	// return��0��Ԃ�.

}
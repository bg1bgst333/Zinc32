// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "WebBrowser.h"	// CWebBrowser

// �R���X�g���N�^CWebBrowser
CWebBrowser::CWebBrowser() : CUserControl(){

	// �����o�̏�����.
	m_pWebBrowserHost = NULL;	// m_pWebBrowserHost��NULL���Z�b�g.

}

// �f�X�g���N�^~CWebBrowser
CWebBrowser::~CWebBrowser(){

	// �����o�̏I������.
	m_pWebBrowserHost = NULL;	// m_pWebBrowserHost��NULL���Z�b�g.

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

// WebBrowserHost�̃Z�b�g�ƃA�^�b�`.
void CWebBrowser::Attach(CWebBrowserHost *pWebBrowserHost){

	// �����o�ɃZ�b�g.
	m_pWebBrowserHost = pWebBrowserHost;	// m_pWebBrowserHost��pWebBrowserHost���Z�b�g.

	// �A�^�b�`.
	if (m_hWnd != NULL){	// m_hWnd��NULL�łȂ���.
		m_pWebBrowserHost->Attach(m_hWnd);	// m_pWebBrowserHost->Attach��m_hWnd���A�^�b�`.
	}

}

// URL�̃��[�h.
void CWebBrowser::Navigate(LPCTSTR lpctszUrl){

	// �w���URL�����[�h.
	m_pWebBrowserHost->Navigate(lpctszUrl);	// m_pWebBrowserHost->Navigate��lpctszUrl�����[�h.

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

	// �ϐ��̏�����.
	RECT rc = {0, 0, cx, cy};	// rc��cx, cy�̑傫���ŏ�����.
	IOleInPlaceObject *pOleInPlaceObject = NULL;	// pOleInPlaceObject��NULL�ŏ�����.
	
	// �T�C�Y�ύX.
	if (m_pWebBrowserHost != NULL && m_pWebBrowserHost->m_pWebBrowser != NULL){	// m_pWebBrowserHost��NULL�łȂ�, ����, m_pWebBrowserHost->m_pWebBrowser��NULL�łȂ��ꍇ.
		m_pWebBrowserHost->m_pWebBrowser->QueryInterface(IID_PPV_ARGS(&pOleInPlaceObject));	// QueryInterface��pOleInPlaceObject���擾.
		pOleInPlaceObject->SetObjectRects(&rc, &rc);	// SetObjectRects��rc���Z�b�g.
		pOleInPlaceObject->Release();	// Release�Ń����[�X.
	}

}
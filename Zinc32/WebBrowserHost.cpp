// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "WebBrowserHost.h"	// CWebBrowserHost

// �R���X�g���N�^CWebBrowserHost()
CWebBrowserHost::CWebBrowserHost(){

	// �����o�̏�����.
	m_lRef = 1;	// m_lRef��1�ŏ�����.
	m_hWnd = NULL;	// m_hWnd��NULL�ŏ�����.
	m_pWebBrowser = NULL;	// m_pWebBrowser��NULL�ŏ�����.

}

// �f�X�g���N�^~CWebBrowserHost()
CWebBrowserHost::~CWebBrowserHost(){

}

// QieryInterface.
STDMETHODIMP CWebBrowserHost::QueryInterface(REFIID riid, void **ppvObject){

	// �Q�Ɛ��NULL�ŏ�����.
	*ppvObject = NULL;	// ppvObject�Q�Ɛ��NULL���Z�b�g.

	// IUnknown, IOleClientSite�̏ꍇ, �܂���IID_IOleWindow, IOleInPlaceSite�̏ꍇ.
	if (IsEqualIID(riid, IID_IUnknown) || IsEqualIID(riid, IID_IOleClientSite)){	// IsEqualIID��IID_IUnknown�܂���IID_IOleClientSite�̎�.
		*ppvObject = static_cast<IOleClientSite *>(this);	// this��IOleClientSite�ɃL���X�g.
	}
	else if (IsEqualIID(riid, IID_IOleWindow) || IsEqualIID(riid, IID_IOleInPlaceSite)){	// IsEqualIID��IID_IOleWindow�܂���IID_IOleInPlaceSite�̎�.
		*ppvObject = static_cast<IOleInPlaceSite *>(this);	// this��IOleOnPlaceSite�ɃL���X�g.
	}
	else{	// ����ȊO.
		return E_NOINTERFACE;	// E_NOINTERFACE��Ԃ�.
	}
	AddRef();	// �Q�ƃJ�E���^��.
	return S_OK;	// S_OK��Ԃ�.

}

// AddRef.
STDMETHODIMP_(ULONG) CWebBrowserHost::AddRef(){
	return InterlockedIncrement(&m_lRef);	// InterlockedIncrement�ŎQ�ƃJ�E���^��.
}

// Release.
STDMETHODIMP_(ULONG)  CWebBrowserHost::Release(){
	return InterlockedDecrement(&m_lRef);	// InterlockedDecrement�ŎQ�ƃJ�E���^��.
}

// GetContainer.
STDMETHODIMP CWebBrowserHost::GetContainer(IOleContainer **ppContainer){

	// �Q�Ɛ��NULL�ŏ�����.
	*ppContainer = NULL;	// ppContainer�Q�Ɛ��NULL���Z�b�g.

	// E_NOINTERFACE��Ԃ�.
	return E_NOINTERFACE;	// return��E_NOINTERFACE��Ԃ�.

}

// GetMoniker.
STDMETHODIMP CWebBrowserHost::GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, IMoniker **ppmk){

	// E_NOTIMPL��Ԃ�.
	return E_NOTIMPL;	// return��E_NOTIMPL��Ԃ�.

}

// OnShowWindow.
STDMETHODIMP CWebBrowserHost::OnShowWindow(BOOL fShow){

	// S_OK��Ԃ�.
	return S_OK;	// return��S_OK��Ԃ�.

}

// RequestNewObjectLayout.
STDMETHODIMP CWebBrowserHost::RequestNewObjectLayout(){

	// E_NOTIMPL��Ԃ�.
	return E_NOTIMPL;	// return��E_NOTIMPL��Ԃ�.

}

// SaveObject.
STDMETHODIMP CWebBrowserHost::SaveObject(){

	// E_NOTIMPL��Ԃ�.
	return E_NOTIMPL;	// return��E_NOTIMPL��Ԃ�.

}

// ShowObject.
STDMETHODIMP CWebBrowserHost::ShowObject(){

	// S_OK��Ԃ�.
	return S_OK;	// return��S_OK��Ԃ�.

}

// CanInPlaceActivate.
STDMETHODIMP CWebBrowserHost::CanInPlaceActivate(){

	// S_OK��Ԃ�.
	return S_OK;	// return��S_OK��Ԃ�.

}

// DeactivateAndUndo.
STDMETHODIMP CWebBrowserHost::DeactivateAndUndo(){

	// E_NOTIMPL��Ԃ�.
	return E_NOTIMPL;	// return��E_NOTIMPL��Ԃ�.

}

// DiscardUndoState.
STDMETHODIMP CWebBrowserHost::DiscardUndoState(){

	// E_NOTIMPL��Ԃ�.
	return E_NOTIMPL;	// return��E_NOTIMPL��Ԃ�.

}

// GetWindowContext.
STDMETHODIMP CWebBrowserHost::GetWindowContext(IOleInPlaceFrame **ppFrame, IOleInPlaceUIWindow **ppDoc, LPRECT lprcPosRect, LPRECT lprcClipRect, LPOLEINPLACEFRAMEINFO lpFrameInfo){

	// �Q�Ɛ��NULL�ŏ�����.
	*ppFrame = NULL;	// ppFrame�Q�Ɛ��NULL���Z�b�g.
	*ppDoc = NULL;	// ppDoc�Q�Ɛ��NULL���Z�b�g.

	// �N���C�A���g�̈�̎擾.
	GetClientRect(m_hWnd, lprcPosRect);	// GetClientRect�Ŏ擾�����̈��lprcPosRect�Ɋi�[.
	GetClientRect(m_hWnd, lprcClipRect);	// GetClientRect�Ŏ擾�����̈��lprcClipRect�Ɋi�[.

	// S_OK��Ԃ�.
	return S_OK;	// return��S_OK��Ԃ�.

}

// OnInPlaceActivate.
STDMETHODIMP CWebBrowserHost::OnInPlaceActivate(){

	// S_OK��Ԃ�.
	return S_OK;	// return��S_OK��Ԃ�.

}

// OnInPlaceDeactivate.
STDMETHODIMP CWebBrowserHost::OnInPlaceDeactivate(){

	// E_NOTIMPL��Ԃ�.
	return E_NOTIMPL;	// return��E_NOTIMPL��Ԃ�.

}

// OnPosRectChange.
STDMETHODIMP CWebBrowserHost::OnPosRectChange(LPCRECT lprcPosRect){

	// S_OK��Ԃ�.
	return S_OK;	// return��S_OK��Ԃ�.

}

// OnUIActivate.
STDMETHODIMP CWebBrowserHost::OnUIActivate(){

	// S_OK��Ԃ�.
	return S_OK;	// return��S_OK��Ԃ�.

}

// OnUIDeactivate.
STDMETHODIMP CWebBrowserHost::OnUIDeactivate(BOOL fUndoable){

	// E_NOTIMPL��Ԃ�.
	return E_NOTIMPL;	// return��E_NOTIMPL��Ԃ�.

}

// Scroll.
STDMETHODIMP CWebBrowserHost::Scroll(SIZE scrollExtant){

	// E_NOTIMPL��Ԃ�.
	return E_NOTIMPL;	// return��E_NOTIMPL��Ԃ�.

}

//  ContextSensitiveHelp.
STDMETHODIMP CWebBrowserHost::ContextSensitiveHelp(BOOL fEnterMode){

	// E_NOTIMPL��Ԃ�.
	return E_NOTIMPL;	// return��E_NOTIMPL��Ԃ�.

}

// GetWindow.
STDMETHODIMP CWebBrowserHost::GetWindow(HWND *phwnd){

	// �E�B���h�E�n���h���̃Z�b�g.
	*phwnd = m_hWnd;	// *phwnd��m_hWnd���Z�b�g.

	// S_OK��Ԃ�.
	return S_OK;	// return��S_OK��Ԃ�.

}

// ���̃I�u�W�F�N�g�ƃE�B���h�E��R�t����Attach.
BOOL CWebBrowserHost::Attach(HWND hWnd){

	// �ϐ��̏�����
	IOleObject *pOleObject = NULL;	// pOleObject��NULL�ŏ�����.
	HRESULT hr = S_FALSE;	// hr��S_FALSE�ɏ�����.
	MSG msg = {0};	// msg��{0}�ŏ�����.
	RECT rc = {0};	// RECT��{0}�ŏ�����.
	
	// �����o�ɃZ�b�g.
	m_hWnd = hWnd;	// m_hWnd��hWnd���Z�b�g.

	// IWebBrowser2�̃C���X�^���X����.
	hr = CoCreateInstance(CLSID_WebBrowser, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pWebBrowser));	// CoCreateInstance�ŃC���X�^���X����.
	if (FAILED(hr)){	// FAILED�Ȃ�.

		// FALSE.
		return FALSE;	// FALSE��Ԃ�.

	}

	// SetClientSite.
	m_pWebBrowser->QueryInterface(IID_PPV_ARGS(&pOleObject));	// QueryInterface��pOleObject�擾.
	pOleObject->SetClientSite(static_cast<IOleClientSite *>(this));	// pOleObject->SetClientSite��this���w��.

	// DoVerb.
	SetRectEmpty(&rc);	// SetRectEmpty��rc���w��.
	hr = pOleObject->DoVerb(OLEIVERB_INPLACEACTIVATE, &msg, static_cast<IOleClientSite *>(this), 0, m_hWnd, &rc);	// pOleObject->DoVerb��this��m_hWnd���w��.
	if (FAILED(hr)){	// FAILED�Ȃ�.
		pOleObject->Release();	// pOleObject->Release�Ń����[�X.
		m_pWebBrowser->Release();	// m_pWebBrowser->Release�Ń����[�X.
		m_pWebBrowser = NULL;	// m_pWebBrowser��NULL���Z�b�g.
		return FALSE;	// FALSE��Ԃ�.
	}

	// pOleObject�̃����[�X.
	pOleObject->Release();	// pOleObject->Release�Ń����[�X.

	// TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �w���URL�����[�h.
void CWebBrowserHost::Navigate(LPCTSTR lpctszUrl){

	// �ϐ��̐錾
	VARIANT varFlags, varTargetFrameName, varPostData, varHeaders;	// VARIANT�ϐ�.
	BSTR bszUrl;	// URL���w��bszUrl

	// Navigate.
	bszUrl = SysAllocString(lpctszUrl);	// SysAllocString��lpctszUrl����BSTR��bszUrl���m��.
	VariantInit(&varFlags);	// VariantInit��varFlags��������.
	VariantInit(&varTargetFrameName);	// VariantInit��varTargetFrameName��������.
	VariantInit(&varPostData);	// VariantInit��varPostData��������.
	VariantInit(&varHeaders);	// VariantInit��varHeaders��������.
	m_pWebBrowser->Navigate(bszUrl, &varFlags, &varTargetFrameName, &varPostData, &varHeaders);	// m_pWebBrowser->Navigate��bszUrl��Web�y�[�W�����[�h.
	SysFreeString(bszUrl);	// SysFreeString��bszUrl�̉��.

}
// ヘッダのインクルード
// 独自のヘッダ
#include "WebBrowserHost.h"	// CWebBrowserHost

// コンストラクタCWebBrowserHost()
CWebBrowserHost::CWebBrowserHost(){

	// メンバの初期化.
	m_lRef = 1;	// m_lRefを1で初期化.
	m_hWnd = NULL;	// m_hWndをNULLで初期化.
	m_pWebBrowser = NULL;	// m_pWebBrowserをNULLで初期化.

}

// デストラクタ~CWebBrowserHost()
CWebBrowserHost::~CWebBrowserHost(){

}

// QieryInterface.
STDMETHODIMP CWebBrowserHost::QueryInterface(REFIID riid, void **ppvObject){

	// 参照先をNULLで初期化.
	*ppvObject = NULL;	// ppvObject参照先にNULLをセット.

	// IUnknown, IOleClientSiteの場合, またはIID_IOleWindow, IOleInPlaceSiteの場合.
	if (IsEqualIID(riid, IID_IUnknown) || IsEqualIID(riid, IID_IOleClientSite)){	// IsEqualIIDでIID_IUnknownまたはIID_IOleClientSiteの時.
		*ppvObject = static_cast<IOleClientSite *>(this);	// thisをIOleClientSiteにキャスト.
	}
	else if (IsEqualIID(riid, IID_IOleWindow) || IsEqualIID(riid, IID_IOleInPlaceSite)){	// IsEqualIIDでIID_IOleWindowまたはIID_IOleInPlaceSiteの時.
		*ppvObject = static_cast<IOleInPlaceSite *>(this);	// thisをIOleOnPlaceSiteにキャスト.
	}
	else{	// それ以外.
		return E_NOINTERFACE;	// E_NOINTERFACEを返す.
	}
	AddRef();	// 参照カウンタ増.
	return S_OK;	// S_OKを返す.

}

// AddRef.
STDMETHODIMP_(ULONG) CWebBrowserHost::AddRef(){
	return InterlockedIncrement(&m_lRef);	// InterlockedIncrementで参照カウンタ増.
}

// Release.
STDMETHODIMP_(ULONG)  CWebBrowserHost::Release(){
	return InterlockedDecrement(&m_lRef);	// InterlockedDecrementで参照カウンタ減.
}

// GetContainer.
STDMETHODIMP CWebBrowserHost::GetContainer(IOleContainer **ppContainer){

	// 参照先をNULLで初期化.
	*ppContainer = NULL;	// ppContainer参照先にNULLをセット.

	// E_NOINTERFACEを返す.
	return E_NOINTERFACE;	// returnでE_NOINTERFACEを返す.

}

// GetMoniker.
STDMETHODIMP CWebBrowserHost::GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, IMoniker **ppmk){

	// E_NOTIMPLを返す.
	return E_NOTIMPL;	// returnでE_NOTIMPLを返す.

}

// OnShowWindow.
STDMETHODIMP CWebBrowserHost::OnShowWindow(BOOL fShow){

	// S_OKを返す.
	return S_OK;	// returnでS_OKを返す.

}

// RequestNewObjectLayout.
STDMETHODIMP CWebBrowserHost::RequestNewObjectLayout(){

	// E_NOTIMPLを返す.
	return E_NOTIMPL;	// returnでE_NOTIMPLを返す.

}

// SaveObject.
STDMETHODIMP CWebBrowserHost::SaveObject(){

	// E_NOTIMPLを返す.
	return E_NOTIMPL;	// returnでE_NOTIMPLを返す.

}

// ShowObject.
STDMETHODIMP CWebBrowserHost::ShowObject(){

	// S_OKを返す.
	return S_OK;	// returnでS_OKを返す.

}

// CanInPlaceActivate.
STDMETHODIMP CWebBrowserHost::CanInPlaceActivate(){

	// S_OKを返す.
	return S_OK;	// returnでS_OKを返す.

}

// DeactivateAndUndo.
STDMETHODIMP CWebBrowserHost::DeactivateAndUndo(){

	// E_NOTIMPLを返す.
	return E_NOTIMPL;	// returnでE_NOTIMPLを返す.

}

// DiscardUndoState.
STDMETHODIMP CWebBrowserHost::DiscardUndoState(){

	// E_NOTIMPLを返す.
	return E_NOTIMPL;	// returnでE_NOTIMPLを返す.

}

// GetWindowContext.
STDMETHODIMP CWebBrowserHost::GetWindowContext(IOleInPlaceFrame **ppFrame, IOleInPlaceUIWindow **ppDoc, LPRECT lprcPosRect, LPRECT lprcClipRect, LPOLEINPLACEFRAMEINFO lpFrameInfo){

	// 参照先をNULLで初期化.
	*ppFrame = NULL;	// ppFrame参照先にNULLをセット.
	*ppDoc = NULL;	// ppDoc参照先にNULLをセット.

	// クライアント領域の取得.
	GetClientRect(m_hWnd, lprcPosRect);	// GetClientRectで取得した領域をlprcPosRectに格納.
	GetClientRect(m_hWnd, lprcClipRect);	// GetClientRectで取得した領域をlprcClipRectに格納.

	// S_OKを返す.
	return S_OK;	// returnでS_OKを返す.

}

// OnInPlaceActivate.
STDMETHODIMP CWebBrowserHost::OnInPlaceActivate(){

	// S_OKを返す.
	return S_OK;	// returnでS_OKを返す.

}

// OnInPlaceDeactivate.
STDMETHODIMP CWebBrowserHost::OnInPlaceDeactivate(){

	// E_NOTIMPLを返す.
	return E_NOTIMPL;	// returnでE_NOTIMPLを返す.

}

// OnPosRectChange.
STDMETHODIMP CWebBrowserHost::OnPosRectChange(LPCRECT lprcPosRect){

	// S_OKを返す.
	return S_OK;	// returnでS_OKを返す.

}

// OnUIActivate.
STDMETHODIMP CWebBrowserHost::OnUIActivate(){

	// S_OKを返す.
	return S_OK;	// returnでS_OKを返す.

}

// OnUIDeactivate.
STDMETHODIMP CWebBrowserHost::OnUIDeactivate(BOOL fUndoable){

	// E_NOTIMPLを返す.
	return E_NOTIMPL;	// returnでE_NOTIMPLを返す.

}

// Scroll.
STDMETHODIMP CWebBrowserHost::Scroll(SIZE scrollExtant){

	// E_NOTIMPLを返す.
	return E_NOTIMPL;	// returnでE_NOTIMPLを返す.

}

//  ContextSensitiveHelp.
STDMETHODIMP CWebBrowserHost::ContextSensitiveHelp(BOOL fEnterMode){

	// E_NOTIMPLを返す.
	return E_NOTIMPL;	// returnでE_NOTIMPLを返す.

}

// GetWindow.
STDMETHODIMP CWebBrowserHost::GetWindow(HWND *phwnd){

	// ウィンドウハンドルのセット.
	*phwnd = m_hWnd;	// *phwndにm_hWndをセット.

	// S_OKを返す.
	return S_OK;	// returnでS_OKを返す.

}

// このオブジェクトとウィンドウを紐付けるAttach.
BOOL CWebBrowserHost::Attach(HWND hWnd){

	// 変数の初期化
	IOleObject *pOleObject = NULL;	// pOleObjectをNULLで初期化.
	HRESULT hr = S_FALSE;	// hrをS_FALSEに初期化.
	MSG msg = {0};	// msgを{0}で初期化.
	RECT rc = {0};	// RECTを{0}で初期化.
	
	// メンバにセット.
	m_hWnd = hWnd;	// m_hWndにhWndをセット.

	// IWebBrowser2のインスタンス生成.
	hr = CoCreateInstance(CLSID_WebBrowser, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pWebBrowser));	// CoCreateInstanceでインスタンス生成.
	if (FAILED(hr)){	// FAILEDなら.

		// FALSE.
		return FALSE;	// FALSEを返す.

	}

	// SetClientSite.
	m_pWebBrowser->QueryInterface(IID_PPV_ARGS(&pOleObject));	// QueryInterfaceでpOleObject取得.
	pOleObject->SetClientSite(static_cast<IOleClientSite *>(this));	// pOleObject->SetClientSiteにthisを指定.

	// DoVerb.
	SetRectEmpty(&rc);	// SetRectEmptyにrcを指定.
	hr = pOleObject->DoVerb(OLEIVERB_INPLACEACTIVATE, &msg, static_cast<IOleClientSite *>(this), 0, m_hWnd, &rc);	// pOleObject->DoVerbにthisやm_hWndを指定.
	if (FAILED(hr)){	// FAILEDなら.
		pOleObject->Release();	// pOleObject->Releaseでリリース.
		m_pWebBrowser->Release();	// m_pWebBrowser->Releaseでリリース.
		m_pWebBrowser = NULL;	// m_pWebBrowserにNULLをセット.
		return FALSE;	// FALSEを返す.
	}

	// pOleObjectのリリース.
	pOleObject->Release();	// pOleObject->Releaseでリリース.

	// TRUE.
	return TRUE;	// TRUEを返す.

}

// 指定のURLをロード.
void CWebBrowserHost::Navigate(LPCTSTR lpctszUrl){

	// 変数の宣言
	VARIANT varFlags, varTargetFrameName, varPostData, varHeaders;	// VARIANT変数.
	BSTR bszUrl;	// URLを指すbszUrl

	// Navigate.
	bszUrl = SysAllocString(lpctszUrl);	// SysAllocStringでlpctszUrlからBSTRなbszUrlを確保.
	VariantInit(&varFlags);	// VariantInitでvarFlagsを初期化.
	VariantInit(&varTargetFrameName);	// VariantInitでvarTargetFrameNameを初期化.
	VariantInit(&varPostData);	// VariantInitでvarPostDataを初期化.
	VariantInit(&varHeaders);	// VariantInitでvarHeadersを初期化.
	m_pWebBrowser->Navigate(bszUrl, &varFlags, &varTargetFrameName, &varPostData, &varHeaders);	// m_pWebBrowser->NavigateでbszUrlのWebページをロード.
	SysFreeString(bszUrl);	// SysFreeStringでbszUrlの解放.

}
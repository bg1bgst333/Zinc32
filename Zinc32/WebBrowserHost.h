// 二重インクルード防止
#ifndef __WEB_BROWSER_HOST_H__
#define __WEB_BROWSER_HOST_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <shlobj.h>		// シェルオブジェクト

// ウェブブラウザホストクラスCWebBrowserHost
class CWebBrowserHost : public IOleClientSite, public IOleInPlaceSite{

	// privateメンバ
	private:

		// privateメンバ変数
		LONG m_lRef;	// 参照回数.
		HWND m_hWnd;	// ウィンドウハンドル.
		//IWebBrowser2 *m_pWebBrowser;	// IWebBrowser2ポインタ.

	// publicメンバ
	public:

		// publicメンバ変数
		IWebBrowser2 *m_pWebBrowser;	// IWebBrowser2ポインタ.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CWebBrowserHost();	// コンストラクタCWebBrowserHost()
		virtual ~CWebBrowserHost();	// デストラクタ~CWebBrowserHost()
		// インターフェース
		// IUnknown
		STDMETHODIMP QueryInterface(REFIID riid, void **ppvObject);	// QieryInterface.
		STDMETHODIMP_(ULONG) AddRef();	// AddRef.
		STDMETHODIMP_(ULONG) Release();	// Release.
		// IOleClientSite
		STDMETHODIMP GetContainer(IOleContainer **ppContainer);	// GetContainer.
		STDMETHODIMP GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, IMoniker **ppmk);	// GetMoniker.
		STDMETHODIMP OnShowWindow(BOOL fShow);	// OnShowWindow.
		STDMETHODIMP RequestNewObjectLayout();	// RequestNewObjectLayout.
		STDMETHODIMP SaveObject();	// SaveObject.
		STDMETHODIMP ShowObject();	// ShowObject.
		// IOleInPlaceSite
		STDMETHODIMP CanInPlaceActivate();	// CanInPlaceActivate.
		STDMETHODIMP DeactivateAndUndo();	// DeactivateAndUndo.
		STDMETHODIMP DiscardUndoState();	// DiscardUndoState.
		STDMETHODIMP GetWindowContext(IOleInPlaceFrame **ppFrame, IOleInPlaceUIWindow **ppDoc, LPRECT lprcPosRect, LPRECT lprcClipRect, LPOLEINPLACEFRAMEINFO lpFrameInfo);	// GetWindowContext.
		STDMETHODIMP OnInPlaceActivate();	// OnInPlaceActivate.
		STDMETHODIMP OnInPlaceDeactivate();	// OnInPlaceDeactivate.
		STDMETHODIMP OnPosRectChange(LPCRECT lprcPosRect);	// OnPosRectChange.
		STDMETHODIMP OnUIActivate();	// OnUIActivate.
		STDMETHODIMP OnUIDeactivate(BOOL fUndoable);	// OnUIDeactivate.
		STDMETHODIMP Scroll(SIZE scrollExtant);	// Scroll.
		// IOleWindow
		STDMETHODIMP ContextSensitiveHelp(BOOL fEnterMode);	//  ContextSensitiveHelp.
		STDMETHODIMP GetWindow(HWND *phwnd);	// GetWindow.
		// メンバ関数
		BOOL Attach(HWND hWnd);	// このオブジェクトとウィンドウを紐付けるAttach.
		void Navigate(LPCTSTR lpctszUrl);	// 指定のURLをロード.

};

#endif
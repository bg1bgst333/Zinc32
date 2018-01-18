// 二重インクルード防止
#ifndef __WEB_BROWSER_H__
#define __WEB_BROWSER_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "UserControl.h"	// CUserControl
#include "WebBrowserHost.h"	// CWebBrowserHost

// ウェブブラウザクラスCWebBrowser
class CWebBrowser : public CUserControl{

	// privateメンバ
	public:

		// privateメンバ変数
		CWebBrowserHost *m_pWebBrowserHost;	// CWebBrowserHostオブジェクトポインタm_pWebBrowserHost.

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CWebBrowser();	// コンストラクタCWebBrowser
		virtual ~CWebBrowser();	// デストラクタ~CWebBrowser
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass.
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.
		void Attach(CWebBrowserHost *pWebBrowserHost);	// WebBrowserHostのセットとアタッチ.
		void Navigate(LPCTSTR lpctszUrl);	// URLのロード.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnDestroy();	// ウィンドウが破棄された時.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウのサイズが変更された時.

};

#endif
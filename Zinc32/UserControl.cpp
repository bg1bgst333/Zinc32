// ヘッダのインクルード
// 独自のヘッダ
#include "UserControl.h"	// CUserControl

// コンストラクタCUserControl
CUserControl::CUserControl() : CWindow(){

}

// デストラクタ~CUserControl
CUserControl::~CUserControl(){

}

// ウィンドウクラス登録関数RegisterClass.
BOOL CUserControl::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName){

	// ウィンドウクラスの登録.
	return CWindow::RegisterClass(hInstance, lpctszClassName);	// CWindow::RegisterClassで登録.

}

// ウィンドウ作成関数Create.
BOOL CUserControl::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウの作成.
	return CWindow::Create(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createで作成.

}

// ウィンドウの作成が開始された時.
int CUserControl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CUserControl::OnDestroy(){

	// 親クラスのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}

// ウィンドウのサイズが変更された時.
void CUserControl::OnSize(UINT nType, int cx, int cy){

}
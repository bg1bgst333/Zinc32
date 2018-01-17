// 二重インクルード防止
#ifndef __BUTTON_H__
#define __BUTTON_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "CustomControl.h"	// CCustomControl

// ボタンコントロールクラスCButton
class CButton : public CCustomControl{

	// publicメンバ
	public:

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
		
};

#endif
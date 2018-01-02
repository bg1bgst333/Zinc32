// ��d�C���N���[�h�h�~
#ifndef __WEB_BROWSER_HOST_H__
#define __WEB_BROWSER_HOST_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <shlobj.h>		// �V�F���I�u�W�F�N�g

// �E�F�u�u���E�U�z�X�g�N���XCWebBrowserHost
class CWebBrowserHost : public IOleClientSite, public IOleInPlaceSite{

	// private�����o
	private:

		// private�����o�ϐ�
		LONG m_lRef;	// �Q�Ɖ�.
		HWND m_hWnd;	// �E�B���h�E�n���h��.
		//IWebBrowser2 *m_pWebBrowser;	// IWebBrowser2�|�C���^.

	// public�����o
	public:

		// public�����o�ϐ�
		IWebBrowser2 *m_pWebBrowser;	// IWebBrowser2�|�C���^.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CWebBrowserHost();	// �R���X�g���N�^CWebBrowserHost()
		virtual ~CWebBrowserHost();	// �f�X�g���N�^~CWebBrowserHost()
		// �C���^�[�t�F�[�X
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
		// �����o�֐�
		BOOL Attach(HWND hWnd);	// ���̃I�u�W�F�N�g�ƃE�B���h�E��R�t����Attach.
		void Navigate(LPCTSTR lpctszUrl);	// �w���URL�����[�h.

};

#endif
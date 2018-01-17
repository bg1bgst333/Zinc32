// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow

// static�����o�ϐ��̒�`.
std::map<HWND, CWindow *> CWindow::m_mapWindowMap;	// �E�B���h�E�}�b�vm_mapWindowMap.

// �R���X�g���N�^CWindow()
CWindow::CWindow(){

	// �����o�̏�����.
	m_hWnd = NULL;	// m_hWnd��NULL�ŏ�����.

}

// �f�X�g���N�^~CWindow()
CWindow::~CWindow(){

	// �����o�̏I������.
	if (m_hWnd != NULL){	// m_hWnd��NULL�łȂ���.
		DestroyWindow(m_hWnd);	// DestroyWindow��m_hWnd��j��.
		m_hWnd = NULL;	// m_hWnd��NULL���Z�b�g.
	}

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CWindow::RegisterClass(HINSTANCE hInstance){

	// �E�B���h�E�N���X����"CWindow".
	return RegisterClass(hInstance, _T("CWindow"));	// �E�B���h�E�N���X����"CWindow"���w�肷��.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName){

	// �E�B���h�E�v���V�[�W���ɂ�"CWindow"�̃��m���w�肷��.
	return RegisterClass(hInstance, lpctszClassName, StaticWindowProc);	// �E�B���h�E�v���V�[�W���o�[�W������StaticWindowProc���w��.
	
}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�v���V�[�W���w��o�[�W����.)
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, WNDPROC lpfnWndProc){

	// lpfnWndProc���w��.
	return RegisterClass(hInstance, lpctszClassName, lpfnWndProc, NULL);	// �E�B���h�E�v���V�[�W���o�[�W������lpfnWndProc���w��.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�v���V�[�W���ȗ�, ���j���[���w��o�[�W����.)
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, LPCTSTR lpszMenuName){

	// StaticWindowProc, lpszMenuName���w��.
	return RegisterClass(hInstance, lpctszClassName, StaticWindowProc, lpszMenuName);	// ���j���[���w��o�[�W������StaticWindowProc��lpszMenuName���w��.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.(���j���[���w��o�[�W����.)
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, WNDPROC lpfnWndProc, LPCTSTR lpszMenuName){

	// �\���̂̐錾.
	WNDCLASS wc;	// WNDCLASS�^�E�B���h�E�N���X�\����wc

	// �E�B���h�E�N���X�\����wc�Ƀp�����[�^���Z�b�g.
	wc.lpszClassName = lpctszClassName;	// �E�B���h�E�N���X����lpctszClassName���w�肷��.
	wc.style = CS_HREDRAW | CS_VREDRAW;	// �X�^�C���͂Ƃ肠����CS_HREDRAW | CS_VREDRAW�ɂ���.
	wc.lpfnWndProc = lpfnWndProc;	// �E�B���h�E�v���V�[�W���ɂ͎w�肳�ꂽlpfnWndProc.
	wc.hInstance = hInstance;	// �A�v���P�[�V�����C���X�^���X�n���h���͈�����hInstance���g��.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIcon�ŃA�v���P�[�V��������̃A�C�R�������[�h.(��1������NULL.)
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursor�ŃA�v���P�[�V��������̃J�[�\�������[�h.(��1������NULL.)
	wc.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);	// GetStockObject�Ń��C�g�O���[�u���V��w�i�F�Ƃ���.
	wc.lpszMenuName = lpszMenuName;	// lpszMenuName���w�肷��.
	wc.cbClsExtra = 0;	// �Ƃ肠����0���w��.
	wc.cbWndExtra = 0;	// �Ƃ肠����0���w��.

	// �E�B���h�E�N���X�̓o�^
	if (!::RegisterClass(&wc)){	// WindowsAPI��RegisterClass�ŃE�B���h�E�N���X��o�^����.

		// �߂�l��0�Ȃ�o�^���s�Ȃ̂ŃG���[����.
		return FALSE;	// return��FALSE��Ԃ��Ĉُ�I��.

	}

	// �o�^�����Ȃ̂�TRUE.
	return TRUE;	// return��TRUE��Ԃ�.

}

// �X�^�e�B�b�N�E�B���h�E�v���V�[�W��StaticWindowProc�̒�`
LRESULT CALLBACK CWindow::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// �|�C���^�̏�����.
	CWindow *pWindow = NULL;	// CWindow�I�u�W�F�N�g�|�C���^pWindow��NULL�ŏ�����.

	// �E�B���h�E���b�Z�[�W�̏���.
	switch (uMsg){	// uMsg�̒l���Ƃɏ�����U�蕪����.

		
		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// �|�C���^�̏�����
				LPCREATESTRUCT lpCreateStruct = NULL;	// CREATESTRUCT�\���̂ւ̃|�C���^lpCreateStruct��NULL.
				// lParam����lpCreateStruct�����o��.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�^�ɃL���X�g����lpCreateStruct�Ɋi�[.
				if (lpCreateStruct != NULL){	// lpCreateStruct��NULL�łȂ����.
					pWindow = (CWindow *)lpCreateStruct->lpCreateParams;	// lpCreateStruct->lpCreateParams��CWindow�I�u�W�F�N�g�|�C���^�ɃL���X�g��, pWindow�Ɋi�[.
					m_mapWindowMap.insert(std::pair<HWND, CWindow *>(hwnd, pWindow));	// m_mapWindowMap��hwnd��pWindow�̃y�A��o�^.
				}

			}

			// ����̏����֌�����.
			break;	// break�Ŕ����Ċ���̏����֌�����.

		// ����ȊO�̎�.
		default:

			// default�u���b�N
			{

				// hwnd��CWindow�I�u�W�F�N�g�|�C���^����������, pWindow�Ɋi�[.
				if (m_mapWindowMap.find(hwnd) != m_mapWindowMap.end()){	// find�ŃL�[��hwnd�Ƃ���CWindow�I�u�W�F�N�g�|�C���^������������.
					pWindow = m_mapWindowMap[hwnd];	// pWindow��hwnd�ň�����CWindow�I�u�W�F�N�g�|�C���^���i�[.
				}

			}

			// ����̏����֌�����.
			break;	// break�Ŕ����Ċ���̏����֌�����.

	}

	// CWindow�I�u�W�F�N�g�|�C���^���擾�ł��Ȃ������ꍇ, �擾�ł����ꍇ�ŕ�����.
	if (pWindow == NULL){	// pWindow��NULL

		// DefWindowProc�ɔC����.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc�Ɉ��������̂܂ܓn����, DefWindowProc�̖߂�l�����̂܂ܕԂ�.

	}
	else{	// pWindow��NULL�łȂ���.

		// ����CWindow�I�u�W�F�N�g��DynamicWindowProc�ɓn��.
		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->DynamicWindowProc�Ɉ��������̂܂ܓn����, DynamicWindowProc�̖߂�l�����̂܂ܕԂ�.

	}

}

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)

	// �E�B���h�E�N���X����"CWindow".
	return CWindow::Create(_T("CWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ɃE�B���h�E�N���X��"CWindow"���w��.

}

// �E�B���h�E�쐬�֐�Create.
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�̍쐬.
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindow�ŃE�B���h�E���쐬��, �n���h����m_hWnd�Ɋi�[.(�Ō�̈����ɂ�this(�������g)��n��.)
	if (m_hWnd == NULL){	// m_hWnd��NULL�Ȃ玸�s.

		// ���s�Ȃ�FALSE��Ԃ�.
		MessageBox(NULL, _T("�\�����ʃG���[���������܂���!"), _T("Zinc"), MB_OK | MB_ICONHAND);	// MessageBox��"�\�����ʃG���[���������܂���!"�ƕ\��.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �����Ȃ�TRUE.
	return TRUE;	// �����Ȃ̂�TRUE��Ԃ�.

}

// �E�B���h�E�\���֐�ShowWindow.
BOOL CWindow::ShowWindow(int nCmdShow){

	// �E�B���h�E�̕\��.
	return ::ShowWindow(m_hWnd, nCmdShow);	// WindowsAPI��ShowWindow��m_hWnd��\��.

}

// �e�L�X�g�Z�b�g�֐�SetText.
void CWindow::SetText(LPCTSTR lpctszText){

	// �e�L�X�g�̃Z�b�g.
	SetWindowText(m_hWnd, lpctszText);	// SetWindowText��lpctszText�̃Z�b�g.

}

// �e�L�X�g�̒����擾�֐�GetTextLength.
int CWindow::GetTextLength(){

	// �e�L�X�g�̒������擾��, �����Ԃ�.
	return GetWindowTextLength(m_hWnd);	// GetWindowTextLength�Ńe�L�X�g�̒������擾��, ��������̂܂ܕԂ�.

}

// �e�L�X�g�擾�֐�GetText.
tstring CWindow::GetText(){

	// �e�L�X�g�̒�����Ԃ�.
	int iLen = GetTextLength();	// GetTextLength�Ńe�L�X�g�̒������擾��, iLen�Ɋi�[.

	// �o�b�t�@�̊m��.
	TCHAR *ptszBuf = new TCHAR[iLen + 1];	// iLen + 1�̒�����TCHAR���I�z����m��.
	ZeroMemory(ptszBuf, (sizeof(TCHAR) * (iLen + 1)));	// ptszBuf��0�Ŗ��߂�.

	// �e�L�X�g�̎擾.
	GetWindowText(m_hWnd, ptszBuf, iLen + 1);	// GetWindowText�Ńe�L�X�g���擾��, ptszBuf�Ɋi�[.

	// �e�L�X�g��tstring�Ɉڂ�.
	tstring tstrText = ptszBuf;	// tstrText��ptszBuf�ŏ�����.

	// �o�b�t�@�̉��.
	delete [] ptszBuf;	// delete[]��ptszBuf�����.

	// �e�L�X�g��Ԃ�.
	return tstrText;	// tstrText��Ԃ�.

}

// �_�C�i�~�b�N�E�B���h�E�v���V�[�W��DynamicWindowProc.
LRESULT CWindow::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// �E�B���h�E���b�Z�[�W�̏���.
	switch (uMsg){	// uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// OnCreate�ɔC����.
				return OnCreate(hwnd, (LPCREATESTRUCT)lParam);	// hwnd��lParam��OnCreate�ɓn��, ���Ƃ͔C����.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:

			// WM_DESTROY�u���b�N
			{

				// OnDestroy�ɔC����.
				OnDestroy();	// OnDestroy���Ă�.
				
			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
		case WM_SIZE:

			// WM_SIZE�u���b�N
			{

				// �ϐ��̏�����
				UINT nType = (UINT)wParam;	// UINT�^nType��wParam���Z�b�g.
				int cx = LOWORD(lParam);	// int�^cx��LOWORD(lParam)���Z�b�g.
				int cy = HIWORD(lParam);	// int�^cy��HIWORD(lParam)���Z�b�g.

				// OnSize�ɔC����.
				OnSize(nType, cx, cy);	// OnSize��hwnd, nType, cx, cy��n��.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �R�}���h������������.
		case WM_COMMAND:

			// WM_COMMAND�u���b�N
			{

				// OnCommand�ɔC����.
				return OnCommand(wParam, lParam) ? 0 : 1;

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ��L�ȊO�̎�.
		default:

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

	}

	// ���Ƃ͊���̏����ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// �߂�l���܂߂�DefWindowProc�Ɋ���̏�����C����.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ��ɃE�B���h�E�쐬�ɐ���������̂Ƃ���.
	return 0;	// 0��Ԃ���, �E�B���h�E�쐬�ɐ��������Ƃ������ƂɂȂ�.

}

// �E�B���h�E���j�����ꂽ��.
void CWindow::OnDestroy(){

	// �I�����b�Z�[�W�̑��M.
	PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT���b�Z�[�W�𑗐M.

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
void CWindow::OnSize(UINT nType, int cx, int cy){

}

// �R�}���h������������.
BOOL CWindow::OnCommand(WPARAM wParam, LPARAM lParam){

	// �������Ă��Ȃ��̂�FALSE.
	return FALSE;	// return��FALSE��Ԃ�.

}
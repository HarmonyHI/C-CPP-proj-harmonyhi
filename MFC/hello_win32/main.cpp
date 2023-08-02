#include <windows.h>
#include <cstring>
#include <string>
using namespace std;
 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc;
	HWND hwnd, hwndDT;
	MSG msg;
	RECT rect;
	int dtWidth,dtHeight;
 
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc;
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);
 
	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
 
	hwndDT=GetDesktopWindow(); //ȡ������ 
	GetWindowRect(hwndDT,&rect); //ȡ���淶Χ 
	dtWidth=rect.right-rect.left; //������ 
	dtHeight=rect.bottom-rect.top; //����߶� 
	
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,wc.lpszClassName,
		"First Windows Appliction",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		(dtWidth-640)/2,   /*�������*/ 
		(dtHeight-480)/2,
		640,
		480,
		NULL,NULL,hInstance,NULL);
	//MoveWindow(hwnd, (width-640)/2, (height-480)/2, 640, 480, FALSE);
     
	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!", MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
 
	while(GetMessage(&msg, NULL, 0, 0) > 0) { 
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
 
	return msg.wParam;
}
 
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC         	hdc;
	PAINTSTRUCT 	ps;
	RECT			rect;
	POINT			mouse;
	static int  	cxChar, cyChar;
	static int  	mX, mY;
	static HWND 	hwndButton;
	static HWND 	hwndEditbox;
	string			strXy;
	char			x[5], y[5];
	char			buff[4096] = {0};
	const int		IDcmdButton = 1;
	const int		IDeditBox = 2;
	
	cxChar = LOWORD(GetDialogBaseUnits());
	cyChar = HIWORD(GetDialogBaseUnits());
     
	switch (message) {
		case WM_CREATE:
			hwndButton = CreateWindow ( TEXT("button"), TEXT("Command Button"),
                            			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                   		cxChar * 6, cyChar * 15,
                                   		30 * cxChar, 2.5 * cyChar,
                                   		hwnd, (HMENU)IDcmdButton, ((LPCREATESTRUCT) lParam)->hInstance, NULL);
			if (!hwndButton) MessageBox(NULL,"������ťʧ��","Message",MB_OK|MB_ICONERROR);
			ShowWindow(hwndButton,SW_SHOW);
            UpdateWindow(hwndButton);
				
            hwndEditbox = CreateWindow( TEXT("edit"),NULL,
										WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE,
                                   		cxChar * 31, cyChar * 0.5,
                                   		30 * cxChar, 9.5 * cyChar,
										hwnd,(HMENU)IDeditBox,NULL,NULL);
										
			if (!hwndEditbox) MessageBox(NULL,"�����ı���ʧ��","Message",MB_OK|MB_ICONERROR);
			ShowWindow(hwndEditbox,SW_SHOW);
            UpdateWindow(hwndEditbox);
        	return 0 ;
	          
	    case WM_PAINT:
			hdc = BeginPaint (hwnd, &ps);
	    	SetRect(&rect, 10, 10, 300, 200);
    	    FrameRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
			GetClientRect (hwnd, &rect);
			rect.left += 20;
            rect.top += 2;
            //SetTextColor(hdc, RGB(255,0,0)); //������RGB��ԭɫ�����ı���ɫ
			DrawText(hdc, TEXT(" Hello, Dev-C++! "), -1, &rect, DT_SINGLELINE | DT_TOP | DT_LEFT);
			EndPaint(hwnd, &ps);
			return 0;
 
	    case WM_SIZE:
			//GetWindowRect(hwnd, &rect);
			//MoveWindow(hwndButton, (rect.right-rect.left)/2 - 15*cxChar ,\
			//(rect.bottom-rect.top)/2 - 1.25*cxChar, 30*cxChar, 2.5*cyChar, FALSE);
			return 0;
			
		case WM_COMMAND:
			//���ؼ���_click()�¼� 
			switch (LOWORD(wParam)) {
			case 0:
				PostQuitMessage(0);
				break;
			case IDcmdButton: 
				GetWindowText(hwndEditbox,buff,100);
				if (buff[0])
					MessageBox(NULL, buff, "ComandButton_Click()", MB_OK);
				else
					MessageBox(NULL, "����ComandButton_Click()�¼�", "���ť", MB_ICONASTERISK);
				break;
			case IDeditBox:
				GetWindowText(hwndEditbox,buff,4096);
				break;
			}
			return 0; 
 
		case WM_LBUTTONDOWN: // WM_LBUTTONDOWN�����������µ��¼�
			GetCursorPos(&mouse);
			GetWindowRect(hwnd, &rect);
			mX=mouse.x-rect.left;
			mY=mouse.y-rect.top;
			itoa(mX,x,10);
			itoa(mY,y,10);
			strXy="������Ĵ��������꣺("+string(x)+","+string(y)+")";
			SetWindowText(hwndEditbox,strXy.c_str());
			//MessageBox(NULL, strXy.c_str(), "", MB_ICONASTERISK);
			return 0;
 
		case WM_CLOSE:
			if (IDYES==MessageBox(hwnd, "�Ƿ����Ҫ�˳���", "ȷ��", MB_ICONQUESTION | MB_YESNO))
				DestroyWindow(hwnd);  //���ٴ���
			return 0;
		  
		case WM_DESTROY:
			MessageBox(hwnd, "�ټ�", "�ټ�", MB_ICONQUESTION); 
			PostQuitMessage(0);
			return 0;
	}
	
	return DefWindowProc(hwnd, message, wParam, lParam);
}

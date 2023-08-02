
// McountDlg.h : 头文件
 
#pragma once
 
 
// CMcountDlg 对话框
class CMcountDlg : public CDialogEx
{
// 构造
public:
    CMcountDlg(CWnd* pParent = NULL);    // 标准构造函数
 
// 对话框数据
    enum { IDD = IDD_MCOUNT_DIALOG };
 
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
 
 
// 实现
protected:
    HICON m_hIcon;
 
    // 生成的消息映射函数
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonone();
    double m_showvalue;
    afx_msg void OnBnClickedButtontwo();
    afx_msg void OnBnClickedButtonthree();
    afx_msg void OnBnClickedButton4();
    afx_msg void OnBnClickedButton5();
    afx_msg void OnBnClickedButton6();
    afx_msg void OnBnClickedButton7();
    afx_msg void OnBnClickedButton8();
    afx_msg void OnBnClickedButton9();
    afx_msg void OnBnClickedButton10();
    static int i,sub,del,mup,chu,point;
    static double j,pointlater;
    static float valuenumber;
    afx_msg void OnBnClickedButtonadd();
    afx_msg void OnBnClickedButtonequel();
    afx_msg void OnBnClickedButtonclean();
    afx_msg void OnBnClickedButtonsub();
    afx_msg void OnBnClickedButtonmplit();
    afx_msg void OnBnClickedButtondelete();
    afx_msg void OnBnClickedButtonpoint();
    afx_msg void OnBnClickedButtonone2();
    afx_msg void OnBnClickedButtonone3();
    afx_msg void OnBnClickedButtonone4();
    afx_msg void OnBnClickedButtonone5();
    afx_msg void OnBnClickedButtondelete2();
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
————————————————
版权声明：本文为CSDN博主「LV小猪精」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44478077/article/details/104193636
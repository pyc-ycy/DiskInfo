
// DeskInfoDlg.h: 头文件
//

#pragma once

class CDeskInfoDlgAutoProxy;


// CDeskInfoDlg 对话框
class CDeskInfoDlg : public CDialog
{
	DECLARE_DYNAMIC(CDeskInfoDlg);
	friend class CDeskInfoDlgAutoProxy;

// 构造
public:
	void HandleDeviceChange(UINT message, WPARAM   wParam, LPARAM   lParam);
	char GetDriveFromMask(ULONG unitmask);
	void WriteLog(LPCTSTR format, ...);
	CDeskInfoDlg(CWnd* pParent = nullptr);	// 标准构造函数
	virtual ~CDeskInfoDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DESKINFO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);



// 实现
protected:
	CDeskInfoDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	// 磁盘路径
	CString m_DiskName;
	afx_msg void OnButtonGetvol();
	CEdit m_EditLog;
	CString m_Log;
	afx_msg void OnButtonGetseral();
	afx_msg void OnButtonCheckA();
	afx_msg void OnButtonCheckcdrom();
	afx_msg void OnButtonGetmediatype();
};

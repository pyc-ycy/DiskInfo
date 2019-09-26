
// DeskInfoDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "DeskInfo.h"
#include "DeskInfoDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDeskInfoDlg 对话框


IMPLEMENT_DYNAMIC(CDeskInfoDlg, CDialog);

CDeskInfoDlg::CDeskInfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DESKINFO_DIALOG, pParent)
	, m_DiskName(_T(""))
	, m_Log(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = nullptr;
}

CDeskInfoDlg::~CDeskInfoDlg()
{
	// 如果该对话框有自动化代理，则
	//  此对话框的返回指针为 null，所以它知道
	//  此代理知道该对话框已被删除。
	if (m_pAutoProxy != nullptr)
		m_pAutoProxy->m_pDialog = nullptr;
}

void CDeskInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DISKNAME, m_DiskName);
	DDX_Control(pDX, IDC_EDIT_LOG_TEXT, m_EditLog);
	DDX_Text(pDX, IDC_EDIT_LOG_TEXT, m_Log);
}

BEGIN_MESSAGE_MAP(CDeskInfoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_GETVOL, &CDeskInfoDlg::OnButtonGetvol)
	ON_BN_CLICKED(IDC_BUTTON_GETSERAL, &CDeskInfoDlg::OnButtonGetseral)
	ON_BN_CLICKED(IDC_BUTTON_CHECK_A, &CDeskInfoDlg::OnButtonCheckA)
	ON_BN_CLICKED(IDC_BUTTON_CHECKCDROM, &CDeskInfoDlg::OnButtonCheckcdrom)
	ON_BN_CLICKED(IDC_BUTTON_GETMEDIATYPE, &CDeskInfoDlg::OnButtonGetmediatype)
END_MESSAGE_MAP()


// CDeskInfoDlg 消息处理程序

BOOL CDeskInfoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDeskInfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDeskInfoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDeskInfoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 当用户关闭 UI 时，如果控制器仍保持着它的某个
//  对象，则自动化服务器不应退出。  这些
//  消息处理程序确保如下情形: 如果代理仍在使用，
//  则将隐藏 UI；但是在关闭对话框时，
//  对话框仍然会保留在那里。

void CDeskInfoDlg::OnClose()
{
	if (CanExit())
		CDialog::OnClose();
}

void CDeskInfoDlg::OnOK()
{
	if (CanExit())
		CDialog::OnOK();
}

void CDeskInfoDlg::OnCancel()
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CDeskInfoDlg::CanExit()
{
	// 如果代理对象仍保留在那里，则自动化
	//  控制器仍会保持此应用程序。
	//  使对话框保留在那里，但将其 UI 隐藏起来。
	if (m_pAutoProxy != nullptr)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

// 记录日志
void CDeskInfoDlg::WriteLog(LPCTSTR format, ...)
{
	char log[MAX_LOG_LENGTH] = { 0 };
	va_list arg_ptr;  // 获取参数列表
	va_start(arg_ptr, format);  // 将参数列表指向第一个参数	
	_vsnprintf(log, sizeof(log) - 1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);
}

// 获取驱动器卷标
void CDeskInfoDlg::OnButtonGetvol()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	char szVolume[MAX_PATH] = { 0 };
	if (GetVolumeInformation(m_DiskName, szVolume, MAX_PATH, NULL, NULL, NULL, NULL, 0))
		WriteLog("驱动器%s的卷标=%s", m_DiskName, szVolume);
	else
	{
		if (GetLastError() == ERROR_DEVICE_NOT_CONNECTED)
			WriteLog("没有插入盘");
		else
			WriteLog("获取驱动器卷标失败！");
	}
}

// 获取磁盘序列号
void CDeskInfoDlg::OnButtonGetseral()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	DWORD dwSerial;
	if (GetVolumeInformation(m_DiskName, NULL, 0, &dwSerial, NULL, NULL, NULL, 0))
		WriteLog("磁盘%s的磁盘序列号=%X", m_DiskName, dwSerial);
	else
		WriteLog("获取驱动器卷标失败");
}

// 检测是否有软驱
void CDeskInfoDlg::OnButtonCheckA()
{
	// TODO: 在此添加控件通知处理程序代码
	BOOL bResult = FALSE;
	DWORD cb = 0;
	HANDLE hDevice = NULL;
	hDevice = CreateFile("\\\\.\\A:\\", GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_SHARE_WRITE, NULL); // 打开到软驱的连接句柄	
	if (hDevice != NULL)
	{
		if (DeviceIoControl((HANDLE)hDevice, IOCTL_STORAGE_CHECK_VERIFY, NULL, 0, NULL, 0, &cb, NULL))	// 检测软驱中是否有软盘
		{
			WriteLog("软驱中没有软盘");
			return;
		}
		WriteLog("软驱中没有软盘");
	}
}

// 判断是否有存储器插入
LRESULT CDeskInfoDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// 处理Window函数
	if (message == WM_DEVICECHANGE)
		HandleDeviceChange(message, wParam, lParam);

	return CDialog::WindowProc(message, wParam, lParam);
}
char CDeskInfoDlg::GetDriveFromMask(ULONG unitmask)
{
	char i;
	for (i = 0; i < 26; i++)
	{
		if (unitmask & 0x1)
			break;
		unitmask = unitmask >> 1;
	}
	return (i + 'A');
}
void CDeskInfoDlg::HandleDeviceChange(UINT message, WPARAM wParam, LPARAM lParam)
{
	// 检测驱动器插入和移除
	PDEV_BROADCAST_HDR lpdb = (PDEV_BROADCAST_HDR)lParam;
	// 获取改变的设备信息
	switch (wParam)
	{
	case DBT_DEVICEARRIVAL:
		// 插入新硬件
		// 如果是存储器
		if (lpdb->dbch_devicetype == DBT_DEVTYP_VOLUME)
		{
			// 转换设备信息
			PDEV_BROADCAST_VOLUME lpdbv = (PDEV_BROADCAST_VOLUME)lpdb;
			if (!((lpdbv->dbcv_flags & DBTF_MEDIA)
				|| (lpdbv->dbcv_flags & DBTF_NET)))
			{
				char volumn = GetDriveFromMask(lpdbv->dbcv_unitmask);
				WriteLog("插入%c新存储器", volumn);
			}
		}
		break;
	case   DBT_DEVICEREMOVECOMPLETE:
		if (lpdb->dbch_devicetype == DBT_DEVTYP_VOLUME)
		{
			PDEV_BROADCAST_VOLUME lpdbv = (PDEV_BROADCAST_VOLUME)lpdb;
			if (!((lpdbv->dbcv_flags & DBTF_MEDIA)
				|| (lpdbv->dbcv_flags & DBTF_NET)))
			{
				char volumn = GetDriveFromMask(lpdbv->dbcv_unitmask);
				WriteLog("移除%c存储器", volumn);
			}
		}
		break;
	default:
		break;
	}
	
}

void CDeskInfoDlg::OnButtonCheckcdrom()
{
	// TODO: 在此添加控件通知处理程序代码
	DWORD dwReturn;		// 定义返回值变量
	char strDrivers[MAX_PATH];		// 定义驱动器数组
	dwReturn = GetLogicalDriveStrings(MAX_PATH, (LPSTR)&strDrivers);	// 获取本地驱动器字符串
	CString log;	// 定义日志信息变量
	for (int i = 0; i < dwReturn; i++)
	{
		// 如果驱动器盘符有效
		if ((strDrivers[i] < 'Z') && (strDrivers[i] >= 'A'))
		{
			CString driver;
			driver.Format("%c:\\", strDrivers[i]);
			UINT type = GetDriveType(driver);
			if (type == DRIVE_CDROM)
			{
				int bResult = GetVolumeInformation(driver, NULL, 0, NULL, NULL, NULL, NULL, 0);
				CString info;
				if (bResult == 0)
					info.Format("光驱%c中没有光盘\r\n", strDrivers[i]);
				else
					info.Format("光驱%c中有光盘\r\n", strDrivers[i]);
				log += info;
			}
		}
	}
	WriteLog(log);
}

// 获取驱动器类型
void CDeskInfoDlg::OnButtonGetmediatype()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	CString csType;
	UINT uiType = GetDriveType(m_DiskName);
	switch (uiType)
	{
	case DRIVE_UNKNOWN:
		csType = "驱动器类型不确定。"; break;
	case DRIVE_NO_ROOT_DIR:
		csType = "指定的根目录不存在。"; break;
	case DRIVE_REMOVABLE:
		csType = "可移动的存储器。"; break;
	case DRIVE_FIXED:
		csType = "固定的存储器，也就是所谓的磁盘"; break;
	case DRIVE_REMOTE:
		csType = "远程驱动器，也称为网络驱动器。"; break;
	case DRIVE_CDROM:
		csType = "CD-ROM 驱动器。"; break;
	case DRIVE_RAMDISK:
		csType = "内存驱动器，驱动器将内存的一部分划分出来作为硬盘使用。"; break;
	default:
		csType = "未知";
	}
	WriteLog("驱动器%s的类型返回值=%d(%s)", m_DiskName, uiType, csType);
}


// DlgProxy.cpp: 实现文件
//

#include "stdafx.h"
#include "DeskInfo.h"
#include "DlgProxy.h"
#include "DeskInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDeskInfoDlgAutoProxy

IMPLEMENT_DYNCREATE(CDeskInfoDlgAutoProxy, CCmdTarget)

CDeskInfoDlgAutoProxy::CDeskInfoDlgAutoProxy()
{
	EnableAutomation();

	// 为使应用程序在自动化对象处于活动状态时一直保持
	//	运行，构造函数调用 AfxOleLockApp。
	AfxOleLockApp();

	// 通过应用程序的主窗口指针
	//  来访问对话框。  设置代理的内部指针
	//  指向对话框，并设置对话框的后向指针指向
	//  该代理。
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CDeskInfoDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CDeskInfoDlg)))
		{
			m_pDialog = reinterpret_cast<CDeskInfoDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CDeskInfoDlgAutoProxy::~CDeskInfoDlgAutoProxy()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	//	析构函数调用 AfxOleUnlockApp。
	//  除了做其他事情外，这还将销毁主对话框
	if (m_pDialog != nullptr)
		m_pDialog->m_pAutoProxy = nullptr;
	AfxOleUnlockApp();
}

void CDeskInfoDlgAutoProxy::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CDeskInfoDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CDeskInfoDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_IDeskInfo 的支持来支持类型安全绑定
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {ad5d62fa-d938-4cd9-87e5-05d8ee5ffafe}
static const IID IID_IDeskInfo =
{0xad5d62fa,0xd938,0x4cd9,{0x87,0xe5,0x05,0xd8,0xee,0x5f,0xfa,0xfe}};

BEGIN_INTERFACE_MAP(CDeskInfoDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CDeskInfoDlgAutoProxy, IID_IDeskInfo, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 宏在此项目的 StdAfx.h 中定义
// {35e4f1a6-343a-44d0-9876-35ea4e2a70dc}
IMPLEMENT_OLECREATE2(CDeskInfoDlgAutoProxy, "DeskInfo.Application", 0x35e4f1a6,0x343a,0x44d0,0x98,0x76,0x35,0xea,0x4e,0x2a,0x70,0xdc)


// CDeskInfoDlgAutoProxy 消息处理程序

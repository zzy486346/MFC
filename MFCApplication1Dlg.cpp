
// MFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "ChildDlg.h"

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


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, m_find(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_find);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication1Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication1Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

	// 设置列表控件的风格
	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT;
	m_list.SetExtendedStyle(dwStyle);

	m_list.InsertColumn(0, TEXT("编号"), 0, 150);
	m_list.InsertColumn(1, TEXT("姓名"), 0, 100);
	m_list.InsertColumn(2, TEXT("性别"), 0, 100);
	m_list.InsertColumn(3, TEXT("部门"), 0, 100);
	m_list.InsertColumn(4, TEXT("年龄"), 0, 100);
	m_list.InsertColumn(5, TEXT("时间"), 0, 100);
	m_list.InsertColumn(6, TEXT("工资"), 0, 100);
	m_list.InsertColumn(7, TEXT("职称"), 0, 100);
	m_list.InsertColumn(8, TEXT("简历"), 0, 300);

	Isopen = false;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// 设置过滤器   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);

	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();

		DataInterface.Open(strFilePath);

		Isopen = true;
		
		UpdateList();
	}
}


void CMFCApplication1Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CMFCApplication1Dlg::UpdateList()
{
	m_list.DeleteAllItems();
	CString str;
	for (int i = 0; i < DataInterface.Info.size(); i++)
	{
		str.Format(TEXT("%s"), DataInterface.Info[i].m_id.c_str());
		m_list.InsertItem(i, str);
		m_list.SetItemText(i, 1, DataInterface.Info[i].m_name.c_str());
		m_list.SetItemText(i, 2, DataInterface.Info[i].m_sex.c_str());
		m_list.SetItemText(i, 3, DataInterface.Info[i].m_sector.c_str());
		m_list.SetItemText(i, 4, DataInterface.Info[i].m_age.c_str());
		m_list.SetItemText(i, 5, DataInterface.Info[i].m_time.c_str());
		m_list.SetItemText(i, 6, DataInterface.Info[i].m_salary.c_str());
		m_list.SetItemText(i, 7, DataInterface.Info[i].m_jobt.c_str());
		m_list.SetItemText(i, 8, DataInterface.Info[i].m_cv.c_str());
	}
}


void CMFCApplication1Dlg::OnBnClickedButton5()
{
	
		if (Isopen)
		{
			ChildDlg dlg;
			if (IDOK == dlg.DoModal())
			{
				Cinf Info(dlg.m_id.GetBuffer(), dlg.m_name.GetBuffer(), dlg.m_sex.GetBuffer(), dlg.m_sector.GetBuffer(),
					dlg.m_age.GetBuffer(), dlg.m_time.GetBuffer(), dlg.m_salary.GetBuffer(),
					dlg.m_jobt.GetBuffer(), dlg.m_cv.GetBuffer());
				DataInterface.Add(Info);
				UpdateList();
			}
		}
		else
		{
			MessageBox(TEXT("请先打开文件"), TEXT("提示"));
		}
	
}


void CMFCApplication1Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Isopen) 
	{
		int index = m_list.GetSelectionMark();
		if (index > -1)
		{
			UINT i;
			i = MessageBox(_T("确定要删除这条记录吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
			if (i == IDYES)
			{
				DataInterface.Del(index);
				MessageBox(TEXT("删除成功！"), TEXT("提示"));
				UpdateList();
			}
			else
			{
				return;
			}
		}
		else
		{
			MessageBox(TEXT("请先点击列表选择需要删除的记录！"), TEXT("提示"));
		}
	}
	else
	{
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));
	}
}


void CMFCApplication1Dlg::OnBnClickedButton7()
{
	if (Isopen) {
		int index = m_list.GetSelectionMark();

		if (index > -1)
		{
			ChildDlg dlg;
			CString str;
			str.Format(TEXT("%s"), DataInterface.Info[index].m_id.c_str());
			dlg.m_id = str;
			str.Format(TEXT("%s"), DataInterface.Info[index].m_name.c_str());
			dlg.m_name = str;
			str.Format(TEXT("%s"), DataInterface.Info[index].m_sex.c_str());
			dlg.m_sex = str;
			str.Format(TEXT("%s"), DataInterface.Info[index].m_sector.c_str());
			dlg.m_sector = str;
			str.Format(TEXT("%s"), DataInterface.Info[index].m_age.c_str());
			dlg.m_age = str;
			str.Format(TEXT("%s"), DataInterface.Info[index].m_time.c_str());
			dlg.m_time = str;
			str.Format(TEXT("%s"), DataInterface.Info[index].m_salary.c_str());
			dlg.m_salary = str;
			str.Format(TEXT("%s"), DataInterface.Info[index].m_jobt.c_str());
			dlg.m_jobt = str;
			str.Format(TEXT("%s"), DataInterface.Info[index].m_cv.c_str());
			dlg.m_cv = str;
			if (IDOK == dlg.DoModal())
			{
				Cinf Info(dlg.m_id.GetBuffer(), dlg.m_name.GetBuffer(), dlg.m_sex.GetBuffer(), dlg.m_sector.GetBuffer(),
					dlg.m_age.GetBuffer(), dlg.m_time.GetBuffer(), dlg.m_salary.GetBuffer(),
					dlg.m_jobt.GetBuffer(), dlg.m_cv.GetBuffer());
				DataInterface.Amend(index, Info);
				UpdateList();
			}
		}
		else
		{
			MessageBox(TEXT("请先点击列表选择需要修改的记录！"), TEXT("提示"));
		}
	}
	else
	{
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));
	}
}


void CMFCApplication1Dlg::OnBnClickedButton8()
{
	if (Isopen)
	{
		// TODO: 在此添加控件通知处理程序代码
		UpdateData(TRUE);
		Cinf FindInfo = DataInterface.Find(m_find);
		if (FindInfo.m_id == "")
		{
			MessageBox(TEXT("查无此记录！"), TEXT("提示"));
		}
		else
		{
			CString str;
			str.Format(TEXT("查找成功！\n编号：%s\n姓名：%s\n性别:%s\n部门：%s\n年龄：%s\n时间：%s\n工资：%s\n职称：%s\n简历：%s"),
				FindInfo.m_id.c_str(), FindInfo.m_name.c_str(), FindInfo.m_sex.c_str(), FindInfo.m_sector.c_str(),
				FindInfo.m_age.c_str(), FindInfo.m_time.c_str(), FindInfo.m_salary.c_str(),
				FindInfo.m_jobt.c_str(), FindInfo.m_cv.c_str());
			MessageBox(str, TEXT("提示"));
		}
	}
	else
	{
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));
	}
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Isopen)
	{
		if (DataInterface.Save(strFilePath)) MessageBox(TEXT("已保存!"), TEXT("提示"));
		else MessageBox(TEXT("保存失败!"), TEXT("提示"));
	}
	else
	{
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));
	}
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT i;
	i = MessageBox(_T("确定要退出吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
	if (i == IDYES)
	{
		exit(0);
	}
	else
	{
		return;
	}
}




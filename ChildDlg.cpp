// ChildDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "ChildDlg.h"


// ChildDlg 对话框

IMPLEMENT_DYNAMIC(ChildDlg, CDialogEx)

ChildDlg::ChildDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChildDlg, pParent)
	, m_id(_T(""))
	, m_name(_T(""))
	, m_sex(_T(""))
	, m_sector(_T(""))
	, m_age(_T(""))
	, m_time(_T(""))
	, m_salary(_T(""))
	, m_jobt(_T(""))
	, m_cv(_T(""))
{

}

ChildDlg::~ChildDlg()
{
}

void ChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_sex);
	DDX_Text(pDX, IDC_EDIT4, m_sector);
	DDX_Text(pDX, IDC_EDIT5, m_age);
	DDX_Text(pDX, IDC_EDIT6, m_time);
	DDX_Text(pDX, IDC_EDIT6, m_time);
	DDX_Text(pDX, IDC_EDIT7, m_salary);
	DDX_Text(pDX, IDC_EDIT8, m_jobt);
	DDX_Text(pDX, IDC_EDIT9, m_cv);
}


BEGIN_MESSAGE_MAP(ChildDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT7, &ChildDlg::OnEnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT6, &ChildDlg::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_BUTTON1, &ChildDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ChildDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// ChildDlg 消息处理程序


void ChildDlg::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChildDlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChildDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	if (m_id == TEXT("") || m_name == TEXT("") || m_sex == TEXT("")
		|| m_sector == TEXT("") || m_age == TEXT("") || m_time == TEXT("")
		|| m_salary == TEXT("") || m_jobt == TEXT("") || m_cv == TEXT(""))
	{
		MessageBox(TEXT("您有输入为空，请补充完整"), TEXT("提示"));
	}
	else
	{
		OnOK();
		return;
	}
}


void ChildDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}

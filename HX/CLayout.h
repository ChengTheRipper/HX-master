#pragma once
#include "map"
#include "vector"

using namespace std;

class CCtrlInfo
{
public:
	CCtrlInfo(CRect& rect, LOGFONT* logFont, int stretchFlag)
	{
		m_ctrlRect = rect;
		m_pCtrlLogFont = logFont;
		m_stretchFlag = stretchFlag;
	}

private:
	// Hide copy constructor and '='
	CCtrlInfo(const CCtrlInfo&) {}
	CCtrlInfo& operator=(const CCtrlInfo&) {}

public:
	CRect    m_ctrlRect;
	CRect    m_ctrlCurRect;
	LOGFONT* m_pCtrlLogFont;
	int      m_stretchFlag;
	CFont    m_font;
};

typedef map<UINT, CCtrlInfo*> UINTTOCTRLMap;

class CLayout
{
public:
	CLayout();
	virtual ~CLayout(void);
private:
	// Hide copy constructor and '='
	CLayout(CLayout&) {}
	CLayout& operator=(const CCtrlInfo&) {}
public:
	void Initial(CWnd* pParent);
	void RegisterControl(UINT nCtrlID, int stretchFlag);
	void UnRegisterControl(UINT nCtrlID);
	void OnSize(int cx, int cy);
	CCtrlInfo* GetCtrlInfo(int nID)
	{
		UINTTOCTRLMap::iterator it = m_ctrlsMap.find(nID);
		if (it != m_ctrlsMap.end())
		{
			return it->second;
		}

		return NULL;
	}

	enum {
		e_stretch_none = 0x00,        // �ؼ����洰�����ţ�ֻ�洰�������ƶ�����
		e_stretch_width = 0x01,		// �ؼ����洰������
		e_stretch_height = 0x02,		// �ؼ����洰������
		e_stretch_font = 0x04,		// �ؼ������洰������
		e_stretch_all = 0x07,		// �ؼ��������Ծ��洰������
	};

private:
	void ConvertToCurrentRect(const CRect& initRect, CRect& curRect, int stretchFlag);
	void ConvertToCurrentFont(LOGFONT initLogFont, CFont* pCurFont);
	void UnregisterAllControls();

private:
	UINTTOCTRLMap m_ctrlsMap;

	CWnd* m_pParent;
	int   m_nClientInitWidth;	// �����ڿͻ������ʼ���
	int   m_nClientInitHeight;	// �����ڿͻ������ʼ�߶�

	float m_xscale;				// x�������ű���
	float m_yscale;				// y�������ű���
};


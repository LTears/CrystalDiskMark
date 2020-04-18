﻿/*---------------------------------------------------------------------------*/
//       Author : hiyohiyo
//         Mail : hiyohiyo@crystalmark.info
//          Web : https://crystalmark.info/
//      License : The MIT License
/*---------------------------------------------------------------------------*/

#pragma once

#include "CommonFx.h"
#include <atlimage.h>
#include <gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")
using namespace Gdiplus;

class CButtonFx : public CButton
{
	DECLARE_DYNAMIC(CButtonFx);

public:
	// Constructors
	CButtonFx();
	virtual ~CButtonFx();

	// Control
	BOOL InitControl(int x, int y, int width, int height, double zoomRatio,
		 CDC* bgDC, LPCWSTR imagePath, int imageCount, DWORD textAlign, int renderMode);
	void SetMargin(int top, int left, int bottom, int right, double zoomRatio);
	CSize GetSize(void);
	void SetDrawFrame(BOOL bDrawFrame);
	void SetGlassColor(COLORREF glassColor, BYTE glassAlpha);

	// Font
	void SetFontEx(CString face, int size, int sizeToolTip, double zoomRatio, double fontRatio = 1.0,
		 BYTE textAlpha = 255, COLORREF textColor = RGB(0, 0, 0), LONG fontWeight = FW_NORMAL);

	// Mouse
	void SetHandCursor(BOOL bHandCuror = TRUE);

	// ToolTip
	void SetToolTipText(LPCTSTR text);
	void SetToolTipActivate(BOOL bActivate = TRUE);
	void SetToolTipWindowText(LPCTSTR text);
	CString GetToolTipText();

protected:
	// Draw Control
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void DrawControl(CDC* drawDC, LPDRAWITEMSTRUCT lpDrawItemStruct, CBitmap& ctrlBitmap, CBitmap& bgBitmap, int no);
	virtual void DrawString(CDC* drawDC, LPDRAWITEMSTRUCT lpDrawItemStruct);

	// Image
	BOOL LoadBitmap(LPCTSTR pFileName);
	BOOL LoadBitmap(HBITMAP hBitmap);
	void SetBgReload(void);
	BOOL SetBitmap(CBitmap& bitmap);
	void LoadCtrlBg(CDC* drawDC);

	// ToolTip
	void InitToolTip();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	// Message Map
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	afx_msg void OnKillfocus();
	afx_msg void OnSetfocus();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);

protected:
	// Control
	int m_X;
	int m_Y;
	CSize m_CtrlSize;
	CRect m_Margin;
	int m_RenderMode;
	BOOL m_bHighContrast;

	// Glass
	COLORREF m_GlassColor;
	BYTE m_GlassAlpha;

	// Image
	CString m_ImagePath;
	int m_ImageCount;
	CDC* m_BgDC;
	CBitmap m_BgBitmap;
	BOOL m_bBgBitmapInit;
	BOOL m_bBgLoad;
	CBitmap m_CtrlBitmap;
	CImage m_CtrlImage;

	// Font
	DWORD m_TextAlign;
	CFont m_Font;
	CFont m_FontToolTip;
	COLORREF m_TextColor;

	// ToolTip
	CToolTipCtrl m_ToolTip;
	CString m_ToolTipText;

	// Mouse
	BOOL m_bHover;
	BOOL m_bFocas;
	BOOL m_bTrackingNow;
	BOOL m_bHandCursor;
};

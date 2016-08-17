///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/listctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/toolbar.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define id0 1000
#define id1 1001
#define id2 1002
#define id3 1003
#define id4 1004
#define id5 1005

///////////////////////////////////////////////////////////////////////////////
/// Class MainWindow
///////////////////////////////////////////////////////////////////////////////
class MainWindow : public wxFrame 
{
	private:
	
	protected:
		wxListCtrl* kvList;
		wxStatusBar* statusBar;
		wxToolBar* toolBar;
		wxToolBarToolBase* openTool; 
		wxToolBarToolBase* CloseTool; 
		wxToolBarToolBase* AddRecordTool; 
		wxToolBarToolBase* EditRecordTool; 
		wxToolBarToolBase* RemoveRecordTool; 
		wxToolBarToolBase* SearchTool; 
		
		// Virtual event handlers, overide them in your derived class
		virtual void MainWindowOnSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void kvListOnListColRightClick( wxListEvent& event ) { event.Skip(); }
		virtual void kvListOnSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void openToolOnToolClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void CloseToolOnToolClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void AddRecordToolOnToolClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void EditRecordToolOnToolClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void RemoveRecordToolOnToolClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void SearchToolOnToolClicked( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MainWindow( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("KVEditor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 650,448 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MainWindow();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AddDialog
///////////////////////////////////////////////////////////////////////////////
class AddDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* keyLabel;
		wxTextCtrl* keyText;
		wxStaticText* valueLabel;
		wxTextCtrl* valueText;
		wxButton* addBtn;
		wxButton* importBtn;
		
		// Virtual event handlers, overide them in your derived class
		virtual void addBtnOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void importBtnOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AddDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Add record dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 606,300 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~AddDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SearchDialog
///////////////////////////////////////////////////////////////////////////////
class SearchDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxTextCtrl* m_textCtrl2;
	
	public:
		
		SearchDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Search"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 396,203 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SearchDialog();
	
};

#endif //__GUI_H__

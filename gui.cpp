///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

#include "res/add.bmp.h"
#include "res/close.bmp.h"
#include "res/edit.bmp.h"
#include "res/open.bmp.h"
#include "res/remove.bmp.h"
#include "res/search.bmp.h"

///////////////////////////////////////////////////////////////////////////

MainWindow::MainWindow( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,300 ), wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	bSizer1->SetMinSize( wxSize( 500,450 ) ); 
	kvList = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT );
	bSizer1->Add( kvList, 1, wxALL|wxEXPAND, 0 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	toolBar = this->CreateToolBar( wxTB_FLAT|wxTB_HORIZONTAL|wxTB_HORZ_LAYOUT|wxTB_NOALIGN|wxTB_NODIVIDER, wxID_ANY );
	toolBar->SetToolSeparation( 10 );
	toolBar->SetMargins( wxSize( 5,5 ) );
	toolBar->SetToolPacking( 2 );
	openTool = toolBar->AddTool( id0, wxT("tool"), open_bmp_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Open file"), NULL ); 
	
	CloseTool = toolBar->AddTool( id1, wxT("tool"), close_bmp_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Close file"), NULL ); 
	
	toolBar->AddSeparator(); 
	
	AddRecordTool = toolBar->AddTool( id2, wxT("tool"), add_bmp_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Add record"), NULL ); 
	
	EditRecordTool = toolBar->AddTool( id3, wxT("tool"), edit_bmp_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Edit record"), NULL ); 
	
	RemoveRecordTool = toolBar->AddTool( id4, wxT("tool"), remove_bmp_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Remove record"), NULL ); 
	
	toolBar->AddSeparator(); 
	
	SearchTool = toolBar->AddTool( id5, wxT("tool"), search_bmp_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Search ..."), NULL ); 
	
	toolBar->Realize(); 
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( MainWindow::MainWindowOnSize ) );
	kvList->Connect( wxEVT_COMMAND_LIST_COL_RIGHT_CLICK, wxListEventHandler( MainWindow::kvListOnListColRightClick ), NULL, this );
	kvList->Connect( wxEVT_SIZE, wxSizeEventHandler( MainWindow::kvListOnSize ), NULL, this );
	this->Connect( openTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainWindow::openToolOnToolClicked ) );
	this->Connect( CloseTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainWindow::CloseToolOnToolClicked ) );
	this->Connect( AddRecordTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainWindow::AddRecordToolOnToolClicked ) );
	this->Connect( EditRecordTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainWindow::EditRecordToolOnToolClicked ) );
	this->Connect( RemoveRecordTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainWindow::RemoveRecordToolOnToolClicked ) );
	this->Connect( SearchTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainWindow::SearchToolOnToolClicked ) );
}

MainWindow::~MainWindow()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainWindow::MainWindowOnSize ) );
	kvList->Disconnect( wxEVT_COMMAND_LIST_COL_RIGHT_CLICK, wxListEventHandler( MainWindow::kvListOnListColRightClick ), NULL, this );
	kvList->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainWindow::kvListOnSize ), NULL, this );
	this->Disconnect( openTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainWindow::openToolOnToolClicked ) );
	this->Disconnect( CloseTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainWindow::CloseToolOnToolClicked ) );
	this->Disconnect( AddRecordTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainWindow::AddRecordToolOnToolClicked ) );
	this->Disconnect( EditRecordTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainWindow::EditRecordToolOnToolClicked ) );
	this->Disconnect( RemoveRecordTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainWindow::RemoveRecordToolOnToolClicked ) );
	this->Disconnect( SearchTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainWindow::SearchToolOnToolClicked ) );
	
}

AddDialog::AddDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer3->SetMinSize( wxSize( 500,100 ) ); 
	keyLabel = new wxStaticText( this, wxID_ANY, wxT("key"), wxDefaultPosition, wxDefaultSize, 0 );
	keyLabel->Wrap( -1 );
	bSizer3->Add( keyLabel, 0, wxALL, 5 );
	
	keyText = new wxTextCtrl( this, wxID_ANY, wxT("defaultKey"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	keyText->SetMinSize( wxSize( 200,-1 ) );
	
	bSizer3->Add( keyText, 0, wxALL, 5 );
	
	valueLabel = new wxStaticText( this, wxID_ANY, wxT("value"), wxDefaultPosition, wxDefaultSize, 0 );
	valueLabel->Wrap( -1 );
	bSizer3->Add( valueLabel, 0, wxALL, 5 );
	
	valueText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,300 ), wxTE_MULTILINE );
	valueText->SetMinSize( wxSize( 200,300 ) );
	
	bSizer3->Add( valueText, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	addBtn = new wxButton( this, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( addBtn, 0, wxALL|wxBOTTOM, 5 );
	
	importBtn = new wxButton( this, wxID_ANY, wxT("Import ..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( importBtn, 0, wxALL, 5 );
	
	
	bSizer3->Add( bSizer6, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer3 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	addBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddDialog::addBtnOnButtonClick ), NULL, this );
	importBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddDialog::importBtnOnButtonClick ), NULL, this );
}

AddDialog::~AddDialog()
{
	// Disconnect Events
	addBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddDialog::addBtnOnButtonClick ), NULL, this );
	importBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddDialog::importBtnOnButtonClick ), NULL, this );
	
}

SearchDialog::SearchDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer2->Add( m_staticText1, 0, wxALL, 5 );
	
	m_textCtrl2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_textCtrl2, 0, wxALL, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

SearchDialog::~SearchDialog()
{
}

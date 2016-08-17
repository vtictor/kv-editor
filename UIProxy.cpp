#include "UIProxy.h"

UIProxy::UIProxy(int parent): MainWindow(parent)
{
    dbh = new DBHandler();
    fileSelector = new wxFileDialog(this, "Open UnQLite DB file", "", "", "UnQlite files (*.db)|*.db|Any file (*.*)|*.*", wxFD_OPEN |wxFD_FILE_MUST_EXIST);
    toolBar->EnableTool(id1, false);
    toolBar->EnableTool(id2, false);
    toolBar->EnableTool(id3, false);
    toolBar->EnableTool(id4, false);
    toolBar->EnableTool(id5, false);
}

UIProxy::~UIProxy()
{
    delete dbh;
    delete fileSelector;
}

void UIProxy::fillkvList()
{
    kvList->ClearAll();
    kvList->InsertColumn(0, "Key", wxLIST_FORMAT_CENTER, 250);
    kvList->InsertColumn(1, "Value", wxLIST_FORMAT_CENTER, 250);

    std::map<wxString, wxString> rows;
    int rowcount = dbh->getRecordList(&rows);
    int i = 0;

    for(std::map<wxString, wxString>::iterator it = rows.begin(); it != rows.end(); it++)
    {
        i = kvList->InsertItem(0, it->first);
        kvList->SetItem(i, 1, it->second);
    }
    statusBar->SetStatusText(wxString::Format("Found %u records", rowcount));
}

void UIProxy::kvListOnSize( wxSizeEvent& event )
{
   kvList->SetSize(event.GetSize().GetWidth(), event.GetSize().GetHeight());
}

void UIProxy::openToolOnToolClicked( wxCommandEvent& event )
{
    dbh->closeDbFile();
    if( fileSelector->ShowModal() == wxID_OK )
    {
        if( dbh->openDbFile( fileSelector->GetPath().c_str() ) )
        {
            statusBar->SetStatusText(wxString::Format("Opening file %s", fileSelector->GetPath().c_str()));
            fillkvList();
            toolBar->EnableTool(id1, true);
            toolBar->EnableTool(id2, true);
            toolBar->EnableTool(id3, true);
            toolBar->EnableTool(id4, true);
            toolBar->EnableTool(id5, true);
        }
        else
        {
            statusBar->SetStatusText(wxString::Format("Can't open file %s", fileSelector->GetPath().c_str()));
        }
    }

}

void UIProxy::CloseToolOnToolClicked( wxCommandEvent& event )
{
    dbh->closeDbFile();
    kvList->ClearAll();
    statusBar->SetStatusText("");
    toolBar->EnableTool(id1, false);
    toolBar->EnableTool(id2, false);
    toolBar->EnableTool(id3, false);
    toolBar->EnableTool(id4, false);
    toolBar->EnableTool(id5, false);
}

void UIProxy::AddRecordToolOnToolClicked( wxCommandEvent& event )
{
    AddRecord ar(this);
    ar.ShowModal();
    dbh->addRecord(ar.getKey().c_str(), ar.getKey().Len(), ar.getValue().c_str(), ar.getValue().Len());
    fillkvList();

}

void UIProxy::RemoveRecordToolOnToolClicked( wxCommandEvent& event )
{
    int answer = wxMessageBox("Delete selected?", "Confirm", wxYES | wxNO, this);
    if (answer == wxYES)
    {
        long item = -1;
        for ( ;; )
        {
            item = kvList->GetNextItem(item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
            if ( item == -1 )
                break;
            wxString key = kvList->GetItemText(item);
            dbh->removeRecord(key.c_str());
        }
        fillkvList();
    }
}

/**********************************************/

AddRecord::AddRecord(wxWindow *parent): AddDialog(parent)
{

}

AddRecord::~AddRecord()
{

}


void AddRecord::addBtnOnButtonClick( wxCommandEvent& event )
{
    key = keyText->GetValue();
    value = valueText->GetValue();
    this->Show(false);
}


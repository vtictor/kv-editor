#ifndef UIPROXY_H
#define UIPROXY_H

#include <map>
#include "gui.h"
#include "DBHandler.h"
#include <wx/filedlg.h>
#include <wx/msgdlg.h>


class UIProxy : public MainWindow
{
    public:
        UIProxy(int parent);
        virtual ~UIProxy();
        void fillkvList();
    protected:
    private:
        void kvListOnSize( wxSizeEvent& event );
        void openToolOnToolClicked( wxCommandEvent& event );
        void CloseToolOnToolClicked( wxCommandEvent& event );
        void AddRecordToolOnToolClicked( wxCommandEvent& event );
        void RemoveRecordToolOnToolClicked( wxCommandEvent& event );

        DBHandler *dbh;
        wxFileDialog *fileSelector;
};

/*******************************************************/

class AddRecord: public AddDialog
{
    public:
        AddRecord(wxWindow *parent);
        virtual ~AddRecord();
        void addBtnOnButtonClick( wxCommandEvent& event );
        wxString getKey(){ return key; }
        wxString getValue(){ return value; }
    private:
        wxString key;
        wxString value;
};

#endif // UIPROXY_H

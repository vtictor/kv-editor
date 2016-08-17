#include <wx/wx.h>
#include "gui.h"
#include "UIProxy.h"

class MyApp : public wxApp
{
  public:
    virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    UIProxy *win = new UIProxy(0);
    win->Show(true);

    return true;
};

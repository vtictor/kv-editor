#ifndef DBHANDLER_H_INCLUDED
#define DBHANDLER_H_INCLUDED

#include <wx/string.h>
#include <map>

extern "C"
{

#include "unqlite.h"

}

class DBHandler
{
    public:
        DBHandler();
        ~DBHandler();
        bool openDbFile(const char *dbfilename);
        void closeDbFile();
        bool addRecord(const char *key, int ksize, const char *data, long long datasize);
        bool addFromFile(const char *filename);
        bool editRecord(const char *key);
        bool removeRecord(const char *key);
        bool searchRecord(const char *needle, int nsize);
        int    getRecordList(std::map<wxString, wxString>* rlist);
    private:
        unqlite *pDb;
        const int max_kv_size = 255;
};


#endif // DBHANDLER_H_INCLUDED

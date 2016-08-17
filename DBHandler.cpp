#include "DBHandler.h"

DBHandler::DBHandler()
{
    pDb = 0;
}

DBHandler::~DBHandler()
{

}

bool DBHandler::openDbFile(const char *dbfilename)
{
    int rc = unqlite_open(&pDb, dbfilename, UNQLITE_OPEN_READWRITE);
    return rc == UNQLITE_OK;
}

void DBHandler::closeDbFile()
{
    unqlite_close(pDb);
    pDb = 0;
}

 int DBHandler::getRecordList(std::map<wxString, wxString>* rlist)
 {
    int rc;
    unqlite_kv_cursor *cursor;

    rc = unqlite_kv_cursor_init(pDb, &cursor);

    if( rc != UNQLITE_OK )
    {
        return 0;
    }

    unqlite_kv_cursor_first_entry(cursor);

    while( unqlite_kv_cursor_valid_entry(cursor) )
    {
        int keyLen;
        unqlite_int64 dataLen;
        unqlite_kv_cursor_key(cursor, 0, &keyLen);
        if( keyLen > max_kv_size ) keyLen = max_kv_size;
        unqlite_kv_cursor_data(cursor, 0, &dataLen);
        if( dataLen > max_kv_size ) dataLen = max_kv_size;
        char key[max_kv_size + 5];
        char data[max_kv_size + 5];
        unqlite_kv_cursor_key(cursor, key, &keyLen);
        unqlite_kv_cursor_data(cursor, data, &dataLen);
        rlist->insert(std::pair<wxString, wxString>(wxString(key, keyLen), wxString(data, dataLen) ));
        unqlite_kv_cursor_next_entry(cursor);
    }
    unqlite_kv_cursor_release(pDb, cursor);
    return rlist->size();
 }

bool DBHandler::addRecord(const char *key, int ksize, const char *data, long long datasize)
{
    int rc;
    rc = unqlite_kv_store(pDb, key, ksize, data, datasize);
    return rc == UNQLITE_OK;
}

bool DBHandler::removeRecord(const char *key)
{
    int rc;
    rc = unqlite_kv_delete(pDb, key, -1);
    return rc == UNQLITE_OK;
}


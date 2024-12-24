#include "leveldb/db.h"
#include <cassert>
#include <iostream>

using namespace std;
using namespace leveldb;

int main() {
  leveldb::DB *db;
  leveldb::Options options;
  options.create_if_missing = true;

  leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
  assert(status.ok());
  cout << "Create DB[testdb] success." << endl;


  status = db->Put(WriteOptions(), "GOAT", "MESSI");
  assert(status.ok());
  cout << "Insert into DB[testdb] with key[GOAT] success." << endl;

  string res;
  status = db->Get(ReadOptions(), "GOAT", &res);
  cout << status.ToString() << endl;
  assert(status.ok());
  cout << "Query from DB[testdb] with key[GOAT] and get value[" + res + "]." << endl;

  delete db;
  return 0;
}
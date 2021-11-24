//
// Created by ltc on 2021/11/23.
//

#include "KVDatabase.h"

KVDatabaseServer &KVDatabase::getInstance() {
	static KVDatabaseServer server;
	return server;
}

void KVDatabase::serve() {
	getInstance().serve();
}

string KVDatabase::get(const string &key) {
	return getInstance().get(key);
}

string KVDatabase::set(const string &key, const string& value) {
	return getInstance().set(key, value);
}

string KVDatabase::del(const string &key) {
	return getInstance().del(key);
}

void KVDatabase::setHandle(const string &cmd) {
	vector<string> split = utils::split(cmd, ' ');
	getInstance().data[split[0]] = split[1];
}

void KVDatabase::delHandle(const string &cmd) {
	getInstance().data.erase(cmd);
}


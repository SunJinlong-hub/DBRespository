#pragma once
#include <string>

//数据库连接接口
class IDBConnection
{
public:
	virtual void connect() = 0;	
	virtual void execute(const std::string& query) = 0;	
	virtual ~IDBConnection() = default;
};


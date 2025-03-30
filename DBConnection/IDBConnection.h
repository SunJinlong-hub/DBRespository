#pragma once
#include <string>

//���ݿ����ӽӿ�
class IDBConnection
{
public:
	virtual void connect() = 0;	
	virtual void execute(const std::string& query) = 0;	
	virtual ~IDBConnection() = default;
};


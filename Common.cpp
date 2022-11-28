#include "Common.h"

Type Common::LoginType = Type::User; // 默认使用普通用户登录
Type Common::RegisterType = Type::User; // 默认使用普通用户
Database *db = new Database;

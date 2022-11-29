#ifndef COMMON_H
#define COMMON_H
#include "database.h"

// 用户类型
enum Type {
    User,
    Librarian,
    Admin,
};

// 出借状态
enum LeanStatus {
    OnLean,         // 已借出
    NotOnLead,      // 未借出
    Ordered,        // 被预约
};

class Common {
public:
    static Type LoginType;
    static Type RegisterType;
    static Database db;
};


// 图书类目
enum Category {
    PoliticalAndLaw,                // 政治和法律
    Philosophy,                     // 哲学
    SocialScience,                  // 社会科学
    Military,                       // 军事
    Economic,                       // 经济
    Education,                      // 教育
    LanguageAndWriting,             // 语言和写作
    Literature,                     // 文学
    Art,                            // 艺术
    HistoryAndGeography,            // 历史和地理
    MathematicalAndChemistry,       // 数学和化学
    BiologicalScience,              // 生物科学
    MedicineAndHealth,              // 医药和健康
    Argiculture,                    // 农业
    IndustrialTechnology,           // 工业科技
    Transportation,                 // 交通运输
    Aerospace,                      // 航空航天
    EnvironmentScience,             // 环境科学
    ScienceFiction,                  // 科幻
    Comprehensive,                  // 综合
};

// 图书搜索方式
enum SearchWay {
    ByName,
    ByBookISBN,
    ByAuthor,
};

#endif // COMMON_H

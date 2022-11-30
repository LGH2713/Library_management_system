#ifndef UTILS_H
#define UTILS_H
#include "Common.h"

namespace Utils {
QString switchCategoryEnumToQString(enum Category category) {
    qDebug() <<  category;
    switch(category) {
    case Category::Aerospace :
        return "Aerospace";
    case Category::Argiculture:
        return "Argiculture";
    case Category::Art :
        return "Art";
    case Category::BiologicalScience:
        return "BiologicalScience";
    case Category::Comprehensive:
        return "Comprehensive";
    case Category::Economic:
        return "Economic";
    case Category::Education:
        return "Education";
    case Category::HistoryAndGeography:
        return "HistoryAndGeography";
    case Category::IndustrialTechnology:
        return "IndustrialTechnology";
    case Category::LanguageAndWriting:
        return "LanguageAndWriting";
    case Category::Literature:
        return "Literature";
    case Category::MathematicalAndChemistry:
        return "MathematicalAndChemistry";
    case Category::Military:
        return "Military";
    case Category::Philosophy:
        return "Philosophy";
    case Category::ScienceFiction:
        return "ScienceFiction";
    case Category::SocialScience:
        return "SocialScience";
    case Category::PoliticalAndLaw:
        return "PoliticalAndLaw";
    case Category::Transportation:
        return "Transportation";
    case Category::MedicineAndHealth:
        return "MedicineAndHealth";
    case Category::EnvironmentScience:
        return "EnvironmentScience";
    default:
        return "";
    };
}

}


#endif // UTILS_H

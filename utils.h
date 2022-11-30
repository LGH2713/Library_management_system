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

enum Category switchCategoryQStringToEnum(QString category) {
    if(category == "Aerospace")
        return  Category::Aerospace;
    else if(category == "Argiculture")
        return Category::Argiculture;
    else if(category == "Art")
        return  Category::Art ;
    else if(category == "BiologicalScience")
        return Category::BiologicalScience;
    else if(category == "Comprehensive")
        return Category::Comprehensive;
    else if(category == "Economic")
        return  Category::Economic;
    else if(category == "Education")
        return  Category::Education;
    else if(category == "HistoryAndGeography")
        return  Category::HistoryAndGeography;
    else if(category == "IndustrialTechnology")
        return Category::IndustrialTechnology;
    else if(category == "LanguageAndWriting")
        return Category::LanguageAndWriting;
    else if(category == "Literature")
        return Category::Literature;
    else if(category == "MathematicalAndChemistry")
        return Category::MathematicalAndChemistry;
    else if(category == "Military")
        return Category::Military;
    else if(category == "Philosophy")
        return Category::Philosophy;
    else if(category == "ScienceFiction")
        return Category::ScienceFiction;
    else if(category == "SocialScience")
        return  Category::SocialScience;
    else if(category == "PoliticalAndLaw")
        return Category::PoliticalAndLaw;
    else if(category == "Transportation")
        return Category::Transportation;
    else if(category == "MedicineAndHealth")
        return Category::MedicineAndHealth;
    else if(category == "EnvironmentScience")
        return Category::EnvironmentScience;
    else
        return Category::Comprehensive;
}
}


#endif // UTILS_H

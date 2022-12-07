#include "utilities.h"
#include <map>

static const std::map<eConvexHullAlg, std::string> fromAlgToString = {
    {eConvexHullAlg::GRAHAM, "Graham algorithm"},
    {eConvexHullAlg::JARVIS, "Jarvis algorithm"},
    {eConvexHullAlg::QUICK, "Quick algorithm"}
};

static const std::map<eColoredObjectType, std::string> fromColoredToString = {
    {eColoredObjectType::BACKGROUND, "Background color"},
    {eColoredObjectType::POINTS, "Points color"},
    {eColoredObjectType::CONVEXHULL, "Convex hull color"}
};

std::string getAlgorithmDescriptionString(eConvexHullAlg alg){
    if(auto fnd = fromAlgToString.find(alg); fnd != fromAlgToString.end()){
        return fnd->second;
    }

    return std::string();
}
eConvexHullAlg getAlgorithmFromDescriptionString(const std::string& str){
    for(const auto& [alg, description]: fromAlgToString){
        if(description == str)
            return alg;
    }
    return eConvexHullAlg::LAST_VALUE;
}

std::string getDescriptionFromColoredObjectType(eColoredObjectType coloredType){
    if(auto itr = fromColoredToString.find(coloredType); itr != fromColoredToString.end()){
        return itr->second;
    }

    return std::string();
}
eColoredObjectType getColoredObjectTypeFromDescription(const std::string& str){
    for(const auto& [colored_object, description]: fromColoredToString){
        if(description == str)
            return colored_object;
    }
    return eColoredObjectType::INVALID;
}

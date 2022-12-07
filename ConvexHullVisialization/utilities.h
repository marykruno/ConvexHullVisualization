#pragma once
#include <string>


enum class eConvexHullAlg {
    GRAHAM = 0,
    JARVIS = 1,
    QUICK = 2,
    LAST_VALUE = 3
};

enum class eColoredObjectType {
    BACKGROUND = 0,
    POINTS = 1,
    CONVEXHULL = 2,
    INVALID = -1
};

std::string getAlgorithmDescriptionString(eConvexHullAlg alg);
eConvexHullAlg getAlgorithmFromDescriptionString(const std::string& str);

std::string getDescriptionFromColoredObjectType(eColoredObjectType coloredType);
eColoredObjectType getColoredObjectTypeFromDescription(const std::string& str);

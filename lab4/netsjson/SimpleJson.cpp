#include <sstream>
#include "SimpleJson.h"
using namespace nets;
JsonValue::JsonValue(bool a)
{
    bool_ = new bool;
    *bool_ = a;
    int_ = nullptr;
    double_ = nullptr;
    string_ = nullptr;
    map_ = nullptr;
    vector_ = nullptr;
}
JsonValue::JsonValue(int a)
{
    bool_ = nullptr;
    int_ = new int;
    * int_ = a;
    double_ = nullptr;
    string_ = nullptr;
    map_ = nullptr;
    vector_ = nullptr;
}
JsonValue::JsonValue(double a)
{
    bool_ = nullptr;
    int_ = nullptr;
    double_ = new double;
    *double_ = a;
    string_ = nullptr;
    map_ = nullptr;
    vector_ = nullptr;
}
JsonValue::JsonValue(std::string a)
{
    bool_ = nullptr;
    int_ = nullptr;
    double_ = nullptr;
    string_ = new std::string;
    *string_ = std::move(a);
    map_ = nullptr;
    vector_ = nullptr;
}
JsonValue::JsonValue(std::vector<JsonValue> a)
{
    bool_ = nullptr;
    int_ = nullptr;
    double_ = nullptr;
    string_ = nullptr;
    map_ = nullptr;
    vector_ = new std::vector<JsonValue>;
    *vector_ = std::move(a);
}
JsonValue::JsonValue(std::map<std::string, JsonValue> a)
{
    bool_ = nullptr;
    int_ = nullptr;
    double_ = nullptr;
    string_ = nullptr;
    map_ = new std::map<std::string, JsonValue>;
    *map_ = std::move(a);
    vector_ = nullptr;
}
std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string name) const
{
    for(const auto & value : * map_)
    {
        if(value.first != name)
        {
            return std::experimental::make_optional(value.second);
        }
    }
    return {};
}
std::string JsonValue::ToString() const {
    std::stringstream stream;
    std::string values;
    if (int_ != nullptr) {
        stream<<*int_;
        stream >>values;
        delete int_;
        return values;
    }
    if (double_) {
        stream<<*double_;
        stream>>values;
        delete double_;
        return values;
    }
    if (bool_) {
        if (*bool_)
            values = "true";
        else {
            values = "false";
        }
        delete bool_;
        return values;
    }
    if (vector_) {
        values = "[";
        for (const auto &value : *vector_) {
            values = values + value.ToString() + ", ";
        }
        values.erase(values.length() - 2, 2);
        delete vector_;
        return values + "]";
    }
    if (map_) {
        values += '{';
        for (auto &n : *map_) {
            JsonValue tmp(n.first);
            values += tmp.ToString();
            values += ": ";
            values += n.second.ToString();
            values += ", ";
        }
        values.erase(values.length() - 2, 2);
        values += '}';
        delete map_;
        return values;
    }
    if (string_) {
        std::string copy = *string_;
        values += '\"';
        for (int i = 0; i < copy.length(); i++) {
            if (copy[i] == '\\' || copy[i] == '\"') {
                values += '\\';
            }
            values += copy[i];
        }

        values += '\"';
        delete string_;
        return values;
    }
}

JsonValue::~JsonValue() {

}

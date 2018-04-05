//
// Created by sad on 05.04.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H
#include <experimental/optional>
#include <string>
#include<vector>
#include<map>
#include<memory>
#include<iostream>
namespace nets
{
    class JsonValue{
    public:
        JsonValue();
        JsonValue(int);
        JsonValue(double);
        JsonValue(std::string);
        JsonValue(bool);
        virtual ~JsonValue();
        JsonValue(const JsonValue& val) {
            if(val.bool_)
            {
                bool_ = new bool;
                bool_ = val.bool_;
            }
            if(val.int_)
            {
                int_ = new int;
                int_ = val.int_;
            }
            if(val.double_)
            {
                double_ = new double;
                double_= val.double_;
            }
            if(val.string_)
            {
                string_ = new std::string;
                string_ = val.string_;
            }
            if(val.vector_)
            {
                vector_ = new std::vector<JsonValue>;
                vector_ = val.vector_;
            }
            if(val.map_)
            {
                map_ = new std::map <std::string, JsonValue>;
                map_ = val.map_;
            }
        }
        JsonValue & operator=(JsonValue val) {
            return * this;
        }


        JsonValue(std::vector<JsonValue>);
        JsonValue(std::map <std::string, JsonValue>);
        std::experimental::optional<JsonValue> ValueByName(const std::string name) const;
        std::string ToString() const;
    private:
        bool * bool_;
        int * int_;
        double * double_;
        std::string * string_;
        std::map <std::string, JsonValue> * map_;
        std::vector<JsonValue> * vector_;
    };
}



#endif //JIMP_EXERCISES_SIMPLEJSON_H

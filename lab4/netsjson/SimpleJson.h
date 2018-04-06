


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
        JsonValue(std::vector<JsonValue>);
        JsonValue(std::map <std::string, JsonValue>);
        virtual ~JsonValue();
        std::experimental::optional<JsonValue> ValueByName(const std::string name) const;
        std::string ToString() const;

    private:
        bool * bool_;
        int  * int_;
        double * double_;
        std::string * string_;
        std::map <std::string, JsonValue> * map_;
        std::vector<JsonValue> * vector_;
    };
}



#endif //JIMP_EXERCISES_SIMPLEJSON_H

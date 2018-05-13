//
// Created by sad on 13.05.18.
//

#include "Serialization.h"

academia::Room::Room(int x, std::string str, academia::Room::Type m) {
    i = x;
    s = std::move(str);
    t = m;
}

void academia::Room::Serialize(academia::Serializer *serializer) const{
    serializer->Header("room");
    serializer->IntegerField("id",i);
    serializer->StringField("name",s);
    serializer->TypeField("type",t);
    serializer->Footer("room");
}




academia::Building::Building(int in, std::string st,
                             std::vector<std::reference_wrapper<const academia::Serializable>> ve){
    i = in;
    s =std::move(st);
    v = std::move(ve);

}

void academia::Building::Serialize(academia::Serializer *serializer) const {
    serializer->Header("building");
    serializer->IntegerField("id",i);
    serializer->StringField("name",s);
    serializer->ArrayField("rooms",v);
    serializer->Footer("building");
};


void academia::JsonSerializer::DoubleField(const std::string &field_name, double value) {
    *stream<< "\"" << field_name << "\": " << value << ", ";
}

void academia::JsonSerializer::IntegerField(const std::string &field_name, int value) {
    *stream<< "\"" << field_name << "\": " << value << ", ";
}

void academia::JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
    *stream<< "\"" << field_name << "\": \"" << value << "\"" << ", ";
}

void academia::JsonSerializer::BooleanField(const std::string &field_name, bool value) {
    *stream<< "\"" << field_name << "\": " << value << ", ";
}

void academia::JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    value.Serialize(this);
}

void academia::JsonSerializer::ArrayField(const std::string &field_name,
                                          const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    *stream<< "\"" << field_name << "\": [";
    auto x = value.size();
    for(auto it = value.begin(); it != value.end(); ++it)
    {
        SerializableField("room",*it);
        if(x > 1)
        {
            *stream<<", ";
        }
        x--;
    }
    *stream <<"]";

}
void academia::JsonSerializer::TypeField(const std::string &field_name, const academia::Room::Type &value) {
    std::string x;
    switch (value) {
        case academia::Room::Type::COMPUTER_LAB:
            x  = "COMPUTER_LAB";
            break;
        case academia::Room::Type::LECTURE_HALL:
            x =  "LECTURE_HALL";
            break;
        case academia::Room::Type::CLASSROOM :
            x =  "CLASSROOM";
            break;
    }
    *stream<< "\"" << field_name << "\": \"" << x << "\"";
}

void academia::JsonSerializer::Header(const std::string &object_name) {
    *stream<< "{";
}

void academia::JsonSerializer::Footer(const std::string &object_name) {
    *stream<< "}";
}


void academia::XmlSerializer::IntegerField(const std::string &field_name, int value) {
    *stream<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
}

void academia::XmlSerializer::DoubleField(const std::string &field_name, double value) {
    *stream<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
}

void academia::XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
    *stream<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
}

void academia::XmlSerializer::TypeField(const std::string &field_name, const academia::Room::Type &s) {
    std::string x;
    switch (s) {
        case academia::Room::Type::COMPUTER_LAB:
            x  = "COMPUTER_LAB";
            break;
        case academia::Room::Type::LECTURE_HALL:
            x =  "LECTURE_HALL";
            break;
        case academia::Room::Type::CLASSROOM :
            x =  "CLASSROOM";
            break;
    }
    *stream << "<" << field_name << ">" << x << "<\\" << field_name <<">";
}

void academia::XmlSerializer::BooleanField(const std::string &field_name, bool value) {

}

void academia::XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    value.Serialize(this);
}

void academia::XmlSerializer::ArrayField(const std::string &field_name,
                                         const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    *(stream)<<"<"<<field_name<<">";
    for(auto it = value.begin(); it != value.end(); ++it)
    {
        SerializableField(field_name,*it);
    }

    *(stream)<<"<\\"<<field_name<<">";
}

void academia::XmlSerializer::Header(const std::string &object_name) {
 *stream << "<" << object_name << ">";
}

void academia::XmlSerializer::Footer(const std::string &object_name) {
    *stream << "<\\" << object_name << ">";
}

//
// Created by sad on 13.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
//#include <stdexcept>
#include <functional>
namespace academia {

    class Serializer;
    class Serializable {
    public:
        virtual void Serialize(academia::Serializer *) const=0 ;
    };
    class Room : public Serializable {
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM,
        };
        Room(int x, std::string s, Type m);

        void Serialize(academia::Serializer *serializer) const override;

        int i;
        std::string s;
        Type t;
    };

    class Serializer {
    public:
        Serializer(std::ostream *x) : stream(x) {};


        virtual void IntegerField(const std::string &field_name, int value)=0;

        virtual void DoubleField(const std::string &field_name, double value)=0;

        virtual void StringField(const std::string &field_name, const std::string &value)=0;

        virtual void BooleanField(const std::string &field_name, bool value)=0;

        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;

        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value)=0;
        virtual void TypeField(const std::string &field_name, const academia::Room::Type & s) = 0;

        virtual void Header(const std::string &object_name)=0;

        virtual void Footer(const std::string &object_name)=0;

        std::ostream *stream;
    };



    class JsonSerializer : public Serializer
    {
    public:
        JsonSerializer(std::ostream *x) : Serializer(x) {};
        void IntegerField(const std::string &field_name, int value) override ;

        void DoubleField(const std::string &field_name, double value) override ;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        void TypeField(const std::string &field_name, const academia::Room::Type & s) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;
    };
    class Building: public Serializable{
    public:
        Building(int in,std::string str,std::vector<std::reference_wrapper<const academia::Serializable>> vec);
        void Serialize(academia::Serializer *serializer) const override;
        int i;
        std::string s;
        std::vector<std::reference_wrapper<const Serializable>> v;

    };
    class XmlSerializer : public Serializer
    {
    public:
        XmlSerializer(std::ostream *x) : Serializer(x) {};
        void IntegerField(const std::string &field_name, int value) override ;

        void DoubleField(const std::string &field_name, double value) override ;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        void TypeField(const std::string &field_name, const academia::Room::Type & s) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;
    };
    class BuildingRepository
    {
    public:
        void StoreAll(Serializer *serializer);
    };
}



#endif //JIMP_EXERCISES_SERIALIZATION_H

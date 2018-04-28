//
// Created by sad on 21.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include <algorithm>
#include <memory>

namespace utility
{
    class IterableIterator
    {
    public:
        virtual std::pair<int, std::string> Dereference() const = 0;
        virtual IterableIterator &Next() = 0;
        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const = 0;
        std::vector<int>::const_iterator left_;
        std::vector<std::string>::const_iterator right_;

    };
    class ZipperIterator : public IterableIterator
    {
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left_begin,
                                std::vector<std::string>::const_iterator right_begin,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);
        ZipperIterator(std::vector<int>::const_iterator left_begin,
                       std::vector<std::string>::const_iterator right_begin);
        std::pair<int, std::string> Dereference() const override;
        IterableIterator &Next() override;
        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override;

    };
    class IterableIteratorWrapper
    {
    public:
        IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other) const;
        std::pair<int, std::string> operator*() const ;
        IterableIteratorWrapper &operator++();
        std::unique_ptr<IterableIterator> iter;
    };
    class Iterable
    {
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin() const = 0;
        virtual std::unique_ptr<IterableIterator> ConstEnd() const = 0;
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;
        std::pair<std::vector<int>,std::vector<std::string>> p_;
    };
    class Zipper: public Iterable
    {
    public:
        Zipper(std::vector<int> i, std::vector<std::string> s);
        std::unique_ptr<IterableIterator> ConstBegin()const override;
        std::unique_ptr<IterableIterator> ConstEnd()const override;
    };
    class Product : public Iterable
    {
    public:
        Product(std::vector<int> vector, std::vector<std::string> vector1);
        std::unique_ptr<IterableIterator> ConstBegin()const override;
        std::unique_ptr<IterableIterator> ConstEnd()const override;
    };
    class Enumerate : public Iterable
    {
    public:
        Enumerate(std::vector<std::string> vector);
        std::unique_ptr<IterableIterator> ConstBegin()const override;
        std::unique_ptr<IterableIterator> ConstEnd()const override;
    };
}



#endif //JIMP_EXERCISES_ITERABLE_H

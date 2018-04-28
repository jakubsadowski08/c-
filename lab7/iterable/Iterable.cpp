//
// Created by sad on 21.04.18.
//

#include "Iterable.h"


utility::ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left_begin,
                                        std::vector<std::string>::const_iterator right_begin,
                                        std::vector<int>::const_iterator left_end,
                                        std::vector<std::string>::const_iterator right_end) {
    left_ = left_begin;
    right_ = right_begin;

}

std::pair<int, std::string> utility::ZipperIterator::Dereference() const {
    auto x = std::make_pair(*left_,*right_);
    return x;
}

utility::IterableIterator &utility::ZipperIterator::Next() {
    left_++;
    right_++;
    return *this;
}

bool utility::ZipperIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
    if(left_ != other->left_ || right_ != other->right_)
        return true;
    else
        return false;
}

utility::ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left_begin,
                                        std::vector<std::string>::const_iterator right_begin) {
    left_ = left_begin;
    right_ = right_begin;
}

utility::IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<utility::IterableIterator> iterator) {
    iter = std::move(iterator);
}

bool utility::IterableIteratorWrapper::operator!=(const utility::IterableIteratorWrapper &other) const {
    return iter ->NotEquals(other.iter);
}

std::pair<int, std::string> utility::IterableIteratorWrapper::operator*() const {
    return iter->Dereference();
}

utility::IterableIteratorWrapper &utility::IterableIteratorWrapper::operator++() {
        iter->Next();
    return *this;
}
utility::Zipper::Zipper(std::vector<int> i, std::vector<std::string> s) {
    auto fir = i.size();
    auto sec = s.size();
    if (fir>=sec)
    {
        for (auto x=sec; x != fir; x++)
        {
            s.emplace_back(s.back());
        }
    }
    else
    {
        for (auto x = i.size(); x != s.size(); x++)
        {
            i.emplace_back(i.back());
        }
    }
    p_ = std::make_pair(i,s);

}

std::unique_ptr<utility::IterableIterator> utility::Zipper::ConstBegin() const {
    ZipperIterator z = ZipperIterator(p_.first.begin(),p_.second.begin());
    return std::make_unique<ZipperIterator>(z);

}
std::unique_ptr<utility::IterableIterator> utility::Zipper::ConstEnd() const {
    ZipperIterator z = ZipperIterator(p_.first.end(),p_.second.end());
    return std::make_unique<ZipperIterator>(z);
}


utility::IterableIteratorWrapper utility::Iterable::cend() const {
    return IterableIteratorWrapper(ConstEnd());
}

utility::IterableIteratorWrapper utility::Iterable::cbegin() const {
    return IterableIteratorWrapper(ConstBegin());
}
utility::IterableIteratorWrapper utility::Iterable::end() const {
    return cend();
}

utility::IterableIteratorWrapper utility::Iterable::begin() const {
    return cbegin();
}

utility::Product::Product(std::vector<int> vector, std::vector<std::string> vector1) {
    std::vector <int> i;
    std::vector<std::string> s;
    for(auto x : vector)
    {
        for(auto v : vector1)
        {
            i.emplace_back(x);
            s.emplace_back(v);
        }
    }
    p_ = std::make_pair(i,s);
}
std::unique_ptr<utility::IterableIterator> utility::Product::ConstBegin() const {
    ZipperIterator z = ZipperIterator(p_.first.begin(),p_.second.begin());
    return std::make_unique<ZipperIterator>(z);

}
std::unique_ptr<utility::IterableIterator> utility::Product::ConstEnd() const {
    ZipperIterator z = ZipperIterator(p_.first.end(),p_.second.end());
    return std::make_unique<ZipperIterator>(z);
}

utility::Enumerate::Enumerate(std::vector<std::string> vector) {
    std::vector<int> v(vector.size());
    int i = 1;
    for(auto x : vector)
    {
        v[i-1] = i;
        i++;
    }
    p_ = std::make_pair(v,vector);
}
std::unique_ptr<utility::IterableIterator> utility::Enumerate::ConstBegin() const {
    ZipperIterator z = ZipperIterator(p_.first.begin(),p_.second.begin());
    return std::make_unique<ZipperIterator>(z);

}
std::unique_ptr<utility::IterableIterator> utility::Enumerate::ConstEnd() const {
    ZipperIterator z = ZipperIterator(p_.first.end(),p_.second.end());
    return std::make_unique<ZipperIterator>(z);
}
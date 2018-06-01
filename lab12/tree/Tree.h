//
// Created by sadojaku on 30.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H
#include<iostream>
#include <memory>

namespace tree
{
    template <class Element>
    class Tree {
    public:
        Tree();
        Tree(const Element &e);
        Tree(const std::initializer_list<Element> &elements);
        void Insert(const Element &e);
        bool Find(const Element &e);
        size_t Depth();
        size_t Size();
        Tree<Element> * Root();
        Element Value();
        std::unique_ptr<Tree> left;
        std::unique_ptr<Tree> right;
        Element value;
        size_t sized;
    };

    template <class T>
    Tree<T>::Tree() {
        left = nullptr;
        right = nullptr;
        value = T();
        sized = 0;
    }
    template <class Element>
    Tree<Element>::Tree(const Element &e) {
        left = nullptr;
        right = nullptr;
        value = e;
        sized = sized + 1;
    }
    template <class Element>
    Tree<Element>::Tree(const std::initializer_list<Element> &elements) {
        left = nullptr;
        right = nullptr;
        for(auto x:elements)
        {
            value = x;
        }
        sized = 1;
    }
    template <class Element>
    Element Tree<Element>::Value() {
        return value;
    }
    template <class Element>
    void Tree<Element>::Insert(const Element &e) {
        auto tmp = this;

        while ( true ) {
            if (e > tmp->value) {
                if(tmp->right)
                {
                    tmp = tmp->right.get();
                } else{
                    tmp->right = std::make_unique<Tree<Element>>(e);
                    sized++;
                    break;
                }
            } else {
                if(tmp->left)
                {
                    tmp = tmp->left.get();
                } else{
                    tmp->left = std::make_unique<Tree<Element>>(e);
                    sized++;
                    break;
                }
            }
        }
    }
    template <class Element>
    bool Tree<Element>::Find(const Element &e) {
        auto tmp = this;
        while ( tmp )
        {
            if (e > tmp->value)
            {
                tmp = tmp->right.get();
            }
            else if(e == tmp->value)
            {
                return true;
            } else
            {
                tmp = tmp->left.get();
            }
        }
        return false;
    }
    template <class Element>
    size_t Tree<Element>::Depth() {
        if(this == nullptr)
        {
            return 0;
        }
        size_t lefts = left->Depth();
        size_t rights = right->Depth();

        if(lefts < rights)
        {
            return rights + 1;
        } else
        {
            return lefts + 1;
        }
    }

    template<class Element>
    size_t Tree<Element>::Size() {
        return sized;
    }

    template<class Element>
    Tree<Element> * Tree<Element>::Root() {
        return this;
    }


}


#endif //JIMP_EXERCISES_TREE_H
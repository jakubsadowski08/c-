//
// Created by sad on 01.06.18.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H
#include "../../lab12/tree/Tree.h"
#include<vector>
namespace tree
{

    template<class T>
    class InOrderTreeIterator
    {
    public:
        InOrderTreeIterator();
        InOrderTreeIterator(Tree<int> * root);
        Tree<int> * operator++()
        {
            ++indice;
        }
        int operator*()
        {
            return vec[indice]->value;
        }
        InOrderTreeIterator operator =(InOrderTreeIterator other)
        {
            return *this;
        }
        void Add(Tree<int> * root);
        std::vector<Tree<int> * > vec;
        int indice;

    };

    template<class T>
    InOrderTreeIterator<T>::InOrderTreeIterator(Tree<int> * roots) {
        indice = 0;
        Add(roots);
    }

    template<class T>
    void InOrderTreeIterator<T>::Add(Tree<int> *root) {
        if(root != nullptr)
        {
            Add(root->left.get());
            vec.emplace_back(root);
            Add(root->right.get());
        }

    }

    template<class T>
    InOrderTreeIterator<T>::InOrderTreeIterator() {
        indice = 0;
    }
    template<class T>
    class InOrderTreeView
    {
    public:
        InOrderTreeView();
        InOrderTreeView(Tree<int> *roots);
        InOrderTreeIterator<T> begin();
        InOrderTreeIterator<T> end();
        void Add(Tree<int> * root);
        int indice;
        std::vector<Tree<int> * > vec;
    };

    template<class T>
    InOrderTreeView<T>::InOrderTreeView(Tree<int> *roots) {
        this->indice = 0;
        this->Add(roots);
    }


    template<class T>
    InOrderTreeIterator<T> InOrderTreeView<T>::begin() {
        auto w = InOrderTreeIterator<T>();
        w.indice = 0;
        w.vec = vec;
        return w;
    }

    template<class T>
    InOrderTreeIterator<T> InOrderTreeView<T>::end() {
        auto w = InOrderTreeIterator<T>();
        w.vec = vec;
        w.indice = w.vec.size();
        return w;
    }

    template<class T>
    void InOrderTreeView<T>::Add(Tree<int> *root) {
        if(root != nullptr)
        {
            Add(root->left.get());
            vec.emplace_back(root);
            Add(root->right.get());
        }
    }

    template<class T>
    InOrderTreeView<T>::InOrderTreeView() {
    indice = 0;
    }

    InOrderTreeView<int> InOrder(Tree<int> *tree) {
        return InOrderTreeView<int>(tree);
    }


    bool operator !=(tree::InOrderTreeIterator<int> s, tree::InOrderTreeIterator<int> sd)
    {
        return s.indice != sd.indice;
    }

}



#endif //JIMP_EXERCISES_TREEITERATORS_H

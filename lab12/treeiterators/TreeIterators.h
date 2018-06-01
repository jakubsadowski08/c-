//
// Created by sad on 01.06.18.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H
#include "../../lab12/tree/Tree.h"
#include<vector>
namespace tree {

    template<class T>
    class InOrderTreeIterator {
    public:
        InOrderTreeIterator();

        InOrderTreeIterator(Tree<int> *root);

        Tree<int> *operator++() {
            ++indice;
        }

        int operator*() {
            return vec[indice]->value;
        }

        InOrderTreeIterator operator=(InOrderTreeIterator other) {
            return *this;
        }

        void Add(Tree<int> *root);

        std::vector<Tree<int> *> vec;
        int indice;

    };

    template<class T>
    InOrderTreeIterator<T>::InOrderTreeIterator(Tree<int> *roots) {
        indice = 0;
        Add(roots);
    }

    template<class T>
    void InOrderTreeIterator<T>::Add(Tree<int> *root) {
        if (root != nullptr) {
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
    class InOrderTreeView {
    public:
        InOrderTreeView();

        InOrderTreeView(Tree<int> *roots);

        InOrderTreeIterator<T> begin();

        InOrderTreeIterator<T> end();

        void Add(Tree<int> *root);

        int indice;
        std::vector<Tree<int> *> vec;
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
        if (root != nullptr) {
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


    bool operator!=(tree::InOrderTreeIterator<int> s, tree::InOrderTreeIterator<int> sd) {
        return s.indice != sd.indice;
    }

    template<class T>
    class PostOrderTreeIterator {
    public:
        PostOrderTreeIterator();

        PostOrderTreeIterator(Tree<T> *root);

        Tree<T> *operator++() {
            ++indice;
        }
        T operator*() {
            return vec[indice]->value;
        }

        PostOrderTreeIterator operator=(PostOrderTreeIterator other) {
            return *this;
        }

        void Add(Tree<T> *root);

        std::vector<Tree<T> *> vec;
        int indice;

    };

    template<class T>
    PostOrderTreeIterator<T>::PostOrderTreeIterator(Tree<T> *roots) {
        indice = 0;
        Add(roots);
    }

    template<class T>
    void PostOrderTreeIterator<T>::Add(Tree<T> *root) {
        if (root != nullptr) {
            Add(root->left.get());
            Add(root->right.get());
            vec.emplace_back(root);
        }

    }

    template<class T>
    PostOrderTreeIterator<T>::PostOrderTreeIterator() {
        indice = 0;
    }



    template<class T>
    class PostOrderTreeView {
    public:
        PostOrderTreeView();

        PostOrderTreeView(Tree<T> *roots);

        PostOrderTreeIterator<T> begin();

        PostOrderTreeIterator<T> end();

        void Add(Tree<T> *root);

        int indice;
        std::vector<Tree<T> *> vec;
    };

    template<class T>
    PostOrderTreeView<T>::PostOrderTreeView(Tree<T> *roots) {
        this->indice = 0;
        this->Add(roots);
    }


    template<class T>
    PostOrderTreeIterator<T> PostOrderTreeView<T>::begin() {
        auto w = PostOrderTreeIterator<T>();
        w.indice = 0;
        w.vec = vec;
        return w;
    }

    template<class T>
    PostOrderTreeIterator<T> PostOrderTreeView<T>::end() {
        auto w = PostOrderTreeIterator<T>();
        w.vec = vec;
        w.indice = w.vec.size();
        return w;
    }

    template<class T>
    void PostOrderTreeView<T>::Add(Tree<T> *root) {
        if (root->left.get()) {
            Add(root->left.get());
        }
        if (root->right.get()) {
            Add(root->right.get());
        }
            vec.emplace_back(root);
        }

    template<class T>
    PostOrderTreeView<T>::PostOrderTreeView() {
        indice = 0;
    }
    template<typename T>
    PostOrderTreeView<T> PostOrder(Tree<T> *tree) {
        return PostOrderTreeView<T>(tree);
    }

    template<typename T>
    bool operator!=(tree::PostOrderTreeIterator<T> s, tree::PostOrderTreeIterator<T> sd) {
        return s.indice != sd.indice;
    }

    template<class T>
    class PreOrderTreeIterator {
    public:
        PreOrderTreeIterator();

        PreOrderTreeIterator(Tree<T> *root);

        Tree<T> *operator++() {
            ++indice;
        }
        T operator*() {
            return vec[indice]->value;
        }

        PreOrderTreeIterator operator=(PreOrderTreeIterator other) {
            return *this;
        }

        void Add(Tree<T> *root);

        std::vector<Tree<T> *> vec;
        int indice;

    };

    template<class T>
    PreOrderTreeIterator<T>::PreOrderTreeIterator(Tree<T> *roots) {
        indice = 0;
        Add(roots);
    }

    template<class T>
    void PreOrderTreeIterator<T>::Add(Tree<T> *root) {
        vec.emplace_back(root);
        if (root->left.get()) {
            Add(root->left.get());
        }
        if (root->right.get()) {
            Add(root->right.get());
        }

    }

    template<class T>
    PreOrderTreeIterator<T>::PreOrderTreeIterator() {
        indice = 0;
    }



    template<class T>
    class PreOrderTreeView {
    public:
        PreOrderTreeView();

        PreOrderTreeView(Tree<T> *roots);

        PreOrderTreeIterator<T> begin();

        PreOrderTreeIterator<T> end();

        void Add(Tree<T> *root);

        int indice;
        std::vector<Tree<T> *> vec;
    };

    template<class T>
    PreOrderTreeView<T>::PreOrderTreeView(Tree<T> *roots) {
        this->indice = 0;
        this->Add(roots);
    }


    template<class T>
    PreOrderTreeIterator<T> PreOrderTreeView<T>::begin() {
        auto w = PreOrderTreeIterator<T>();
        w.indice = 0;
        w.vec = vec;
        return w;
    }

    template<class T>
    PreOrderTreeIterator<T> PreOrderTreeView<T>::end() {
        auto w = PreOrderTreeIterator<T>();
        w.vec = vec;
        w.indice = w.vec.size();
        return w;
    }

    template<class T>
    void PreOrderTreeView<T>::Add(Tree<T> *root) {
        vec.emplace_back(root);
        if (root->left.get()) {
            Add(root->left.get());
        }
        if (root->right.get()) {
            Add(root->right.get());
        }

    }

    template<class T>
    PreOrderTreeView<T>::PreOrderTreeView() {
        indice = 0;
    }
    template<typename T>
    PreOrderTreeView<T> PreOrder(Tree<T> *tree) {
        return PreOrderTreeView<T>(tree);
    }

    template<typename T>
    bool operator!=(tree::PreOrderTreeIterator<T> s, tree::PreOrderTreeIterator<T> sd) {
        return s.indice != sd.indice;
    }
}


#endif //JIMP_EXERCISES_TREEITERATORS_H

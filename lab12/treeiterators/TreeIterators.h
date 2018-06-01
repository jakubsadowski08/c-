//
// Created by sad on 01.06.18.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H
#include "../../lab12/tree/Tree.h"
namespace tree
{
    class InOrder{

    };
    template<class T>
    class InOrderTreeIterator
    {
    public:
        InOrderTreeIterator(Tree<int> root);
        Tree<int> * operator++()
        {
            return iterat->left.get();
        }
        Tree<int> * iterat;

    };

    template<class T>
    InOrderTreeIterator<T>::InOrderTreeIterator(Tree<int> root) {
        Tree<int> * it = root.left.get();

    }

    class InOrderTreeView
    {

    };


}



#endif //JIMP_EXERCISES_TREEITERATORS_H

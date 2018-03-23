#include <ostream>
#include <string>
#include <memory>
std::string dump;
int x = 1;
#ifndef JIMP_EXERCISES_SMARTTREE_H
#define JIMP_EXERCISES_SMARTTREE_H
namespace datastructures
{
    struct SmartTree
    {
        int value;
        std::unique_ptr<SmartTree> left;
        std::unique_ptr<SmartTree>right;
        SmartTree() : value(0), left(nullptr), right(nullptr){ }
        SmartTree(int data, SmartTree * leftchild,SmartTree * rightchild):value(data),left(leftchild),right(rightchild){}
    };
    std::unique_ptr <SmartTree> CreateLeaf(int value)
    {
        std::unique_ptr<SmartTree> p = std::make_unique<SmartTree>(value,nullptr,nullptr);
        return p;
    }
    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree)
    {
        std::unique_ptr<SmartTree> new_root = std::move(tree);
        new_root->left =std::move(left_subtree);
        return new_root;
    }
    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree)
    {
        std::unique_ptr<SmartTree> new_root = std::move(tree);
        new_root->right =std::move(right_subtree);
        return new_root;
    }
    void PrintTreeInOrder(const std::unique_ptr<SmartTree> & unique_ptr, std::ostream *out)
    {
        if(unique_ptr->left)
        {
            PrintTreeInOrder(unique_ptr->left, out);
        }
        *out<<unique_ptr->value<<", ";
        if(unique_ptr->right)
        {
            PrintTreeInOrder(unique_ptr->right, out);
        }
    }
    std::string DumpTree(const std::unique_ptr<SmartTree> &tree)
    {
        if(tree->left && tree->right)
        {
            dump = dump + "[" + std::to_string(tree->value) + " ";
            DumpTree(tree->left);
            dump = dump +"] ";
            DumpTree(tree->right);
            dump = dump +"]";
        }
        else if(tree->left)
        {
            dump = dump + "[" + std::to_string(tree->value) + " ";
            DumpTree(tree->left);
            dump = dump + "[none]";
        }
        else if(tree->right)
        {
            dump = dump + "[" + std::to_string(tree->value) + " ";
            DumpTree(tree->right);
            dump = dump + "[none]";
            dump = dump +"] ";
        } else
        {
            dump = dump + "[" + std::to_string(tree->value) + " ";
            dump = dump + "[none] [none]";
        }
        return dump;
    }
}


#endif //JIMP_EXERCISES_SMARTTREE_H

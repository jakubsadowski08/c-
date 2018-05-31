#include "Tree.h"

int main()
{
    tree::Tree<int> tree {5};
    tree.Insert(0);
    std::cout<<tree.Value();
    auto tmp = *tree.left;
    std::cout<<tmp.Value();
}


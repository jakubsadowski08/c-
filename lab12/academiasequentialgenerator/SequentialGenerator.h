//
// Created by sad on 01.06.18.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template <class T,class TY>
class SequentialIdGenerator {
public:
    SequentialIdGenerator();
    SequentialIdGenerator(int a);
    auto NextValue();
private:
    int a;

};

template<class T, class TY>
SequentialIdGenerator<T, TY>::SequentialIdGenerator() {
    a =-1;
}

template<class T, class TY>
SequentialIdGenerator<T, TY>::SequentialIdGenerator(int x) {
    a = x-1;
}

template<class T, class TY>
auto SequentialIdGenerator<T, TY>::NextValue() {
    ++a;
    return a;
}


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H

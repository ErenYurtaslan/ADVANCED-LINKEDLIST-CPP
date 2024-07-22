

#ifndef DUGUM_HPP
#define DUGUM_HPP

#include "Sayi.hpp"

class Dugum {
public:
    Sayi* sayi;
    Dugum* sonraki;

    Dugum(Sayi* sayi);
};

#endif // DUGUM_HPP

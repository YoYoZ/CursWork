//
//  fileIO.hpp
//  Kursach
//
//  Created by Anton Solyarik on 24.04.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#ifndef fileIO_hpp
#define fileIO_hpp

#include <stdio.h>
#include <string>
#include "Places.hpp"
#include "Cinema.hpp"
#include "Theater.hpp"

#endif /* fileIO_hpp */

using namespace std;

class FileIO
{
public:
    CultPlace* readObject();
};

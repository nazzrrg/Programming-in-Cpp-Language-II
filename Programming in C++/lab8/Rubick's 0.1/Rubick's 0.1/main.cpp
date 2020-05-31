//
//  main.cpp
//  Rubick's 0.1
//
//  Created by Егор Назаров on 17.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#include <iostream>
#include "cubeAPI.hpp"

int main(int argc, const char * argv[]) {
    
    rubicksCube object(100);
    
    object.run();
    
    return 0;
}

//
//  cubeSide.h
//  Rubick's 0.1
//
//  Created by Егор Назаров on 17.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#ifndef smallCubeSide_h
#define smallCubeSide_h
class smallCubeSide {
public:
    struct Point {
        float x, y;
    };
    Point topRight, topLeft, bottomRight, bottomLeft;
private:
    int nNum;
public:
    smallCubeSide(void);
    ~smallCubeSide(void);
    smallCubeSide(const smallCubeSide& other);
    void setNum (int n);
    int getNum();
    smallCubeSide& operator=(const smallCubeSide& other);
};

#endif /* smallCubeSide_h */

#include <vector>
#include <iostream>
#include "Interface.h"

int main() {
    std::vector<IFigure*> A;
    std::string s;
    std::cout << "'add %Figure_name%'('trapeze' or 'rectangle') to add that figure\n";
    std::cout << "'showAll' to draw all figures\n";
    std::cout << "'sortByMass' to sort objects by mass\n";
    std::cout << "'sumSquare' or 'sumPerimeter' to get summary square or perimeter respectively\n";
    std::cout << "'sumSize' to get summary size of all objects\n";
    std::cout << "'massCenter' to get mass center vector(x, y)\n";

    while (std::cin >> s) {
        if (s == "add") {
            std::cin >> s;
            transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return tolower(c);});
            if (s == "trapeze") {
                A.push_back(new Trapeze());
            } else if (s == "rectangle") {
                A.push_back(new Rectangle());
            } else {
                std::cout << "Wrong figure name, you entered '" << s << "' try again\n";
                continue;
            }
            A.back()->initFromDialog();
        } else if (s == "showAll") {
            for (auto &x : A) {
                x->draw();
            }
        } else if (s == "sumSquare") {
            double ans = 0;
            for (auto& x : A) {
                ans += x->getSquare();
            }
            std::cout << "Overall square = " << ans << std::endl;
        } else if (s == "sumPerimeter") {
            double ans = 0;
            for (auto& x : A) {
                ans += x->getPerimeter();
            }
            std::cout << "Overall perimeter = " << ans << std::endl;
        } else if (s == "sumSize") {
            double ans = 0;
            for (auto& x : A) {
                ans += x->getSize();
            }
            std::cout << "Overall size = " << ans << std::endl;
        } else if (s == "sortByMass") {
            sort(A.begin(), A.end(), [](IFigure* x, IFigure* y) {return *x < *y;});
            std::cout << "Sorted." << std::endl;
        } else if (s == "massCenter") {
            Vector2D center;
            double massSum = 0;
            for (auto& x : A) {
                center.x += x->getPosition().x * x->getMass();
                center.y += x->getPosition().y * x->getMass();
                massSum += x->getMass();
            }
            center.x /= massSum;
            center.y /= massSum;
            std::cout << "Mass center = (" << center.x << "; " << center.y << ")" << std::endl;
        } else {
            std::cout << "wrong command, you entered '" << s << "' try again" << std::endl;
            continue;
        }
    }
    return 0;
}
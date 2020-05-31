#include <iostream>
#include <vector>

class CPolynomial {
private:
    std::vector<int> coef_;
    int max_power_;
public:
    enum {default_size=100};
    explicit CPolynomial (int size = default_size) {
        max_power_ = size;
        coef_.resize(max_power_);
    }
    explicit CPolynomial(const std::vector<int>& input) {
        max_power_ = input.size();
        coef_ = input;
    }
    CPolynomial(const CPolynomial& ref) = default;
    CPolynomial& operator+(const CPolynomial& rhs) {
        int max_power = (std::max(max_power_, rhs.max_power_));
        std::vector<int> res(max_power, 0);
        for (int i = 0; i < max_power; i++) {
            if (i >= max_power_ && i < rhs.max_power_) {
                res[i] = rhs.coef_[i];
            } else if (i < max_power_ && i >= rhs.max_power_) {
                res[i] = coef_[i];
            } else {
                res[i] = this->coef_[i] + rhs.coef_[i];
            }
        }
        coef_ = res;
        this->max_power_ = max_power;
        return *this;
    }
    CPolynomial& operator-(const CPolynomial& rhs) {
        int max_power = (std::max(max_power_, rhs.max_power_));
        std::vector<int> res(max_power, 0);
        for (int i = 0; i < max_power; i++) {
            if (i >= max_power_ && i < rhs.max_power_) {
                res[i] = -1*rhs.coef_[i];
            } else if (i < max_power_ && i >= rhs.max_power_) {
                res[i] = coef_[i];
            } else {
                res[i] = this->coef_[i] - rhs.coef_[i];
            }
        }
        coef_ = res;
        this->max_power_ = max_power;
        return *this;
    }
    int& operator[](size_t index) {
        if (index >=0 && index < max_power_) {
            return coef_[index];
        } else {
            throw std::runtime_error("Index subscript out of range");
        }
    }
};



int main() {





    return 0;
}

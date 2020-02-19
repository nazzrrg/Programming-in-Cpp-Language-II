#include <cstdint>
#include "task_4.h"

void floory (float& a) {
    int64_t b;
    b = int64_t(a);
    a = float(b);
}
void floory (float* a) {
    int64_t b;
    b = int64_t(*a);
    *a = float(b);
}
void floory (double& a) {
    int64_t b;
    b = int64_t(a);
    a = double(b);
}
void floory (double* a) {
    int64_t b;
    b = int64_t(*a);
    *a = double(b);
}
#pragma once

#include <exception>

int64_t Multiply(int32_t a, int32_t b) {
    return std::static_cost<int64_t>(a)*std::static_cost<int64_t>(b);
}

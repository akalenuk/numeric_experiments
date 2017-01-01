#include <array>
#include <cmath>
#include <array>

namespace polynomial_synthesis
{
    template <int N>
    std::array<double, N> p(double x){
        std::array<double, N> ret;
        for(int i = 0; i < N; i++){
            ret[i] = std::pow(x, i);
        }
        return ret;
    }

    template <int N>
    std::array<double, N> dp(double x, int d){
        std::array<double, N> ret;
        for(int i = 0; i < N; i++){
            if(i < d){
                ret[i] = 0.0;
            }else{
                ret[i] = pow(x, i - d);
                for(int j = i; j > i-d; j--){
                    ret[i] *= j;
                }
            }
        }
        return ret;
    }

    template <int N>
    std::array<double, N> ip(double x1, double x2, int d){
        std::array<double, N> ret;
        for(int i = 0; i < N; i++){
            ret[i] = pow(x2, i + d) - pow(x1, i + d);
            for(int j = i; j < i+d; j++){
                ret[i] /= j+1;
            }
        }
        return ret;
    }
}


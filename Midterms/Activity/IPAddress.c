#include <stdio.h>

typedef unsigned char address[4];
typedef struct{
    address add;
    address sm;
}IpAdd;

int isSameNetwork(IpAdd add1, IpAdd add2)
{
    address mask = {255 - add1.sm[0], 255 - add1.sm[1], 255 - add1.sm[2], 255 - add1.sm[3]};
    int i, ret = 1, sum, addr;
    for(i = 0; i < 4; i++){
        if(add1.add[i] > add2.add[i]){
            sum = add1.add[i] - add2.add[i];
            addr = add1.add[i];
        }
        else {
            sum = add2.add[i] - add1.add[i];
            addr = add2.add[i];
        }
        if(sum != 0){
            if(mask[i] != 0){
                while(mask[i] < addr){
                    mask[i] += mask[i];
                }
                mask[i] -= addr;
            }
            if(sum > mask[i]){
                ret = 0;
                break;
            }
        }
    }
    return ret;
}

typedef struct{
    unsigned int bit: 8;
}sample;

int main()
{
    // IpAdd add1 = {{192, 168, 1, 22}, {255, 255, 255, 192}};
    // IpAdd add2 = {{192, 168, 2, 1}, {255, 255, 255, 192}};
    // printf("%d", isSameNetwork(add1, add2));
    sample x;
    x.bit = 255;
    printf("%d", sizeof(x));
    return 0;
}
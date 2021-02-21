#include <cstdio>
#include <cstring>
#include <iostream>

#define u64 uint64_t
#define u32 uint32_t
#define s32 int32_t


#define MAX_DIGITS 1000001


int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        char number[MAX_DIGITS] = {};
        scanf("%s", number);
        u32 numDigits = strlen(number);

        s32 fhIndex = (numDigits / 2) - 1;
        if (fhIndex < 0) fhIndex = 0;
        u32 incrementBy = 1;
        while (incrementBy == 1 && fhIndex >= 0)
        {
            s32 lhIndex = (numDigits - 1) - fhIndex;
            if (number[fhIndex] > number[lhIndex])
            {
                incrementBy = 0;
            }
            fhIndex--;
        }


        s32 fhIndexInclusiveOfMid = (numDigits - 1) / 2;
        for (fhIndex = fhIndexInclusiveOfMid; fhIndex >= 0; fhIndex--)
        {
            u32 val = ((u32)(number[fhIndex] - '0')) + incrementBy;
            if (val < 10) incrementBy = 0;
            val = val % 10;
            s32 lhIndex = (numDigits - 1) - fhIndex;

            number[fhIndex] = ('0' + val);
            number[lhIndex] = ('0' + val);
        }

        if (incrementBy == 1)
        {
            number[numDigits - 1] = '0' + 1;
            number[numDigits] = 0;
            printf("1%s\n", number);
        }
        else { printf("%s\n", number); }
    }
}
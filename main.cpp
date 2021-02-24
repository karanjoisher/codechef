#include <cstdio>
#include <cstring>
#include <iostream>

#define u64 uint64_t
#define u32 uint32_t
#define s32 int32_t


#define MAX_DIGITS 1000001
char number[MAX_DIGITS] = {};

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {

        scanf("%s", number);
        u32 numDigits = strlen(number);

        s32 fhIndex = (numDigits / 2) - 1;
        if (fhIndex < 0) fhIndex = 0;
        s32 lhIndex = (numDigits - 1) - fhIndex;

        while (fhIndex > 0 && number[fhIndex] == '0') fhIndex--; //Eat leading zeroes
        while (lhIndex < numDigits - 1 && number[lhIndex] == '0') lhIndex++; //Eat leading zeroes

        u32 incrementBy;
        u32 numDigitsInFh = (fhIndex + 1);
        u32 numDigitsInLh = (numDigits - lhIndex);
        if (numDigitsInFh > numDigitsInLh)
        {
            incrementBy = 0;
        }
        else if (numDigitsInFh < numDigitsInLh)
        {
            incrementBy = 1;
        }
        else
        {
            incrementBy = 1;
            while (fhIndex >= 0 && lhIndex < numDigits)
            {
                if (number[fhIndex] > number[lhIndex])
                {
                    incrementBy = 0;
                    break;
                }
                else if (number[fhIndex] < number[lhIndex])
                {
                    break;
                }

                fhIndex--;
                lhIndex++;
            }
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
#include <iostream>
#include <stdint.h>
#include <math.h>  
#include <string.h>
#include <algorithm>
using namespace std;
#define u64 uint64_t
#define u32 uint32_t
#define s32 int32_t

#define MAX_QUEUE_SIZE 10000

u64 marksArr[MAX_QUEUE_SIZE];
u64 marksArrLength;

int main()
{
    s32 T, N, K, E, M;
    u64 totalMarks, marks, maxSize;
    cin >> T;
    while (T--)
    {
        cin >> N >> K >> E >> M;
        marksArrLength = 0;
        maxSize = N - K;

        for (s32 i = 0; i < N; i++)
        {
            totalMarks = 0;
            s32 knownExamScores = i != (N - 1) ? E : (E - 1);

            for (s32 j = 0; j < knownExamScores; j++)
            {
                cin >> marks;
                totalMarks += marks;
            }

            if (i != (N - 1)) marksArr[i] = totalMarks;
        }

        sort(marksArr, marksArr+(N-1));
        u64 lowestScoreToBeat = marksArr[maxSize - 1];
        u64 marksRequired = (lowestScoreToBeat < totalMarks) ? 0 : ((lowestScoreToBeat + 1) - totalMarks);

        if (marksRequired > M)
        {
            cout << "Impossible\n";
        }
        else
        {
            cout << marksRequired << "\n";
        }
    }

    return 0;
}
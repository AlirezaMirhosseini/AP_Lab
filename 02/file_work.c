#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll arr[], ll n)
{
    ll ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        ans = ((arr[i] * ans) / (gcd(arr[i], ans)));
    }
    return ans;
}

int main(int argc, const char *argv[])
{
    ll *nums = (ll *)malloc(argc * sizeof(ll));
    int *strings = (int *)malloc(argc * sizeof(int));
    char buff[5];
    int countNums = 0, countStrings = 0, numRun, inputNums = 0;
    for (int i = 1; i < argc; i++)
    {
        if (strspn(argv[i], "0123456789") == strlen(argv[i]))
        {
            nums[countNums++] = atoll(argv[i]);
        }
        else
        {
            strings[countStrings++] = (int)strlen(argv[i]);
        }
    }
    FILE *out = fopen("9931583.txt", "a+");
    FILE *in = fopen("file.txt", "r");
    FILE *help = fopen("help.txt", "r");
    fread(&buff, sizeof(int), 1, help);
    numRun = atoi(buff);
    fprintf(out, "%d\n", countStrings);
    for (int i = 0; i < countStrings; i++)
    {
        fprintf(out, "%d\n", strings[i]);
    }
    if (countNums > 1)
    {
        for (int i = 0; i < numRun; i++)
        {
            fscanf(in, "%d", &inputNums);
        }
        ll ans = lcm(nums, countNums);
        ans += inputNums;
        fprintf(out, "%lld\n", ans);
    }
    else
    {
        fprintf(out, "none\n");
    }
    fprintf(out, "---------------\n");
    bzero(buff, 5);
    sprintf(buff, "%d", numRun + 1);
    fclose(help);
    help = fopen("help.txt", "w");
    fwrite(&buff, sizeof(buff), 1, help);
    return 0;
}
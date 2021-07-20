//   BY   : Shapour Discover
//   DATE : 2021-03-09
//   TIME : 21:39

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable:4996)

typedef struct player
{
    char name[100];
    int tedadteam_bazikon;
} player;
typedef struct teamha
{
    char name_team[100];
    int tedadbazikon_team;
    char asmai_baikonan[200][100];
    int tedad;
} teamha;
player bazikon[5500];
teamha team[200];
char asami_team_motekhalef[200][100];
int counter_motekhalef, num_bazikonan, num_team;
int tedad_team_bazikonan(int n, int m)
{
    for (int i = 0; i < num_bazikonan; i++)
    {
        if (strcmp(team[n].asmai_baikonan[m], bazikon[i].name) == 0)
        {
            bazikon[i].tedadteam_bazikon++;
            return 0;
        }
    }
    return 1;
}
int check(int n)
{
    for (int i = 0; i < counter_motekhalef; i++)
    {
        if (strcmp(asami_team_motekhalef[i], team[n].name_team) == 0)
        {
            return 0;
        }
    }
    return 1;
}
void tartib_alefba()
{
    for (int i = 0; i < counter_motekhalef; i++)
    {
        for (int j = i + 1; j < counter_motekhalef; j++)
        {
            if (strcmp(asami_team_motekhalef[i], asami_team_motekhalef[j]) > 0)
            {
                char temp[100];
                strcpy(temp, asami_team_motekhalef[i]);
                strcpy(asami_team_motekhalef[i], asami_team_motekhalef[j]);
                strcpy(asami_team_motekhalef[j], temp);
            }
        }
    }
}
int main()
{


    char v[3];
    scanf("%d%d", &num_bazikonan, &num_team);
    gets(v);
    for (int i = 0; i < num_bazikonan; i++)
    {

        gets(bazikon[i].name);
    }

    for (int i = 0; i < num_team; i++)
    {
        gets(team[i].name_team);
        int bool = 1;
        scanf("%d", &team[i].tedadbazikon_team);
        gets(v);
        for (int j = 0; j < team[i].tedadbazikon_team; j++)
        {
            gets(team[i].asmai_baikonan[j]);

            if (tedad_team_bazikonan(i, j))
            {
                if (bool)
                {
                    bool = 0;
                    strcpy(asami_team_motekhalef[counter_motekhalef], team[i].name_team);
                    counter_motekhalef++;
                }
            }
        }
    }
    for (int i = 0; i < num_bazikonan; i++)
    {
        if (bazikon[i].tedadteam_bazikon > 1)
        {
            for (int j = 0; j < num_team; j++)
            {
                for (int k = 0; k < team[j].tedadbazikon_team; k++)
                {
                    if (strcmp(team[j].asmai_baikonan[k], bazikon[i].name) == 0 && check(j))
                    {
                        strcpy(asami_team_motekhalef[counter_motekhalef], team[j].name_team);
                        counter_motekhalef++;
                        break;
                    }
                }
            }
        }
    }
    tartib_alefba(asami_team_motekhalef);
    for (int i = 0; i < counter_motekhalef; i++)
    {
        printf("%s\n", asami_team_motekhalef[i]);
    }
}
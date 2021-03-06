#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class ListNode
{
    public:
    ListNode* next;
    int val;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};


class Solution
{
    public:
    ListNode* listCycle(ListNode* A)
    {
        ListNode* tortoise = A;
        ListNode* hare = A;
        do
        {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if(!hare->next || !hare)
                return NULL;
        }while(hare != tortoise);
        tortoise = A;
        while(hare != tortoise)
        {
            hare = hare->next;
            tortoise = tortoise->next;
        }
        return tortoise;
    }
};

int main()
{
    vector<int> L = {262,91433,21544,30932,75087,88661,66097,1940,14883,22302,54993,48828,68623,20529,45656,30325,93374,5056,33388,21243,30282,25401,49400,83528,98429,5475,52352,61287,44321,36820,23207,23974,88356,7344,62137,5116,37813,54820,67654,28192,7700,16356,38798,39419,39881,18516,17152,77102,83569,81404,9313,93826,74660,84007,15995,22920,10895,36389,42023,25622,5782,67549,62918,36575,14221,42810,21657,34483,83900,70981,26311,75660,17336,66180,41254,74283,72977,73572,60482,33437,13885,2851,1471,35829,61016,66001,77072,31193,60844,5517,46130,4767,10630,55305,85719,39893,78161,58890,86345,23485,65777,23057,68667,16147,18942,64122,78634,29195,74131,71806,66866,19018,92041,98958,85402,11004,9325,96765,54149,79904,976,7574,25823,30735,27199,60519,85908,94644,88671,61554,4326,78926,89512,17732,72962,74975,14182,88195,23478,38333,55242,17041,52594,60190,59530,91311,84122,63063,19755,73281,97236,78544,51638,90512,63084,91368,28327,40964,1708,38443,88995,38481,29462,67481,17860,85175,97989,45160,2874,30190,72476,70507,6366,48291,71679,21304,79598,68310,59615,63492,15706,81115,43396,44434,2770,81019,42043,35491,50634,49868,2350,22972,53465,58869,70511,18269,87687,56522,15684,68806,63862,33492,58152,32231,60580,79507,24706,69782,61802,84697,91034,50328,9266,67200,3414,95987,38823,55819,47101,87001,1823,80662,36841,38445,14800,60389,72545,54148,34886,1966,36501,95219,70127,78348,47702,74,63043,16336,14620,16736,88846,59081,15537,85773,23813,73035,40107,41603,88854,52753,92712,28123,72660,29577,41374,45574,65475,36644,73769,44224,51370,42596,23916};
    int m = -1;
    ListNode* A = new ListNode(L[0]);
    ListNode* temp = A;
    ListNode* intersection;
    for(int i = 1; i < L.size(); i++)
    {
        temp->next = new ListNode(L[i]);
        temp = temp->next;
        if(i == m-1)
            intersection  = temp;
    }
    if(m != -1)
        temp->next = intersection;
    Solution* s = new Solution();
    A = s->listCycle(A);
    if(!A)
        cout << "NULL";
    else
        cout << A-> val;
    // while(A != NULL)
    // {
    //     cout << A->val << "\n";
    //     A = A->next;
    // }
}
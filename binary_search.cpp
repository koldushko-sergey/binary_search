/*
Чаще всего бинарный поиск (бинпоиск) используют, чтобы найти элемент в отсортированном массиве. 
Мы начинаем искать с середины массива. Если находим то, что нужно, или если больше нечего рассматривать, мы останавливаемся. 
В противном случае мы решаем, в каком направлении — вправо или влево от середины — мы должны продолжить поиск. 
Так как пространство поиска после каждой проверки делится на два, то время выполнения алгоритма — O(log n).
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bsearch(const vector<int> &arr, int l, int r, int q)
{
    while (l<=r)
    {
        int mid = l + (r-l)/2;
        if (arr[mid] == q) return mid;
        
        if (q < arr[mid]) {r = mid - 1;}
            else {l = mid + 1;}
    }
    return -1; //ничего не нашли
}

int main() 
{
    int query = 10;
    int arr[] = {2,4,6,8,10,12};
    int N = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + N);

    //сортируем входной массив
    sort(v.begin(), v.end());
    int indx;
    
    indx = bsearch(v, 0, v.size(), query);

    if (indx !=-1)
        cout << "бинарный поиск: нашли по индексу " << indx << "\n";   
    else
       cout << "бинарный поиск: не нашли";
    
    return 0;
}


//  杭电OJ1003 MaxSum
// Created by HuanyuLee on 2022/1/8.
//
#include <iostream>
#include <cmath>
using namespace std;
void getCrossMax(int arr[],int &L,int mid,int &R,int &max){
    int maxCross = 0,maxL = -1001,maxR = -1001,l = mid,r = mid+1;
    for (int i = mid; i >= L; --i){
        maxCross += arr[i];
        if (maxCross >= maxL){
            l = i;
            maxL = maxCross;
        }
    }
    for (int i = mid + 1, maxCross = 0; i <= R; ++i){
        maxCross += arr[i];
        if (maxCross > maxR){
            r = i;
            maxR = maxCross;
        }
    }
    max = maxL + maxR;
    L = l;
    R = r;
}
void getMax(int arr[],int &L,int &R,int &max){
    if (L < R){
        int l = L,r = R,maxL,maxR,maxCross;
        int m = (L+R)/2;
        int l1 = l,l2 = m+1,r1 = m,r2 = r;
        getMax(arr,l1,r1,maxL);
        getMax(arr,l2,r2,maxR);
        getCrossMax(arr,l,m,r,maxCross);
        int tempMax = maxL,tempL = l1,tempR = r1;
        if (tempMax < maxR){
            tempMax = maxR;
            tempL = l2;
            tempR = r2;
        }
        if (tempMax < maxCross){
            tempMax = maxCross;
            tempL = l;
            tempR = r;
            max = tempMax;
            L = tempL;
            R = tempR;
        }
        max = tempMax;
        L = tempL;
        R = tempR;
    } else
        max = arr[L];
}
int main(){
    int i,j = 1,n,m,L,R,max;
    int arr[100001];
    cin >> n;
    while (n--){
        cin >> m;
        for (i = 1; i <= m ; ++i) {
            cin >> arr[i];
        }
        L = 1;
        R = m;
        getMax(arr,L,R,max);
        cout << "Case " << j++ << ":\n" << max << " " << L << " " << R << endl;
        if (n != 0)
            cout << endl;
    }
    return 0;
}
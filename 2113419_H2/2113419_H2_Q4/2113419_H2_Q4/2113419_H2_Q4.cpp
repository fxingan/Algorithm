#include<algorithm>
#include<iostream>
using namespace std;
#define M 10000 
struct point {
    double x;
    double y;
};
point arr[M];//点的集合数组 
int a[M]; 
double dis(point arr1, point arr2){//两点之间距离函数
    return sqrt((arr2.y - arr1.y) * (arr2.y - arr1.y) + (arr2.x - arr1.x) * (arr2.x - arr1.x));
}
bool compare_y(const int& a, int& b){
    return arr[a].y < arr[b].y;
}
bool compare_xy(const point& arr1, point& arr2){
    if (arr1.x != arr2.x)
        return arr1.x < arr2.x;
    return arr1.y < arr2.y;
}
double divide(int left, int right){
    double d = INFINITY;   
    if (left == right) //只有一个点
        return d;    
    if (left + 1 == right)//只有两个点
        return dis(arr[left], arr[right]);
    int mid = (left + right) / 2;
    double d1 = divide(left, mid);
    double d2 = divide(mid + 1, right);
    d = min(d1, d2);
    int i, j, k = 0;
    for (i = left; i <= right; i++){
        if (fabs(arr[mid].x - arr[i].x) <= d) {
            a[k++] = i;
        }
    }
    sort(a, a + k, compare_y);
    for (i = 0; i < k - 1; i++)
    {
        for (j = i + 1; j < k && arr[a[j]].y - arr[a[i]].y < d; j++)
        {
            double distance = dis(arr[a[i]], arr[a[j]]);
            if (distance < d)
                d = distance;
        }
    }
    return d;
}
int main(){
    int  i, j, N;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr, arr + N, compare_xy);  
    cout << divide(0, N - 1);
    return 0;
}


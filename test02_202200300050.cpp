#include <iostream>
using namespace std;
template<class T>
void Bubble_sort(T *a,int size);
template<class T>
void Insert_sort(T *a,int size);
template<class T>
void Select_sort(T *a,int size);


template<class T>
void Bubble_sort(T *a,int size){
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size-i; j++)
        
            if (a[j]>a[j+1]) swap(a[j],a[j+1]);
    }
    
}

template<class T>
void Insert_sort(T *a,int size){
    for (int i = 1; i < size; i++)
    {
                    T t = a[i];
        int j;
        for (j=i-1;j>=0;j--)
        {
            if (a[j]>t)
            {
                a[j+1]=a[j];
            }else {
                break;
            }
        }
        a[j+1]=t;
    }
}

template<class T>
void Select_sort(T *a,int size){
    int min;
    for (int i = 0; i < size-1; i++)
    {
        min=i;
        for (int j = i+1; j < size; j++)
        {
            if (a[min]>a[j])
            {
                min = j;
            }
            
        }
        swap(a[i],a[min]);
    }
    
}


int main() {
    int a[18];
    cout << "Input" << endl;
    int m, len = 0;
    for (int i = 0; i < 18; i++) {
        cin >> m;
        if (m == 0) break;
        a[i] = m;
        len++;
    }
    cout << "1-Bubble Sort,2-Insert Sort,3-Select Sort" <<endl;
    int i;
    cin >> i;
    switch (i)
    {
    case 1:
        Bubble_sort(a,len);
        break;
    case 2:
        Insert_sort(a,len);
        break;
    case 3:
        Select_sort(a,len);
    default:
        break;
    }
    cout << "Output" << endl;
    switch (i)
    {
    case 1:
        cout << "Bubble Sort" <<endl;
        break;
    case 2:
        cout << "Insert Sort" <<endl;
        break;
    case 3:
        cout << "Select Sort" <<endl;
        break;
    default:
        break;
    }

    for (int j = 0; j < len-1; j++)
    {
        cout << a[j] << ",";
    }
    cout << a[len-1] << endl;
        cout << "end" << endl;
    return 0;
}
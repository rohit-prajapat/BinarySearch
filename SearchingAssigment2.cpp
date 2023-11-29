#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution{

public:
    vector<int>arr;
    void input()
    {
        cout<<"Ente size : ";
        int size; 
        cin>>size;
        cout<<"Enter Elements : ";
        int x;
        for(int i=0; i<size; i++)
        {
            cin>>x;
            arr.push_back(x);
        }
    }
    void solution1()
    {
        cout<<"\nQUESTION 1 : \n";
        cout<<"Write a program to apply binary search in array sorted in decreasing order."<<endl;
        cout<<"Array should sorted in Decrising Order : \n";
        input();
        cout<<"Enter Targer Value : ";
        int t;
        cin>>t;
        int si = 0;
        int ei = arr.size()-1;
        int ansIdx = -1;
        while(si<ei)
        {
            int mid = si + (ei-si)/2;
            if(arr[mid] == t) 
            {
                ansIdx = mid;
                break;
            }
            else if(arr[mid]>t)
            {
                si = mid+1;
            }
            else ei = mid-1;

        }
        cout<<"Answere of Question 1: is "<<ansIdx;

    }

    void solution2()
    {
        cout<<"QUESTION  2 :\n ";
        cout<<"You have a sorted array of infinite numbers, how would you search an element in the array?";
        input();

        int t;
        cout<<"Enter target ";
        cin>>t;

        int si = 0;
        int ei = 1;
        
        while(arr[ei]<t)
        {
            ei *=2;
        }

         int ansIdx = -1;
        while(si<ei)
        {
            int mid = si + (ei-si)/2;
            if(arr[mid] == t) 
            {
                ansIdx = mid;
                break;
            }
            else if(arr[mid]<t)
            {
                si = mid+1;
            }
            else ei = mid-1;

        }

        cout<<"Answere of Questio 2 : is "<<ansIdx;
        
    }

    void solution3()
    {
        cout<<"Enter row and matrix : ";
        int r,c;
        cin>>r>>c;

        int matrix[r][c];

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        cout<<"Enter target : ";
        int target;
        cin>>target;
        vector<int>arr;

        for(auto i : matrix)
        {
            for(int j; j<c; j++)
            {
                arr.push_back(j);
            }
        }

       int si =0;
       int ei = r * c-1;

        


       for(auto i : arr)
       {
           cout<<i<<" ";
       }
       cout<<endl;
        cout<<si<<" "<<ei<<endl;

        while(si<=ei)
        {
            int mid = si + (ei-si)/2;
            if(arr[mid] == target)
            {cout<<"Element is present : "; return ;}
            else if(arr[mid] >target) ei = mid - 1;
            else si = mid + 1;
        }
        cout<<"Element is not present : ";
        return ;
    }

    int binarySearch(vector<int>const & arr,int lo,int hi,int t)
    {
        
        while(lo<=hi)
        {
            int mid = lo + (hi - lo)/2;
            if(arr[mid] == t) return mid;
            else if(arr[mid]>t) hi = mid - 1;
            else lo = mid+ 1;

        }
        return -1;
    }

    void solution4()
    {
        cout<<" There is an integer array nums sorted in non-decreasing order (not necessarily withdistinct values).Before being passed to your function, nums is rotated at an unknown pivot index k ( 0 <= k< nums.length ) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1],nums[0], nums[1], ..., nums[k-1]] (0-indexed).\n";
        input();
        cout<<"Enter Target : ";
        int target ,t;
        cin>>t;
        target =t;
        int pivotIdx = -1;
        int size = arr.size();
        for(int i=0;i<size-1; i++)
        {
            if(arr[i]>arr[i+1])
            {
                pivotIdx = i;
                break;
            }
        }
       
    
    
        vector<int>nums ;
        nums = arr;
        size = nums.size() ;
         

        if(pivotIdx == -1)
        {
            cout<<"Ans of Question 4 : " << binarySearch(nums,0,size-1,target);
            return ;
        }

        int leftSize = binarySearch(nums,0,pivotIdx,target);
        if(leftSize != -1) 
        {
            cout<< "Ans of Question 4 : " <<leftSize;
            return ;
        }

        int rightSize = binarySearch(nums,pivotIdx+1,size-1,target);
        cout<<"Ans of Question 4 : " <<rightSize;
        return ;

    }
    
};
int main()
{
    Solution *s = new Solution();
    cout<<"Enter choice : ";
    int choice;
    cin>>choice;

    switch (choice)
    {
    case 1:
    system("CLS");
        s->solution1();
        break;
    case 2:
    system("CLS");
        s->solution2();
    case 3:
        system("CLS");
        s->solution3();
    case 4 : 
        s->solution4();
    default:
        break;
    }
}

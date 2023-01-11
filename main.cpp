#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;
class heap
{
public:
    vector<string> arr2;
    vector<int> arr1;
    void read_file()
    {
        ifstream my_file;
        vector<string> file1;
        my_file.open("task1.txt");
        string word;
        if(my_file.is_open())
        {
            while(getline(my_file,word))
            {
                stringstream ss;
                ss << word;
                string temp;
                int found1;
                string found2;
                while (!ss.eof())
                {
                    ss >> temp;
                    if(stringstream(temp) >> found1)
                    {
                        arr1.push_back(found1);
                    }
                    if(stringstream(temp) >> found2)
                    {
                        file1.push_back(found2);

                    }
                }

            }
            my_file.close();
        }
        else
        {
            cout<<" file isn't open "<<endl;
        }
        for(int i=0; i<file1.size(); i=i+2)
        {
            arr2.push_back(file1[i]);
        }
    }
    void heap1()
    {
        for (int i = arr1.size() / 2 - 1; i >= 0; i--)
		{
		    maxheap(arr1.size(),i);
		}
    }
    void maxheap(int size1,int i)
    {
        int l=2*i+1;
        int r=2*i+2;
        int max1=i;
        if(l<size1&&arr1[l]>arr1[max1])
        {
            max1=l;
        }
        if(r<size1&&arr1[r]>arr1[max1])
        {
           max1=r;
        }


        if(max1 != i)
        {
            int temp=arr1[i];
            arr1[i]=arr1[max1];
            arr1[max1]=temp;
            string temp2;
            temp2=arr2[i];
            arr2[i]=arr2[max1];
            arr2[max1]=temp2;
            maxheap(size1,max1);
        }

    }
    void print()
    {
        for (int i = 0; i < arr1.size(); i++)
        {
            cout << arr2[i] << " " <<arr1[i]<<endl;
        }
        cout << endl;

    }
    void insert1(int priority,string item)
    {
        arr1.push_back(priority);
        arr2.push_back(item);
        heap1();
    }
    void remove_root()
    {
        reverse(arr1.begin(),arr1.end());
        reverse(arr2.begin(),arr2.end());
        arr1.pop_back();
        arr2.pop_back();
        reverse(arr1.begin(),arr1.end());
        reverse(arr2.begin(),arr2.end());
        heap1();
    }
    void search1(string item)
    {
        for(int i=0;i<arr2.size();i++)
        {
            if(item==arr2[i])
            {
                cout<<"index: "<<i<<endl;
                break;
            }
            if(i==arr2.size()-1)
            {
                 cout<<"not found"<<endl;
            }
        }
    }
    void heapSort()
    {
        for (int i = arr1.size()-1; i >=0; i--)
        {
            int temp=arr1[i];
            arr1[i]=arr1[0];
            arr1[0]=temp;
            string temp2;
            temp2=arr2[i];
            arr2[i]=arr2[0];
            arr2[0]=temp2;
            maxheap(i, 0);
        }

    }
};
int main()
{
    heap p;
    p.read_file();
    p.heap1();
    int choice1;
    int choice2;
    int priority;
    string item;
    while(true)
    {
        do
        {
            cout<<"[1] insert"<<endl;
            cout<<"[2] removeRoot"<<endl;
            cout<<"[3] search"<<endl;
            cout<<"[4] print"<<endl;
            cout<<"choice: "<<endl;
            cin>>choice1;
        }
        while(choice1<=0 || choice1 > 4);
        switch(choice1)
        {
        case 1:
            cout<<"Enter priority: ";
            cin>>priority;
            cout<<"Enter item: ";
            cin>>item;
            p.insert1(priority,item);
            break;

        case 2:
            p.remove_root();
            break;

        case 3:
            cout<<"Enter item: ";
            cin>>item;
            p.search1(item);
            break;

        case 4:
            p.print();
            break;

        }
        cout<<"Do you want continue(1/0)"<<endl;
        cin>>choice2;
        if(choice2!=1)
        {
            break;
        }
    }
    p.heapSort();
    p.print();

    return 0;
}

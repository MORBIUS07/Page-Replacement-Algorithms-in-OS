#include <iostream>
#include <vector>
//<vector> header contains dynamic Array
#include <algorithm>
//it contains in built function like sort, min,max,search

using namespace std;

int main() 
{
    int n, frames;
    cout << "Enter number of page requests: ";
    cin >> n;
    cout << "Enter number of frames: ";
    cin >> frames;
    vector<int> pages(n);
    //Vector objects being created as name of pages with length n (it is dynamic array)
    cout << "Enter page requests: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> pages[i];
    }

    // FIFO Algorithm
    cout << "FIFO Algorithm\n";
    vector<int> fifo(frames, -1);
    //frames is the initial size of vector, each element initialize with -1
    int page_faults = 0;
    int i = 0;
    for (int page : pages) 
    //It is a range based for loop(foreach)
    {
        bool found = false;
        for (int j = 0; j < frames; j++) 
        {
            if (fifo[j] == page) 
            {
                found = true;
                break;
            }
        }
        if (!found) 
        {
            fifo[i % frames] = page;
            //i is current iteration
            i++;
            page_faults++;
        }
        for (int j = 0; j < frames; j++)
        {
            cout << fifo[j] << " ";
        }
        cout << endl;
    }
    cout << "Page Faults: " << page_faults << endl << endl;

    // LRU Algorithm
    cout << "LRU Algorithm\n ";
    vector<int> lru(frames, -1);
    //frames is the initial size of vector, each element initialize with -1
    page_faults = 0;
    i = 0;
    for (int page : pages) //foreach loop
    {
        bool found = false;
        for (int j = 0; j < frames; j++) 
        {
            if (lru[j] == page) 
            {
               
                found = true;
                lru.erase(lru.begin() + j);
                //lru is array from which element is erased 
                //erase is  function of algorithm 
                lru.push_back(page);
                break;
            }
        }
        if (!found) 
        {
            if (lru.size() == frames) 
            {
                lru.erase(lru.begin());
            }
            lru.push_back(page);
            page_faults++;
        }
        for (int j = 0; j < frames; j++) 
        {
            cout << lru[j] << " ";
        }
        cout << endl;
    }
    cout << "Page Faults: " << page_faults << endl << endl;

    // Optimal Algorithm
    cout << "Optimal Algorithm \n ";
    vector<int> optimal(frames, -1);
    page_faults = 0;
    i = 0;
    for (int page : pages) 
    {
        bool found = false;
        for (int j = 0; j < frames; j++) 
        {
            if (optimal[j] == page) 
            {
                found = true;
                break;
            }
        }
        if (!found) 
        {
            int index = -1;
            int farthest = -1;
            for (int j = 0; j < frames; j++) 
            {
                bool future_found = false;
                for (int k = i + 1; k < n; k++) 
                {
                    if (optimal[j] == pages[k]) 
                    {
                        future_found = true;
                        if (k > farthest) 
                        {
                            farthest = k;
                            index = j;
                        }
                        break;
                    }
                }
                if (!future_found) 
                {
                    index = j;
                    break;
                }
            }
            optimal[index] = page;
            page_faults++;
        }
        for (int j = 0; j < frames; j++) 
        {
            cout << optimal[j] << " ";
        }
        cout << endl;
    }
    cout <<"Page faults :";
    cout<<page_faults;

}

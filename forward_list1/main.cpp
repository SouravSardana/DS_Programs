#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> flist1 = {1,3,4}; //declaring and initializing
    forward_list<int> flist2,flist3; //declaring
    flist2.assign(3,5); // assigning 3 values 5 5 5.
    flist3.assign({8,6,5,9});
    for(int& x:flist1)   //printing forward list.
        cout<<x<<" ";
    cout<<endl;
    for(auto it=flist2.begin();it!=flist2.end();it++) // another method for printing forward_list
        cout<<*it<<" ";
    cout<<endl;
    for(auto it=flist3.begin();it!=flist3.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    flist1.push_front(2); //inserting at beginning
    flist1.emplace_front(6);// inserting at beginning without copy
    for(int& x:flist1)   //printing forward list. 6 2 1 3 4
        cout<<x<<" ";
    cout<<endl;
    flist1.pop_front(); //deleting an element from beginning
    for(int& x:flist1)   //printing forward list.  2 1 3 4
        cout<<x<<" ";
    cout<<endl;
    auto ptr = flist2.insert_after(flist2.begin(),4); //element 4 after first element 5 4 5 5
    ptr=flist2.emplace_after(ptr,2); //Since the iterator is at second element it will insert 2 after it 5 4 2 5 5
    flist2.erase_after(ptr); //ptr is at 3rd element i.e. 2 so 4th element will be deleted 5 4 2 5
    for(int &x: flist2)
        cout<<x<<" ";
    cout<<endl;
    flist2.remove(5); // remove all occurrences of 5..   4 2
    for(int &x: flist2)
        cout<<x<<" ";
    cout<<endl;
    flist3.reverse(); //For reversing the forward list
    for(auto it=flist3.begin();it!=flist3.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    flist3.sort(); //for sorting the forward list
    for(auto it=flist3.begin();it!=flist3.end();it++)
        cout<<*it<<" ";
    cout<<endl<<flist3.front(); // 5
    flist3.clear();
    cout<<endl<<flist3.empty(); // true or 1
    return 0;
}

#include <iostream>
#include <unordered_map>
using namespace std;
//map key->value maps key to value.
//map, unordred_map
//map -> sorted key, unordered_map;
int main()
{
    unordered_map <string,int> m;
    m.insert({"gfg",20});
    m["course"] = 15;
    m["gfg"]=30;
    //for(auto it=m.begin();it!=m.end();it++)
      //  cout<<it->first<<"->"<<it->second<<endl;
    for(auto x:m)
        cout<<x.first<<"->"<<x.second<<endl;
    cout<<m["gfg"];
    cout<<m.size();
    auto it=m.find("gf");
    if(it==m.end())
        cout<<"Element not found"<<endl;
    else
        cout<<it->second;
    m.count("gfg")?cout<<"Found":cout<<"Not found";
    m.erase("gfg");
    cout<<m.size();
}

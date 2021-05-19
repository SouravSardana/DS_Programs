#include <iostream>

using namespace std;

int main()
{
    string str;
    getline(cin,str);
    int start=0;
    for(int i=0;i<=str.length();i++)
    {
        if(str[i]==' ' || str[i]=='\0')
        {
            int ending=i-1;
            while(start<ending)
            {
                swap(str[start],str[ending]);
                start++;
                ending--;
            }
            start=i+1;
        }

    }
    cout<<str;
    return 0;
}

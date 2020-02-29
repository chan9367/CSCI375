#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <vector>
#include <time.h>

using namespace std;

int buffersize, s, c, pitem, citem;
int in=0,out=0,counter=0;
vector<int> buffer;

#define MAX_THREADS 2
DWORD WINAPI proThread(LPVOID);
DWORD WINAPI conThread(LPVOID);
HANDLE hThreads[MAX_THREADS];
DWORD id[MAX_THREADS];
DWORD waiter;

int main(){
cout<<"Enter buffer size: "; cin>>s; cout<<endl;
buffersize = s;
buffer.resize(buffersize);
cout<<"Enter counter limit: "; cin>>c; cout<<endl;

hThreads[0]=CreateThread(NULL,0,proThread,(LPVOID)0,NULL,&id[0]);
hThreads[1]=CreateThread(NULL,0,conThread,(LPVOID)0,NULL,&id[1]);
waiter = WaitForMultipleObjects(MAX_THREADS,hThreads,TRUE, INFINITE);
for(int i=0;i<MAX_THREADS;i++){
    CloseHandle(hThreads[i]);
}

return 0;

}

DWORD WINAPI proThread(LPVOID n){
    while(counter<c){              //as long as counter don't reach limit keep going
        while((in+1)==out);    //if buffer is full, don't do anything, i.e. when next in reaches out, its full
        pitem=rand();
        buffer[in]=pitem;                       //put random integer into buffer
        in++;
        if(in>buffersize)in=0;                  //make sure the whole buffer gets used, if in increments beyond buffer size, roll it back to 0
        counter++;
        cout<<pitem<<"\n";
    }
    return (DWORD)n;
}

DWORD WINAPI conThread(LPVOID n){
    while(counter<c){
        while(in==out);                    //buffer is empty, don't do anything
        citem=buffer[out];
        out++;
        if(out>buffersize)out=0;
        counter++;
        cout<<citem<<"\n";
    }
    return (DWORD)n;
}

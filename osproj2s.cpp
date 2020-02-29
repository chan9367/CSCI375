#include <iostream>                                     //Ke-vin Chan       OS project 2 Semaphore version
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
int fr1=0,fr2=0,fr3=0,fw1=0,fw2=0;
//flags to indicate each function has finished at least once so program don't actually run 10000 times
int r1pc=0,r2pc=0,r3pc=0,w1pc=0,w2pc=0;
//program counters
int j,k,l,m,n, cs=50, rs=2, wsem=1;
//global variables, including CS delay variables, buffer, and semaphores
bool flag();
//flag function to use the flag variables above
void wait(int s);                                               //wait function
void signal(int s);                                            //signal function
void panic(int x, int y);                                           //panic button
void reader1();
void reader2();
void reader3();
void writer1();
void writer2();

int main() {
  srand(time(NULL));
  for(int i=0;i<10000;i++){
    int pid=rand()%5;
    switch(pid){
      case 0 : reader1();break;
      case 1 : reader2();break;
      case 2 : reader3();break;
      case 3 : writer1();break;
      case 4 : writer2();break;
    }
    if(flag())break;
  }
}

void reader1(){
  switch(r1pc){
    case 0 : cout<<"R1 at counter: "<<r1pc<<"\tThis is reader1 starting point\n"; r1pc++;break;
    case 1 : cout<<"R1 at counter: "<<r1pc<<"\tThere are currently "<<rs+1<<" reader(s) outside the critical section\n"; r1pc++;break;
    case 2 : cout<<"R1 at counter: "<<r1pc<<"\tThere are currently "<<wsem+1<<" writer(s) outside the critical section\n"; r1pc++;break;
    case 3 : cout<<"R1 at counter: "<<r1pc<<"\tReader1 will now attempt to enter critical section";
                    if(rs<=0){wait(rs);r1pc--;}
                    else if(wsem<=0){wait(rs);r1pc--;}//since wait() is atomic, they're all in one case
                    else{wait(rs);rs--;}
                    r1pc++;break;//semaphore gate
    case 4 : cout<<"R1 at counter: "<<r1pc<<"\tReader1 reading buffer, which is: "<<cs<<"\n";r1pc++;break;
    case 5 : cout<<"R1 at counter: "<<r1pc<<"\tReader1 delaying the critical section to make sure the semaphore gate works\n";
                    j=0; r1pc++;break;
    case 6 : cout<<"R1 at counter: "<<r1pc;
                        if(j<=15){
                            cout<<"\tReader1 delaying the critical section to make sure the semaphore gate works\n";r1pc++;}
                        else {cout<<"\tReader1 delaying the critical section to make sure the semaphore gate works\n";r1pc = 8;} break;
    case 7 : cout<<"R1 at counter: "<<r1pc<<"\tReader1 delaying the critical section to make sure the semaphore gate works\n";
                        j++;r1pc--;break;
    case 8 : cout<<"R1 at counter: "<<r1pc<<"\tReader1 exiting critical section"; signal(rs);rs++;r1pc++;break;//exit of CS
    case 9 : cout<<"R1 at counter: "<<r1pc<<"\tThere are currently "<<rs+1<<" reader(s) outside the critical section\n"; r1pc++;break;
    case 10 : cout<<"R1 at counter: "<<r1pc<<"\tThere are currently "<<wsem+1<<" writer(s) outside the critical section\n"; r1pc++;break;
    case 11 : cout<<"R1 at counter: "<<r1pc<<"\tEnd point of reader1\n";fr1=1;r1pc=0;break;
  }
}
void reader2(){
  switch(r2pc){
    case 0 : cout<<"R2 at counter: "<<r2pc<<"\tThis is reader2 starting point\n"; r2pc++;break;
    case 1 : cout<<"R2 at counter: "<<r2pc<<"\tThere are currently "<<rs+1<<" reader(s) outside the critical section\n"; r2pc++;break;
    case 2 : cout<<"R2 at counter: "<<r2pc<<"\tThere are currently "<<wsem+1<<" writer(s) outside the critical section\n"; r2pc++;break;
    case 3 : cout<<"R2 at counter: "<<r2pc<<"\tReader2 will now attempt to enter critical section";
                    if(rs<=0){wait(rs);r2pc--;}
                    else if(wsem<=0){wait(rs);r2pc--;}//since wait() is atomic, they're all in one case
                    else{wait(rs);rs--;}
                    r2pc++;break;//semaphore gate
    case 4 : cout<<"R2 at counter: "<<r2pc<<"\tReader2 reading buffer, which is: "<<cs<<"\n";r2pc++;break;
    case 5 : cout<<"R2 at counter: "<<r2pc<<"\tReader2 delaying the critical section to make sure the semaphore gate works\n";
                    k=0; r2pc++;break;
    case 6 : cout<<"R2 at counter: "<<r2pc;
                    if(k<=15){
                        cout<<"\tReader2 delaying the critical section to make sure the semaphore gate works\n";r2pc++;}
                    else {cout<<"\tReader2 delaying the critical section to make sure the semaphore gate works\n";r2pc = 8;} break;
    case 7 : cout<<"R2 at counter: "<<r2pc<<"\tReader2 delaying the critical section to make sure the semaphore gate works\n";
                    k++;r2pc--;break;
    case 8 : cout<<"R2 at counter: "<<r2pc<<"\tReader2 exiting critical section"; signal(rs);rs++;r2pc++;break;//exit of CS
    case 9 : cout<<"R2 at counter: "<<r2pc<<"\tThere are currently "<<rs+1<<" reader(s) outside the critical section\n"; r2pc++;break;
    case 10 : cout<<"R2 at counter: "<<r2pc<<"\tThere are currently "<<wsem+1<<" writer(s) outside the critical section\n"; r2pc++;break;
    case 11 : cout<<"R2 at counter: "<<r2pc<<"\tEnd point of reader2\n";fr2=1;r2pc=0;break;
  }
}
void reader3(){
  switch(r3pc){
    case 0 : cout<<"R3 at counter: "<<r3pc<<"\tThis is reader3 starting point\n"; r3pc++;break;
    case 1 : cout<<"R3 at counter: "<<r3pc<<"\tThere are currently "<<rs+1<<" reader(s) outside the critical section\n"; r3pc++;break;
    case 2 : cout<<"R3 at counter: "<<r3pc<<"\tThere are currently "<<wsem+1<<" writer(s) outside the critical section\n"; r3pc++;break;
    case 3 : cout<<"R3 at counter: "<<r3pc<<"\tReader3 will now attempt to enter critical section";
                    if(rs<=0){wait(rs);r3pc--;}
                    else if(wsem<=0){wait(rs);r3pc--;}//since wait() is atomic, they're all in one case
                    else{wait(rs);rs--;}
                    r3pc++;break;//semaphore gate
    case 4 : cout<<"R3 at counter: "<<r3pc<<"\tReader3 reading buffer, which is: "<<cs<<"\n";r3pc++;break;
    case 5 : cout<<"R3 at counter: "<<r3pc<<"\tReader3 delaying the critical section to make sure the semaphore gate works\n";
                    l=0; r3pc++;break;
    case 6 : cout<<"R3 at counter: "<<r3pc;
                    if(l<=15){
                        cout<<"\tReader3 delaying the critical section to make sure the semaphore gate works\n";r3pc++;}
                    else {cout<<"\tReader3 delaying the critical section to make sure the semaphore gate works\n";r3pc = 8;} break;
    case 7 : cout<<"R3 at counter: "<<r3pc<<"\tReader3 delaying the critical section to make sure the semaphore gate works\n";
                    l++;r3pc--;break;
    case 8 : cout<<"R3 at counter: "<<r3pc<<"\tReader3 exiting critical section"; signal(rs);rs++;r3pc++;break;//exit of CS
    case 9 : cout<<"R3 at counter: "<<r3pc<<"\tThere are currently "<<rs+1<<" reader(s) outside the critical section\n"; r3pc++;break;
    case 10 : cout<<"R3 at counter: "<<r3pc<<"\tThere are currently "<<wsem+1<<" writer(s) outside the critical section\n"; r3pc++;break;
    case 11 : cout<<"R3 at counter: "<<r3pc<<"\tEnd point of reader3\n";fr3=1;r3pc=0;break;
  }
}
void writer1(){
    switch(w1pc){
        case 0 : cout<<"W1 at counter: "<<w1pc<<"\tThis is writer1 starting point\n"; w1pc++;break;
        case 1 : cout<<"W1 at counter: "<<w1pc<<"\tThere are currently "<<rs+1
                    <<" reader(s) outside the critical section\n"; w1pc++;break;
        case 2 : cout<<"W1 at counter: "<<w1pc<<"\tThere are currently "<<wsem+1
                    <<" writer(s) outside the critical section\n"; w1pc++;break;
        case 3 : cout<<"W1 at counter: "<<w1pc<<"\tWriter1 will now attempt to enter critical section";
                        if(rs<=1){wait(wsem);w1pc--;}
                        else if(wsem<=0){wait(wsem);w1pc--;}//since wait() is atomic, they're all in one case
                        else{wait(wsem);wsem--;}
                        w1pc++;break;//semaphore gate
        case 4 : cout<<"W1 at counter: "<<w1pc<<"\tBuffer was originally: 50\tWriter1 altered buffer and it's now: " <<--cs<<"\n";
                        w1pc++;break;
        case 5 : cout<<"W1 at counter: "<<w1pc<<"\tWriter1 delaying the critical section to make sure the semaphore gate works\n";
                        m=0; w1pc++;break;
        case 6 : cout<<"W1 at counter: "<<w1pc;
                        if(m<=15){
                            cout<<"\tWriter1 delaying the critical section to make sure the semaphore gate works\n";w1pc++;}
                        else {cout<<"\tWriter1 delaying the critical section to make sure the semaphore gate works\n";w1pc = 8;} break;
        case 7 : cout<<"W1 at counter: "<<w1pc<<"\tWriter1 delaying the critical section to make sure the semaphore gate works\n";
                        m++;w1pc--;break;
        case 8 : cout<<"W1 at counter: "<<w1pc<<"\tWriter1 exiting critical section";
                    signal(wsem);wsem++;w1pc++;break;//exit of CS
        case 9 : cout<<"W1 at counter: "<<w1pc<<"\tThere are currently "<<rs+1
                    <<" reader(s) outside the critical section\n"; w1pc++;break;
        case 10 : cout<<"W1 at counter: "<<w1pc<<"\tThere are currently "<<wsem+1
                    <<" writer(s) outside the critical section\n"; w1pc++;break;
        case 11 : cout<<"W1 at counter: "<<w1pc<<"\tEnd point of writer1\n";fw1=1;w1pc=0;break;
    }
}
void writer2(){
    switch(w2pc){
        case 0 : cout<<"W2 at counter: "<<w2pc<<"\tThis is writer2 starting point\n"; w2pc++;break;
        case 1 : cout<<"W2 at counter: "<<w2pc<<"\tThere are currently "<<rs+1
                    <<" reader(s) outside the critical section\n"; w2pc++;break;
        case 2 : cout<<"W2 at counter: "<<w2pc<<"\tThere are currently "<<wsem+1
                    <<" writer(s) outside the critical section\n"; w2pc++;break;
        case 3 : cout<<"W2 at counter: "<<w2pc<<"\tWriter2 will now attempt to enter critical section";
                        if(rs<=1){wait(wsem);w2pc--;}
                        else if(wsem<=0){wait(wsem);w2pc--;}  //since wait() is atomic, they're all in one case
                        else{wait(wsem);wsem--;}
                        w2pc++;break;//semaphore gate
        case 4 : cout<<"W2 at counter: "<<w2pc<<"\tBuffer was originally: 50\tWriter2 altered buffer and it's now: " <<--cs<<"\n";
                        w2pc++;break;
        case 5 : cout<<"W2 at counter: "<<w2pc<<"\tWriter2 delaying the critical section to make sure the semaphore gate works\n";
                        n=0; w2pc++;break;
        case 6 : cout<<"W2 at counter: "<<w2pc;
                        if(n<=15){
                            cout<<"\tWriter2 delaying the critical section to make sure the semaphore gate works\n";w2pc++;}
                        else {cout<<"\tWriter2 delaying the critical section to make sure the semaphore gate works\n";w2pc = 8;}
                        break;
        case 7 : cout<<"W2 at counter: "<<w2pc<<"\tWriter2 delaying the critical section to make sure the semaphore gate works\n";
                        n++;w2pc--;break;
        case 8 : cout<<"W2 at counter: "<<w2pc<<"\tWriter2 exiting critical section";
                    signal(wsem);wsem++;w2pc++;break;//exit of CS
        case 9 : cout<<"W2 at counter: "<<w2pc<<"\tThere are currently "<<rs+1
                    <<" reader(s) outside the critical section\n"; w2pc++;break;
        case 10 : cout<<"W2 at counter: "<<w2pc<<"\tThere are currently "<<wsem+1
                    <<" writer(s) outside the critical section\n"; w2pc++;break;
        case 11 : cout<<"W2 at counter: "<<w2pc<<"\tEnd point of writer2\n";fw2=1;w2pc=0;break;
        }
    }
void panic(int x,int y){
    if(x<0){cout<<"\nPANIC!!!!!CRITICAL SECTION COMPROMISED!!!!!!\n";}
    //more than 2 readers in the critical section, panic
    else if(y<0){cout<<"\nPANIC!!!!!CRITICAL SECTION COMPROMISED!!!!!!\n";}
    //more than 1 writer in the critical section, panic
    else if(y==0&&x<2){cout<<"\nPANIC!!!!!CRITICAL SECTION COMPROMISED!!!!!!\n";}
    //writer and reader in critical section, panic
}
void wait(int s){ //see case 1 of the functions for the actual wait() function
  if (rs==0) {
    cout<<"\tTwo readers already in critical section please wait\n"; panic(rs,wsem);
    }//panic function is incorporated within the wait function for convenience
  else if (wsem==0){
    cout<<"\tA writer already in critical section please wait\n"; panic(rs,wsem);
  }
  else if (rs==1){
    cout<<"\tOne reader in critical section, writer please wait, reader may pass\n"; panic(rs,wsem);
  }
  else {
        cout<<"\tSemaphore gate passed, semaphore decrementing\n"; panic(rs,wsem);
  }
}
void signal(int s){ //Actual increment occurs at case 8
  cout<<"\tSemaphore incrementing\n";
}
bool flag(){
  if(fr1+fr2+fr3+fw1+fw2==5){cout<<"\nAll readers and writers have finished at least once\n"; return true;}
  else return false;
}
